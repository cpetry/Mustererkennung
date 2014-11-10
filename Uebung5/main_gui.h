/**
 * @Copyright   2013
 * @Author  Matthias Karl, Hufnagel Stefan, Petry Christian
 * @FHWS
 */

#pragma once

#include <chrono>
#include <stack>
#include <QtWidgets/QMainWindow>
#include <boost/optional/optional.hpp>

//#include "ppmFileThread.h"
//#include "encodeThread.h"
#include "pictureView.h"

#include "../ui_main_GUI.h"

class picture;


/**
 * @brief	main entry for application.
 *			Creates a QMainWindow, connects its widgets signals with this classes slots.
 *			This GUI has mainly two pictures. 
 *			The left one is the picture that gets read.
 *			The right one is the encoded one.
 */
class main_GUI : public QMainWindow{
    //Q_OBJECT

public:
	/**
	 * @brief	Sets standard values. 
	 *			Connects its widgets signals with this classes slots.
	 */
    main_GUI();

private:
	/** ui file for the gui*/
    Ui::main_GUI ui;
	QString filename;
	/** loader for encoding the file */
    //encodeThread* encoder;
	/** QImages that get shown after transforming them (i.e. scale) */
	std::stack<QImage> img_stack;
	QImage left_image, right_image;
	/** QPixmap that get shown as labels */
	QPixmap left_pixmap, right_pixmap;
	/** Original sizes of the pictures */
	QSize left_original_size, right_original_size;
	/** GraphicsView that show pictures and handles events */
	pictureView leftView, rightView;
    /** Save the picture for encoding */
    //picture pic;

	void setfilter(int values[9], int div[2], bool readonly);

	std::chrono::system_clock::time_point encoder_begin, loader_begin;
public slots:
    /**
     * @brief	When the picture was read in, or had an error,
     *			the result is updated here.
     * @param	encodeThread::result		result of the encode process
     */
	//void slot_getEncodingResult(encodeThread::result r);

private slots:

	/**
	 * @brief	Slot for button "choose File".
	 *			A QFileDialog pops up, that lets the user choose a "*.ppm" file
	 */
	void slot_chooseFile();

	/**
	 * @brief	Slot for when the QLineEdit "Filename" has signaled that it has been changed.
	 *			Checks if the filename specified really exists 
	 *			and sets the usability of the encode button and other functionalities.
	 */
	void slot_editingFilenameFinished();

	void slot_startCamera();

	void slot_spinBoxValueChanged(int i);

	void slot_pushFilter();
	void slot_popFilter();

	void slot_loadPicture();

	/**
	 * @brief	Slot for button "Encode".
	 *			TODO!!
	 */
	void slot_startEncodingPicture();

	/**
	 * @brief	Slot for checkbox "scale" for right picture
	 *			When the checkbox changes the picture gets scaled to its full size or its original size.
	 */
	void slot_scaleImagesToggled(bool checked);


	void slot_filterChanged(const QString &text);
};