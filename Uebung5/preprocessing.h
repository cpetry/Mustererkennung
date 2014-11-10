
#include <QtWidgets/QMainWindow>
#include <boost/numeric/ublas/matrix.hpp>
using namespace boost::numeric::ublas;

class preprocessing
{
public:
	enum PreproType{
		MITTELWERT,
		GAUSS,
		SOBEL_HORI,
		SOBEL_VERT,
		CUSTOM,
		EROSION,
		DILATATION,
		MEDIAN,
		KANTENFILTER,
		SCHLIESSUNG,
		OEFFNUNG
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
		else if (text_type == "CUSTOM")
			return preprocessing::CUSTOM;
		else if (text_type == "Erosion")
			return preprocessing::EROSION;
		else if (text_type == "Dilatation")
			return preprocessing::DILATATION;
		else if (text_type == "Schliessung")
			return preprocessing::SCHLIESSUNG;
		else if (text_type == "Oeffnung")
			return preprocessing::OEFFNUNG;
	}

	static QImage applyConvolution(QImage img, matrix<int> m, float div);

	static QImage applyMorphologicOperation(QImage img, PreproType type, int size);
};