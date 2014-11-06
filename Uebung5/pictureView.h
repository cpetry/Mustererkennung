#pragma once

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>

class pictureView : public QGraphicsView
{
public:
	pictureView();
	
	void setOtherView(pictureView* pV);
	void setPixmap(QPixmap pixmap);
	void clear();
	void scaleToFit(bool toFit);

	void mousePressEvent ( QMouseEvent * event );
	void mouseReleaseEvent ( QMouseEvent * event );
	void mouseMoveEvent ( QMouseEvent * event );
	void wheelEvent ( QWheelEvent * event );

	void setDraging(bool draging);
	void setLastPosition(int x, int y);
	void movePictureBy(int x, int y);
	void scaleByAt(int delta, int x, int y);

private:
	QGraphicsScene scene;
	bool scene_is_empty;
	pictureView *otherView;

	QGraphicsItem* pictureItem;
	int pic_pos_x = 0;
	int pic_pos_y = 0;
	bool is_draging;
	bool scaled_to_fit;
	int last_pos_x, last_pos_y;
	float scale_factor;
};