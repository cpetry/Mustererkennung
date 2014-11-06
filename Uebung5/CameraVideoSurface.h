#include <QtMultimedia/QAbstractVideoSurface>

class CameraVideoSurface : public QAbstractVideoSurface{
	//Q_OBJECT
public:
	CameraVideoSurface(QObject * parent = NULL) : QAbstractVideoSurface(parent)
	{}

	QList<QVideoFrame::PixelFormat>
		supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const{
				return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB24; // here return whatever formats you will handle
		}

	bool present(const QVideoFrame& frame){

		/*
		if (frame.isValid()) {
			QVideoFrame cloneFrame(frame);
			cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
			const QImage img(cloneFrame.bits(),
				cloneFrame.width(),
				cloneFrame.height(),
				QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));


			// do something with the image ...

			cloneFrame.unmap();
			return true;
		}
		return false;
		*/
		return false;
	}

};