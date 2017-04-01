#ifndef IMAGEVIEWER_VIEWMENU_H
#define IMAGEVIEWER_VIEWMENU_H

#include <QMenu>

class RotationMenu;
class ZoomMenu;

class ViewMenu : public QMenu {
public:
  ViewMenu();
  ~ViewMenu();

  void reload();

private:
  void setup();
  void addFullscreenAction();
  void addShowMenuBarAction();
  void addShowStatusBarAction();
  void addShowToolBarAction();

  void fullscreen();
  void toggleMenuBar();
  void toggleStatusBar();
  void toggleToolBar();

private:
  QAction *mFullScreenAction = nullptr;
  RotationMenu *mRotationMenu = nullptr;
  QAction *mShowMenuBarAction = nullptr;
  QAction *mShowStatusBarAction = nullptr;
  QAction *mShowToolBarAction = nullptr;
  ZoomMenu *mZoomMenu = nullptr;
};

#endif  // IMAGEVIEWER_VIEWMENU_H
