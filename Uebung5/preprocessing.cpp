#include <omp.h>
#include "preprocessing.h"

bool ascending(int i, int j) { return i > j; }
bool descending(int i, int j) { return i < j; }
QImage preprocessing::applyConvolution(QImage img, matrix<int> m, float div){
	QImage newimg(img.width(), img.height(), QImage::Format::Format_RGB888);

#pragma omp parallel for
	for (int y = 0; y < img.height(); y++)
		for (int x = 0; x < img.width(); x++){
			float v = 0;
			for (int yf = -1; yf <= 1; yf++)
				for (int xf = -1; xf <= 1; xf++){
					int posx = std::min(std::max(x + xf, 0), img.width() - 1);
					int posy = std::min(std::max(y + yf, 0), img.height() - 1);
					v += m(xf + 1, yf + 1) * qRed(img.pixel(posx, posy));
				}
			v *= div;
			//v += 128;
			v = std::min(std::max(int(v), 0), 255);
			newimg.setPixel(x, y, qRgb(v, v, v));
		}
	return newimg;
}

QImage preprocessing::applyMorphologicOperation(QImage img, PreproType type, bool binary, int size, matrix<int> S){
	QImage newimg(img.width(), img.height(), QImage::Format::Format_RGB888);
	int half_size = size / 2;

#pragma omp parallel for
	for (int y = 0; y < img.height(); y++){
		std::vector<int> list;
		if (type == PreproType::MEDIAN)
			for (int i = 0; i < size*size; i++)
				list.push_back(0);

		for (int x = 0; x < img.width(); x++){
			int v_min = 255;
			int v_max = 0;

			for (int yf = -half_size; yf <= half_size; yf++)
			for (int xf = -half_size; xf <= half_size; xf++){
				int posx = std::min(std::max(x + xf, 0), img.width() - 1);
				int posy = std::min(std::max(y + yf, 0), img.height() - 1);

				if (type == PreproType::MEDIAN)
					list[(yf + half_size)*size + xf + half_size] = qRed(img.pixel(posx, posy)); // add to list
				int value = qRed(img.pixel(posx, posy)) - S((yf + half_size), xf + half_size);

				v_min = std::min(v_min, value); // Minimum
				v_max = std::max(v_max, value); // Maximum
			}

			
			if (type == PreproType::EROSION)
				newimg.setPixel(x, y, qRgb(v_min, v_min, v_min));

			else if (type == PreproType::DILATATION)
				newimg.setPixel(x, y, qRgb(v_max, v_max, v_max));

			else if (type == PreproType::MEDIAN){
				std::sort(list.begin(), list.end(), ascending);
				float v = list[((size*size) - 1) / 2];
				newimg.setPixel(x, y, qRgb(v, v, v));
			}
			else if (type == PreproType::KANTENFILTER)
				newimg.setPixel(x, y, qRgb(v_max - v_min, v_max - v_min, v_max - v_min));	
		}
	}
	return newimg;
}