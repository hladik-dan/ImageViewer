#ifndef IMAGEVIEWER_IMAGEVIEW_H
#define IMAGEVIEWER_IMAGEVIEW_H

#include <QCoreApplication>
#include <QGraphicsView>
#include <QTimer>

class ImageView : public QGraphicsView {
  Q_OBJECT

public:
  ImageView();
  ~ImageView();

  void reload();

  void closeImage();
  void fitBigToCustom();
  void fitBigToDesktop();
  void fitBigToWindow();
  void fitToBigImage();
  void fitToCustom();
  void fitToDesktop();
  void fitToImage();
  void fitToWindow();
  void nextImage();
  void openImage(QString fileName);
  void originalSize();
  void previousImage();
  void rotateLeft();
  void rotateRight();
  void saveImage(QString fileName);
  void toggleSlideshow();
  void zoomIn();
  void zoomOut();

  void rotate(qreal angle);

  QImage image();
  qreal scale();

private:
  void setup();
  void addScene();

  void autoZoom();
  void resize();

  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void wheelEvent(QWheelEvent* event);

signals:
  void updated();
  void slideshowToggled(bool running);

private:
  const qreal ZOOM_MIN = 0.05;
  const qreal ZOOM_MAX = 50.00;

  qreal mScale = 1.00;
  qreal mAngle = 0.00;

  bool mSlideshowRunning = false;

  QImage mImage;
  QPixmap mPixmap;
  QTimer mTimer;

  QGraphicsPixmapItem *mPixmapItem = nullptr;
  QGraphicsScene *mScene = nullptr;
};

#endif  // IMAGEVIEWER_IMAGEVIEW_H
