#ifndef IMAGEVIEWER_COPYMENU_H
#define IMAGEVIEWER_COPYMENU_H

#include <QMenu>

class CopyMenu : public QMenu {
public:
  CopyMenu();
  ~CopyMenu();

private:
  void setup();
  void addCopyToFolder1Action();
  void addCopyToFolder2Action();
  void addCopyToFolder3Action();
  void addCopyToFolder4Action();
  void addCopyToFolder5Action();

  void copyToFolder1();
  void copyToFolder2();
  void copyToFolder3();
  void copyToFolder4();
  void copyToFolder5();

private:
  QAction *mCopyToFolder1Action = nullptr;
  QAction *mCopyToFolder2Action = nullptr;
  QAction *mCopyToFolder3Action = nullptr;
  QAction *mCopyToFolder4Action = nullptr;
  QAction *mCopyToFolder5Action = nullptr;
};

#endif  // IMAGEVIEWER_COPYMENU_H
