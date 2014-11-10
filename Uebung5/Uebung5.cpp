// Uebung5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include <string>

#include <QtWidgets/QApplication>
#include <QtCore/QDir>

#include "main_gui.h"


int main(int argc, char** argv){
	QApplication qt_app(argc, argv);

	QString path = QDir::current().absolutePath() + "/AppIcon.png";

	if (!QFile::exists(path)){
		QDir res = QDir::current();
		res.cdUp();
		res.cdUp();
		path = res.absolutePath() + "/_resources/AppIcon.png";
	}
	std::string s = path.toStdString();

	qt_app.setWindowIcon(QIcon(path));

	qt_app.addLibraryPath("Qt5"); // to load jpeg files (imageformats)

	main_GUI window;
	window.show();

	qt_app.exec();

	return 0;
}
