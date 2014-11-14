/**
* @Copyright   2014
* @Author  Petry Christian
* @FHWS
*/

#include <omp.h>
#include "preprocessing.h"

bool ascending(int i, int j) { return i > j; }
bool descending(int i, int j) { return i < j; }
QImage preprocessing::applyConvolution(QImage img, matrix<int> m, int mid_value, float div){
	QImage newimg(img.width(), img.height(), QImage::Format::Format_RGB888);

#pragma omp parallel for
	for (int y = 0; y < img.height(); y++)
		for (int x = 0; x < img.width(); x++){
			float v = 0;

			// calc sum of values inside window
			for (int yf = -1; yf <= 1; yf++)
				for (int xf = -1; xf <= 1; xf++){
					int posx = std::min(std::max(x + xf, 0), img.width() - 1);
					int posy = std::min(std::max(y + yf, 0), img.height() - 1);
					v += m(xf + 1, yf + 1) * qRed(img.pixel(posx, posy));
				}

			v *= div;
			v = std::min(std::max(int(v + mid_value), 0), 255); // clamp (0, 255)
			newimg.setPixel(x, y, qRgb(v, v, v));
		}
	return newimg;
}

QImage preprocessing::applyMorphologicOperation(QImage img, PreproType type, bool binary_img, int size, matrix<int> S){
	QImage newimg(img.width(), img.height(), QImage::Format::Format_RGB888);
	int half_size = size / 2;

#pragma omp parallel for
	for (int y = 0; y < img.height(); y++){
		std::vector<int> list;

		// creating a list for the values of the window.
		// only needed when calculating median
		if (type == PreproType::MEDIAN)
			for (int i = 0; i < size*size; i++)
				list.push_back(0);

		for (int x = 0; x < img.width(); x++){
			int v_min = 255;
			int v_max = 0;

			// getting min max and if median a list inside the window of dimension size^2
			for (int yf = -half_size; yf <= half_size; yf++)
			for (int xf = -half_size; xf <= half_size; xf++){
				int posx = std::min(std::max(x + xf, 0), img.width() - 1);  // clamp (0, width-1)
				int posy = std::min(std::max(y + yf, 0), img.height() - 1); // clamp (0, height-1)

				if (type == PreproType::MEDIAN){
					int pos_in_array = (yf + half_size)*size + xf + half_size; // y*width + x
					list[pos_in_array] = qRed(img.pixel(posx, posy)); // add pixel to list
				}
				int value = qRed(img.pixel(posx, posy)) - S((yf + half_size), xf + half_size); // reduce by S at pos

				v_min = std::min(v_min, value); // Minimum
				v_max = std::max(v_max, value); // Maximum
			}

			// Binary image: swap min & max, does make sense for "binary images"
			// 0 = white, 1 = black  =>  8Bit: 255 = white, 0 = black
			if (binary_img)
				std::swap(v_min, v_max);

			// erosion: r_1 = smallest value
			if (type == PreproType::EROSION)
				newimg.setPixel(x, y, qRgb(v_min, v_min, v_min));

			// dilatation: r_max = highest value
			else if (type == PreproType::DILATATION)
				newimg.setPixel(x, y, qRgb(v_max, v_max, v_max));

			// median: r_mid = middle value
			else if (type == PreproType::MEDIAN){
				std::sort(list.begin(), list.end(), ascending);
				int v = list[((size*size) - 1) / 2];
				newimg.setPixel(x, y, qRgb(v, v, v));
			}
			// edge detection: r_max - r_1 = difference of max and min
			else if (type == PreproType::KANTENFILTER){
				int v = std::abs(v_max - v_min);
				newimg.setPixel(x, y, qRgb(v, v, v));
			}
				
		}
	}
	return newimg;
}