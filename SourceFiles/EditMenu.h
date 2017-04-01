#ifndef IMAGEVIEWER_EDITMENU_H
#define IMAGEVIEWER_EDITMENU_H

#include <QMenu>

class CopyMenu;
class MoveMenu;
class SortingMenu;

class EditMenu : public QMenu {
public:
  EditMenu();
  ~EditMenu();

  void reload();

private:
  void setup();
  void addSettingsAction();

  void settings();

private:
  CopyMenu *mCopyMenu = nullptr;
  MoveMenu *mMoveMenu = nullptr;
  QAction *mSettingsAction = nullptr;
  SortingMenu *mSortingMenu = nullptr;
};

#endif  // IMAGEVIEWER_EDITMENU_H
