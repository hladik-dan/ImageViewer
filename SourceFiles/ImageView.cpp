#include "ImageView.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsPixmapItem>
#include <QLayout>
#include <QMouseEvent>
#include <QtMath>

#include "File.h"
#include "MainWindow.h"
#include "MenuBar.h"
#include "Settings.h"
#include "StatusBar.h"
#include "ToolBar.h"

extern File *gFile;
extern MainWindow *gMainWindow;
extern MenuBar *gMenuBar;
extern Settings *gSettings;
extern StatusBar *gStatusBar;
extern ToolBar *gToolBar;

ImageView::ImageView() {
  setup();
}

ImageView::~ImageView() {
}

void ImageView::reload() {
  if (!mSlideshowRunning) {
    setBackgroundBrush(QBrush(gSettings->backgroundColor()));
  } else {
    setBackgroundBrush(QBrush(gSettings->backgroundColorForSlideshow()));
  }
}

void ImageView::closeImage() {
  mImage = QImage();
  mPixmapItem->setPixmap(QPixmap());

  gFile->setCurrentFile(QString());

  emit updated();
}

void ImageView::fitBigToCustom() {
  if (mImage.rect().width() <= gSettings->fitBigToCustomWidth()
      && mImage.rect().height() <= gSettings->fitBigToCustomHeight()) {
    return;
  }

  if (mImage.width() > mImage.height()) {
    mScale = (qreal) gSettings->fitBigToCustomWidth() / (qreal) mImage.width();
  } else {
    mScale =
        (qreal) gSettings->fitBigToCustomHeight() / (qreal) mImage.height();
  }

  QTransform transformation = transform().fromScale(mScale, mScale);
  transformation.rotate(mAngle);

  setTransform(transformation);

  emit updated();
}

void ImageView::fitBigToDesktop() {
  QRect availableGeometry = QApplication::desktop()->availableGeometry();
  int frameSize = gMainWindow->frameGeometry().height()
      - gMainWindow->geometry().height();
  availableGeometry.setHeight(availableGeometry.height() - frameSize);

  if (mImage.width() <= availableGeometry.width()
      && mImage.height() <= availableGeometry.height()) {
    return;
  }

  fitToDesktop();
}

void ImageView::fitBigToWindow() {
  if (mImage.rect().width() <= rect().width()
      && mImage.rect().height() <= rect().height()) {
    return;
  }

  fitToWindow();
}

void ImageView::fitToBigImage() {
  if (mImage.rect().width() <= rect().width()
      && mImage.rect().height() <= rect().height()) {
    return;
  }

  fitToImage();
}

void ImageView::fitToCustom() {
  if (mImage.width() > mImage.height()) {
    mScale = (qreal) gSettings->fitToCustomWidth() / (qreal) mImage.width();
  } else {
    mScale = (qreal) gSettings->fitToCustomHeight() / (qreal) mImage.height();
  }

  QTransform transformation = transform().fromScale(mScale, mScale);
  transformation.rotate(mAngle);

  setTransform(transformation);

  emit updated();
}

void ImageView::fitToDesktop() {
  QRect availableGeometry = QApplication::desktop()->availableGeometry();
  int frameSize = gMainWindow->frameGeometry().height()
      - gMainWindow->geometry().height();

  availableGeometry.setHeight(availableGeometry.height() - frameSize);

  if (gMenuBar->isVisible()) {
    availableGeometry.setHeight(availableGeometry.height() - gMenuBar->height());
  }
  if (gToolBar->isVisible()) {
    availableGeometry.setHeight(availableGeometry.height() - gToolBar->height());
  }
  if (gStatusBar->isVisible()) {
    availableGeometry.setHeight(availableGeometry.height() - gStatusBar->height());
  }

  if (mImage.width() > availableGeometry.width()) {
    mScale = (qreal) availableGeometry.width() / (qreal) mImage.width();
  } else {
    mScale = (qreal) availableGeometry.height() / (qreal) mImage.height();
  }

  QTransform transformation = transform().fromScale(mScale, mScale);
  transformation.rotate(mAngle);

  setTransform(transformation);

  emit updated();
}

void ImageView::fitToImage() {
  if (gMainWindow->isMaximized()) {
    gMainWindow->showNormal();
  }

  int w = qRound(mImage.width() * mScale);
  int h = qRound(mImage.height() * mScale);

  if (gMenuBar->isVisible()) {
    h += gMenuBar->height();
  }
  if (gToolBar->isVisible()) {
    h += gToolBar->height();
  }
  if (gStatusBar->isVisible()) {
    h += gStatusBar->height();
  }

  gMainWindow->resize(w, h);
}

void ImageView::fitToWindow() {
  fitInView(mScene->sceneRect(), Qt::KeepAspectRatio);

  mScale = (transform().m11()) ? transform().m11() : transform().m21();

  emit updated();
}

void ImageView::nextImage() {
  if (mSlideshowRunning && (gFile->index() + 1) == gFile->size()) {
    toggleSlideshow();
  }

  openImage(gFile->nextFile().absoluteFilePath());
}

void ImageView::openImage(QString fileName) {
  if (!mImage.load(fileName)) {
    return;
  }

  if (!mPixmap.convertFromImage(mImage)) {
    return;
  }

  gFile->setCurrentFile(fileName);

  if (gSettings->showFileNameInTitleBar()) {
    gMainWindow->setWindowTitle(gFile->currentFile().fileName()
                                    + " - ImageViewer");
  }

  mPixmapItem->setPixmap(mPixmap);
  mScene->setSceneRect(QRect(QPoint(0, 0), mImage.size()));

  originalSize();
  autoZoom();
  resize();

  emit updated();
}

void ImageView::originalSize() {
  mScale = 1.00;

  QTransform transformation = transform().fromScale(mScale, mScale);
  transformation.rotate(mAngle);

  setTransform(transformation);

  emit updated();
}

void ImageView::previousImage() {
  openImage(gFile->previousFile().absoluteFilePath());
}

void ImageView::rotateLeft() {
  rotate(-90.0);
}

void ImageView::rotateRight() {
  rotate(90.0);
}

void ImageView::saveImage(QString fileName) {
  mImage.save(fileName);
}

void ImageView::toggleSlideshow() {
  mSlideshowRunning = !mSlideshowRunning;

  emit slideshowToggled(mSlideshowRunning);

  if (!mSlideshowRunning) {
    setBackgroundBrush(QBrush(gSettings->backgroundColor()));
    mTimer.stop();
    mTimer.disconnect();
    return;
  }

  setBackgroundBrush(QBrush(gSettings->backgroundColorForSlideshow()));
  mTimer.start(gSettings->slideshowInterval() * 1000);

  connect(&mTimer,
          &QTimer::timeout,
          this,
          &ImageView::nextImage);
}

void ImageView::zoomIn() {
  qreal zoomStep = gSettings->zoomStep() / 100.0;
  if (mScale + zoomStep <= ZOOM_MAX) {
    mScale += zoomStep;
    mScale = qFloor(mScale / zoomStep) * zoomStep;
  }

  QTransform transformation = transform().fromScale(mScale, mScale);
  transformation.rotate(mAngle);

  setTransform(transformation);

  emit updated();
}

void ImageView::zoomOut() {
  qreal zoomStep = gSettings->zoomStep() / 100.0;
  if (mScale - zoomStep >= ZOOM_MIN) {
    mScale -= zoomStep;
    mScale = qCeil(mScale / zoomStep) * zoomStep;
  }

  QTransform transformation = transform().fromScale(mScale, mScale);
  transformation.rotate(mAngle);

  setTransform(transformation);

  emit updated();
}

void ImageView::rotate(qreal angle) {
  mAngle += angle;
  QGraphicsView::rotate(angle);

  emit updated();
}

QImage ImageView::image() {
  return mImage;
}

qreal ImageView::scale() {
  return mScale;
}

void ImageView::setup() {
  setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setBackgroundBrush(QBrush(gSettings->backgroundColor()));
  setStyleSheet("QGraphicsView { border: 0px; }");

  addScene();

  gMainWindow->setCentralWidget(this);
}

void ImageView::addScene() {
  mPixmapItem = new QGraphicsPixmapItem();

  mScene = new QGraphicsScene();
  mScene->addItem(mPixmapItem);

  setScene(mScene);
}

void ImageView::autoZoom() {
  if (!gSettings->enableAutoZoom()) {
    return;
  }

  switch (gSettings->autoZoom()) {
    case Settings::AutoZoom::FitToWindow:
      fitToWindow();
      break;
    case Settings::AutoZoom::FitBigToWindow:
      fitBigToWindow();
      break;
    case Settings::AutoZoom::FitToDesktop:
      fitToDesktop();
      break;
    case Settings::AutoZoom::FitBigToDesktop:
      fitBigToDesktop();
      break;
    case Settings::AutoZoom::FitToCustom:
      fitToCustom();
      break;
    case Settings::AutoZoom::FitBigToCustom:
      fitBigToCustom();
      break;
  }
}

void ImageView::resize() {
  switch (gSettings->resize()) {
    case Settings::Resize::KeepSize:
      break;
    case Settings::Resize::FitToImage:
      fitToImage();
      break;
    case Settings::Resize::FitToBigImage:
      fitToBigImage();
      break;
  }
}

void ImageView::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    setDragMode(QGraphicsView::ScrollHandDrag);
  }

  QGraphicsView::mousePressEvent(event);
}

void ImageView::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    setDragMode(QGraphicsView::NoDrag);
  }

  QGraphicsView::mouseReleaseEvent(event);
}

void ImageView::wheelEvent(QWheelEvent *event) {
  if (event->delta() > 0) {
    zoomIn();
  } else {
    zoomOut();
  }
}
