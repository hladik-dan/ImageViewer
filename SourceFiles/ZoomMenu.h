#ifndef IMAGEVIEWER_ZOOMMENU_H
#define IMAGEVIEWER_ZOOMMENU_H

#include <QMenu>

class ZoomMenu : public QMenu {
public:
  ZoomMenu();
  ~ZoomMenu();

  void reload();

private:
  void setup();
  void addFitToCustimAction();
  void addFitToWindowAction();
  void addOriginalSizeAction();
  void addZoomInAction();
  void addZoomOutAction();

  void fitToCustom();
  void fitToWindow();
  void originalSize();
  void zoomIn();
  void zoomOut();

private:
  QAction *mFitToCustomAction = nullptr;
  QAction *mFitToWindowAction = nullptr;
  QAction *mOriginalSizeAction = nullptr;
  QAction *mZoomInAction = nullptr;
  QAction *mZoomOutAction = nullptr;
};

#endif  // IMAGEVIEWER_ZOOMMENU_H
