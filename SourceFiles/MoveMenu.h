#ifndef IMAGEVIEWER_MOVEMENU_H
#define IMAGEVIEWER_MOVEMENU_H

#include <QMenu>

class MoveMenu : public QMenu {
public:
  MoveMenu();
  ~MoveMenu();

private:
  void setup();
  void addMoveToFolder1Action();
  void addMoveToFolder2Action();
  void addMoveToFolder3Action();
  void addMoveToFolder4Action();
  void addMoveToFolder5Action();

  void moveToFolder1();
  void moveToFolder2();
  void moveToFolder3();
  void moveToFolder4();
  void moveToFolder5();

private:
  QAction *mMoveToFolder1Action = nullptr;
  QAction *mMoveToFolder2Action = nullptr;
  QAction *mMoveToFolder3Action = nullptr;
  QAction *mMoveToFolder4Action = nullptr;
  QAction *mMoveToFolder5Action = nullptr;
};

#endif  // IMAGEVIEWER_MOVEMENU_H
