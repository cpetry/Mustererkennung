
#include "pictureView.h"

#include <QtWidgets/QGraphicsItem>
#include <QtGui\QMouseEvent>

pictureView::pictureView(){
	is_draging = false;
	scale_factor = 1;
	scene_is_empty = true;
	pictureItem = NULL;
	last_pos_x = 0;
	last_pos_y = 0;
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QWidget::setCursor(Qt::OpenHandCursor);
}

void pictureView::setPixmap(QPixmap pixmap){
	scene.clear();
	pictureItem = this->scene.addPixmap(pixmap);

	pictureItem->setScale(scale_factor);
	pictureItem->moveBy(pic_pos_x, pic_pos_y);
	scene_is_empty = false;
	this->setScene(&scene);
}

void pictureView::clear(){
	scene.clear();
	scene_is_empty = true;
}

void pictureView::mousePressEvent ( QMouseEvent * event ){
	QWidget::setCursor(Qt::ClosedHandCursor);

	if (event->button() == Qt::LeftButton && !scene_is_empty  && !scaled_to_fit){
		setDraging(true);
		setLastPosition(event->pos().x(), event->pos().y());
		if (otherView){
			otherView->setDraging(true);
			otherView->setLastPosition(event->pos().x(), event->pos().y());
		}
	}
}

void pictureView::mouseReleaseEvent ( QMouseEvent * event ){
	QWidget::setCursor(Qt::OpenHandCursor);

	if (event->button() == Qt::LeftButton && !scene_is_empty  && !scaled_to_fit){
		setDraging(false);
		if (otherView)
			otherView->setDraging(false);
	}
}

void pictureView::mouseMoveEvent ( QMouseEvent * event ){
	if (is_draging && !scene_is_empty  && !scaled_to_fit){
		movePictureBy(event->pos().x(), event->pos().y());
		if (otherView)
			otherView->movePictureBy(event->pos().x(), event->pos().y());
	}
}

void pictureView::wheelEvent ( QWheelEvent * event ){
	if (!scene_is_empty && !scaled_to_fit){
		scaleByAt(event->delta(), event->pos().x(), event->pos().y());
		if (otherView)
			otherView->scaleByAt(event->delta(), event->pos().x(), event->pos().y());
	}
}

void pictureView::scaleToFit(bool toFit){
	scaled_to_fit = toFit;

	if (scene_is_empty)
		return;

	QSizeF pic_size = pictureItem->boundingRect().size();
	QSize view_size = this->size();
	
	float factor;

	if (toFit){
		pictureItem->setPos(0,0);
		factor = std::min(view_size.width() / pic_size.width(), view_size.height() / pic_size.height());
	}
	else
		factor = scale_factor;

	
	pictureItem->setScale(factor);
}

void pictureView::setOtherView(pictureView *other){
	this->otherView = other;
}

void pictureView::setDraging(bool draging){
	is_draging = draging;
}

void pictureView::setLastPosition(int x, int y){
	this->last_pos_x = x;
	this->last_pos_y = y;
}

void pictureView::movePictureBy(int x, int y){
	if (pictureItem)
		pictureItem->moveBy(x - last_pos_x, y - last_pos_y);
	pic_pos_x += (x - last_pos_x);
	pic_pos_y += (y - last_pos_y);
	last_pos_x = x;
	last_pos_y = y;
}

void pictureView::scaleByAt(int delta, int x, int y){
	if (!pictureItem)
		return;

	int numDegrees = delta / 8;
	int numSteps = numDegrees / 15;

	// +20% per "wheel click"
	float scale_factor_before = scale_factor;
	scale_factor += numSteps * scale_factor * 0.2f;

	int delta_x = x - pictureItem->pos().x();
	int delta_y = y - pictureItem->pos().y();
	//pictureItem->setPos(-pictureItem->pos().x(), -pictureItem->pos().y());
	pictureItem->setPos(-pic_pos_x, -pic_pos_y);
	pictureItem->setScale(scale_factor);
	pictureItem->setPos(pic_pos_x, pic_pos_y);
	//pictureItem->setPos(x - delta_x, y - delta_y);
}