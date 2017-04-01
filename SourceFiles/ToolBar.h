#ifndef IMAGEVIEWER_TOOLBAR_H
#define IMAGEVIEWER_TOOLBAR_H

#include <QToolBar>

class ToolBar : public QToolBar {
public:
  ToolBar();
  ~ToolBar();

private:
  void setup();
  void addFitToWindowAction();
  void addNextAction();
  void addOpenAction();
  void addOriginalSizeAction();
  void addPreviousAction();
  void addSpacer();
  void addToggleSlideshowAction();
  void addZoomInAction();
  void addZoomOutAction();

  void fitToWindow();
  void next();
  void open();
  void originalSize();
  void previous();
  void toggleSlideshow();
  void toggleSlideshow(bool running);
  void zoomIn();
  void zoomOut();

private:
  QAction *mFitToWindowAction = nullptr;
  QAction *mNextAction = nullptr;
  QAction *mOpenAction = nullptr;
  QAction *mOriginalSizeAction = nullptr;
  QAction *mPrevousAction = nullptr;
  QAction *mToggleSlideshowAction = nullptr;
  QAction *mZoomInAction = nullptr;
  QAction *mZoomOutAction = nullptr;
};

#endif  // IMAGEVIEWER_TOOLBAR_H
