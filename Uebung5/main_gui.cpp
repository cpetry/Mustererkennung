/**
 * @Copyright   2013
 * @Author  Matthias Karl, Hufnagel Stefan, Petry Christian
 * @FHWS
 */

#include "main_gui.h"
#include <QtGui/QWindow>
#include <QtWidgets/QFileDialog>

//#include "ppmFileThread.h"
#include "preprocessing.h"
#include <chrono>
#include <QtGui\QImageReader>
#include <QtCore\QDebug>

main_GUI::main_GUI(){
	// Loads the ui_GUI.ui file and set it to the UI
	ui.setupUi(this);

	// Sets the window title
	this->setWindowTitle("Mustererkennung");

	//At first disable Load and Encode button
	this->ui.btn_loadPPM->setDisabled(true);
	this->ui.btn_apply->setDisabled(true);

	
	leftView.setParent(ui.leftPicture);
	leftView.setOtherView(&rightView);
	leftView.setSizePolicy(QSizePolicy::QSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding));
	//leftView.resize(ui.leftPicture->size());
	leftView.show();

	//leftView.resize(ui.leftPicture->size());
	
	
	
	//leftView.resize(ui.leftPicture->size());
	

	rightView.setParent(ui.rightPicture);
	rightView.setOtherView(&leftView);
	leftView.setSizePolicy(QSizePolicy::QSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding));
	//rightView.resize(ui.rightPicture->size());
    rightView.show();
		
	this->ui.cb_filter->addItem("Mittelwert");
	this->ui.cb_filter->addItem("Gauss");
	this->ui.cb_filter->addItem("Sobel hori");
	this->ui.cb_filter->addItem("Sobel vert");
	this->ui.cb_filter->addItem("CUSTOM"); 
	this->ui.cb_filter->addItem("Erosion");
	this->ui.cb_filter->addItem("Dilatation");
	this->ui.cb_filter->addItem("Median");
	this->ui.cb_filter->addItem("Kantenfilter");
	this->ui.cb_filter->addItem("Schliessung");
	this->ui.cb_filter->addItem("Oeffnung");
	
	
	slot_filterChanged("Mittelwert");

	connect(ui.btn_choose, &QPushButton::clicked, this, &main_GUI::slot_chooseFile);
	connect(ui.btn_push, &QPushButton::clicked, this, &main_GUI::slot_pushFilter);
	connect(ui.btn_pop, &QPushButton::clicked, this, &main_GUI::slot_popFilter);
	connect(ui.lineEdit_filename, &QLineEdit::editingFinished, this, &main_GUI::slot_editingFilenameFinished);
	connect(ui.sb_morph_size, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &main_GUI::slot_spinBoxValueChanged);
	connect(ui.cb_filter, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &main_GUI::slot_filterChanged);
	connect(ui.btn_loadPPM, &QPushButton::clicked, this, &main_GUI::slot_loadPicture);
	connect(ui.btn_apply, &QPushButton::clicked, this, &main_GUI::slot_startEncodingPicture);

	QDir solution = QDir::current();
	this->ui.lineEdit_filename->setText(QString(solution.absolutePath() + "/_resources/lena.png"));
	slot_editingFilenameFinished();

	this->ui.btn_pop->setEnabled(false);
	this->ui.btn_push->setEnabled(false);
}

void main_GUI::slot_chooseFile(){
	QDir res = QDir::current().absolutePath() + "/_resources";
	if (!res.exists()){
		res = QDir::current();
		res.cdUp();
		res.cdUp();
		res = res.absolutePath() + "/_resources";
	}
	QString path = res.absolutePath();

	QString file = QFileDialog::getOpenFileName(this,
		tr("Open Image"), 
		path,
		tr("Image Files"),
		(QString*)0, QFileDialog::ReadOnly);

	if (!file.isEmpty()){
		ui.lineEdit_filename->setText(file);
		slot_editingFilenameFinished();
	}
}

void main_GUI::slot_editingFilenameFinished(){
	this->filename = ui.lineEdit_filename->text();
	// check if file even exists
	if (QFile::exists(this->filename)){
		// clear Message on StatusBar
		this->ui.btn_loadPPM->setEnabled(true);
		ui.statusBar->showMessage("");
	}
	else if(!this->filename.isEmpty())
	{
		this->ui.btn_loadPPM->setDisabled(true);
		ui.statusBar->showMessage("File not found!");
	}
}

void main_GUI::slot_startCamera(){
	//QCamera* camera = new QCamera(this);
	
	//QAbstractVideoSurface* mySurface = new CameraVideoSurface();
	//camera->setViewfinder(mySurface);
	//camera->start(); // Viewfinder frames start flowing
	
	//QCameraViewfinder* viewfinder = new QCameraViewfinder;
	//camera->setViewfinder(viewfinder);
	//viewfinder->show();

	/*
	QCameraImageCapture* imageCapture = new QCameraImageCapture(camera);

	camera->setCaptureMode(QCamera::CaptureStillImage);
	camera->start(); // Viewfinder frames start flowing
	
	//on shutter button pressed
	imageCapture->capture();

	//on shutter button released
	camera->unlock();
	*/
}

void main_GUI::slot_loadPicture(){
	
	this->left_image.load(ui.lineEdit_filename->text());
	this->left_pixmap = QPixmap::fromImage(left_image);
	this->leftView.setPixmap(this->left_pixmap);
	this->leftView.show();
	this->leftView.scaleToFit(false);
	leftView.resize(ui.leftPicture->size());
	
	while (!img_stack.empty())
		img_stack.pop();

	img_stack.push(left_image);

	int filesize = QFile(ui.lineEdit_filename->text()).size();
	QString size;
	if ((filesize > 1024 * 1024))
		size = QString::number(filesize / 1024.0 / 1024.0, 'f', 2) + " MB";
	else if (filesize > 1024)
		size = QString::number(filesize / 1024.0, 'f', 2) + " KB";
	else
		size = QString::number(filesize) + " B";
	ui.lineEdit_filesize_load->setText(size);
	this->ui.lineEdit_dimensionsX->setText(QString::number(left_pixmap.width()));
	this->ui.lineEdit_dimensionsY->setText(QString::number(left_pixmap.height()));

	this->ui.btn_apply->setEnabled(true);

	this->slot_startEncodingPicture();
}

void main_GUI::slot_spinBoxValueChanged(int i){
	this->slot_startEncodingPicture();
}

void main_GUI::slot_popFilter(){
	img_stack.pop();
	if (img_stack.size() >= 1){
		left_image = img_stack.top();
		this->left_pixmap = QPixmap::fromImage(left_image);
		this->leftView.setPixmap(this->left_pixmap);
		this->leftView.show();
		this->leftView.scaleToFit(false);
		leftView.resize(ui.leftPicture->size());
		if (img_stack.size() == 1)
			this->ui.btn_pop->setDisabled(true);
	}
	slot_startEncodingPicture();
}

void main_GUI::slot_pushFilter(){
	img_stack.push(right_image);

	left_image = img_stack.top();
	this->left_pixmap = QPixmap::fromImage(left_image);
	this->leftView.setPixmap(this->left_pixmap);
	this->leftView.show();
	this->leftView.scaleToFit(false);
	leftView.resize(ui.leftPicture->size());

	this->ui.btn_pop->setEnabled(true);
}

void main_GUI::slot_startEncodingPicture(){
	ui.statusBar->showMessage("Using Filter...");
	encoder_begin = std::chrono::steady_clock::now();

	QString text_type = ui.cb_filter->currentText();
	preprocessing::PreproType type = preprocessing::getTypeEnum(text_type);

	if (type == preprocessing::MITTELWERT
		|| type == preprocessing::GAUSS
		|| type == preprocessing::SOBEL_HORI
		|| type == preprocessing::SOBEL_VERT
		|| type == preprocessing::CUSTOM){
	
		matrix<int> m(3, 3);
		m(0, 0) = this->ui.sb_11->value();
		m(0, 1) = this->ui.sb_12->value();
		m(0, 2) = this->ui.sb_13->value();
		m(1, 0) = this->ui.sb_21->value();
		m(1, 1) = this->ui.sb_22->value();
		m(1, 2) = this->ui.sb_23->value();
		m(2, 0) = this->ui.sb_31->value();
		m(2, 1) = this->ui.sb_32->value();
		m(2, 2) = this->ui.sb_33->value();
	
		float div = 1.0 * this->ui.sb_div1->value() / (1.0 * this->ui.sb_div2->value());
		this->right_image = preprocessing::applyConvolution(this->left_image, m, div);
	}
	else if (type == preprocessing::SCHLIESSUNG){
		this->right_image = preprocessing::applyMorphologicOperation(this->left_image, preprocessing::DILATATION, ui.sb_morph_size->value());
		this->right_image = preprocessing::applyMorphologicOperation(this->right_image, preprocessing::EROSION, ui.sb_morph_size->value());
	}
	else if (type == preprocessing::OEFFNUNG){
		this->right_image = preprocessing::applyMorphologicOperation(this->left_image, preprocessing::EROSION, ui.sb_morph_size->value());
		this->right_image = preprocessing::applyMorphologicOperation(this->right_image, preprocessing::DILATATION, ui.sb_morph_size->value());
	}
	else{
		this->right_image = preprocessing::applyMorphologicOperation(this->left_image, type, ui.sb_morph_size->value());
	}
	

	this->right_pixmap = QPixmap::fromImage(right_image);
	this->rightView.setPixmap(this->right_pixmap);
	this->rightView.show();
	this->rightView.scaleToFit(false);
	rightView.resize(ui.rightPicture->size());

	std::chrono::duration<double> elapsed_seconds = (std::chrono::steady_clock::now() - encoder_begin);
	ui.statusBar->showMessage("Time needed: " + QString::number(elapsed_seconds.count()*1000) + "ms");

	this->ui.btn_push->setEnabled(true);
}


void main_GUI::slot_scaleImagesToggled(bool checked){
	if (!right_image.isNull())
		this->rightView.scaleToFit(checked);
	if (!left_image.isNull())
		this->leftView.scaleToFit(checked);
}

void main_GUI::slot_filterChanged(const QString &text){
	std::string s;

	if (text == "Mittelwert"){
		int filter[9]{ 1, 1, 1, 1, 1, 1, 1, 1, 1};
		int div[2]{ 1, 9};
		bool readonly = true;
		setfilter(filter, div, readonly);
		ui.sw_options_stacked_widget->setCurrentIndex(0);
	}
	else if (text == "Gauss"){
		int filter[9]{ 1, 2, 1, 2, 4, 2, 1, 2, 1};
		int div[2]{ 1, 16};
		bool readonly = true;
		setfilter(filter, div, readonly);
		ui.sw_options_stacked_widget->setCurrentIndex(0);
	}
	else if (text == "Sobel hori"){
		int filter[9]{ 1, 0, -1, 2, 0, -2, 1, 0, -1};
		int div[2]{ 1, 1};
		bool readonly = true;
		setfilter(filter, div, readonly);
		ui.sw_options_stacked_widget->setCurrentIndex(0);
	}
	else if (text == "Sobel vert"){
		int filter[9]{ 1, 2, 1, 0, 0, 0, -1, -2, -1};
		int div[2]{ 1, 1};
		bool readonly = true;
		setfilter(filter, div, readonly);
		ui.sw_options_stacked_widget->setCurrentIndex(0);
	}
	else if (text == "Erosion"){
		ui.sw_options_stacked_widget->setCurrentIndex(1);
	}
	else if (text == "Dilatation"){
		ui.sw_options_stacked_widget->setCurrentIndex(1);
	}		
	else if (text == "Median"){
		ui.sw_options_stacked_widget->setCurrentIndex(1);
	}
	else if (text == "Kantenfilter"){
		ui.sw_options_stacked_widget->setCurrentIndex(1);
	}
	else if (text == "Schliessung"){
		ui.sw_options_stacked_widget->setCurrentIndex(1);
	}
	else if (text == "Oeffnung"){
		ui.sw_options_stacked_widget->setCurrentIndex(1);
	}
	else if (text == "CUSTOM"){
		int filter[9]{ 1, 1, 1, 1, 1, 1, 1, 1, 1};
		int div[2]{ 1, 9};
		bool readonly = false;
		setfilter(filter, div, readonly);
		ui.sw_options_stacked_widget->setCurrentIndex(0);
	}

	this->slot_startEncodingPicture();
	
	//this->ui.ComboBox_QTable->setToolTip(QString::fromStdString(s));
}

void main_GUI::setfilter(int values[], int div[], bool readonly){
	this->ui.sb_11->setValue(values[0]);
	this->ui.sb_12->setValue(values[1]);
	this->ui.sb_13->setValue(values[2]);
	this->ui.sb_21->setValue(values[3]);
	this->ui.sb_22->setValue(values[4]);
	this->ui.sb_23->setValue(values[5]);
	this->ui.sb_31->setValue(values[6]);
	this->ui.sb_32->setValue(values[7]);
	this->ui.sb_33->setValue(values[8]);
	this->ui.sb_div1->setValue(div[0]);
	this->ui.sb_div2->setValue(div[1]);

	this->ui.sb_11->setReadOnly(readonly);
	this->ui.sb_12->setReadOnly(readonly);
	this->ui.sb_13->setReadOnly(readonly);
	this->ui.sb_21->setReadOnly(readonly);
	this->ui.sb_22->setReadOnly(readonly);
	this->ui.sb_23->setReadOnly(readonly);
	this->ui.sb_31->setReadOnly(readonly);
	this->ui.sb_32->setReadOnly(readonly);
	this->ui.sb_33->setReadOnly(readonly);
	this->ui.sb_div1->setReadOnly(readonly);
	this->ui.sb_div2->setReadOnly(readonly);
}