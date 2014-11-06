
#include <QtWidgets/QMainWindow>
#include <boost/numeric/ublas/matrix.hpp>
using namespace boost::numeric::ublas;

class preprocessing
{
public:
	static QImage applyConvolution(QImage img, matrix<int> m, float div);

	static QImage applyMorphologicOperation(QImage img, QString type, int size);
};