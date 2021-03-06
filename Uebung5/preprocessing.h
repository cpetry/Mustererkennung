
#include <QtWidgets/QMainWindow>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

class preprocessing
{
public:
	enum PreproType{
		MITTELWERT,
		GAUSS,
		SOBEL_HORI,
		SOBEL_VERT,
		SOBEL,
		SCHARR_HORI,
		SCHARR_VERT,
		SCHARR,
		CUSTOM,
		EROSION,
		DILATATION,
		MEDIAN,
		KANTENFILTER,
		SCHLIESSUNG,
		OEFFNUNG,
		ERROR
	};

	static preprocessing::PreproType getTypeEnum(QString text_type){
		if (text_type == "Mittelwert")
			return preprocessing::MITTELWERT;
		else if (text_type == "Gauss")
			return preprocessing::GAUSS;
		else if (text_type == "Sobel hori")
			return preprocessing::SOBEL_HORI;
		else if (text_type == "Sobel vert")
			return preprocessing::SOBEL_VERT;
		else if (text_type == "Sobel")
			return preprocessing::SOBEL;
		else if (text_type == "Scharr hori")
			return preprocessing::SCHARR_HORI;
		else if (text_type == "Scharr vert")
			return preprocessing::SCHARR_VERT;
		else if (text_type == "Scharr")
			return preprocessing::SCHARR;
		else if (text_type == "CUSTOM")
			return preprocessing::CUSTOM;
		else if (text_type == "Erosion")
			return preprocessing::EROSION;
		else if (text_type == "Dilatation")
			return preprocessing::DILATATION;
		else if (text_type == "Median")
			return preprocessing::MEDIAN; 
		else if (text_type == "Kantenfilter")
			return preprocessing::KANTENFILTER; 
		else if (text_type == "Schliessung")
			return preprocessing::SCHLIESSUNG;
		else if (text_type == "Oeffnung")
			return preprocessing::OEFFNUNG;
		else
			return preprocessing::ERROR;
	}

	static QImage applyConvolution(QImage img, matrix<int> m, int mid_value, float div);

	static QImage applyMorphologicOperation(QImage img, PreproType type, bool binary_img, int size = 7, matrix<int> S = zero_matrix<int>(7, 7));
};