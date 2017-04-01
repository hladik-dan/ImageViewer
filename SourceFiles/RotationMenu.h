#ifndef IMAGEVIEWER_ROTATIONMENU_H
#define IMAGEVIEWER_ROTATIONMENU_H

#include <QMenu>

class RotationMenu : public QMenu {
public:
  RotationMenu();
  ~RotationMenu();

  void reload();

private:
  void setup();
  void addRotateLeftAction();
  void addRotateRightAction();

  void rotateLeft();
  void rotateRight();

private:
  QAction *mRotateLeftAction = nullptr;
  QAction *mRotateRightAction = nullptr;
};

#endif  // IMAGEVIEWER_ROTATIONMENU_H
