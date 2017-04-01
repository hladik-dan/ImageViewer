#ifndef IMAGEVIEWER_SORTINGMENU_H
#define IMAGEVIEWER_SORTINGMENU_H

#include <QMenu>

class SortingMenu : public QMenu {
public:
  SortingMenu();
  ~SortingMenu();

  void reload();

private:
  void setup();
  void addSortByDateAction();
  void addSortByFileNameAction();
  void addSortOrderAscendingAction();
  void addSortOrderDescendingAction();

  QActionGroup *sortByActionGroup();
  QActionGroup *sortOrderActionGroup();

  void sortByDate();
  void sortByFileName();
  void sortOrderAscending();
  void sortOrderDescending();

private:

  QAction *mSortByDateAction = nullptr;
  QAction *mSortByFileNameAction = nullptr;
  QActionGroup *mSortByActionGroup = nullptr;
  QAction *mSortOrderAscendingAction = nullptr;
  QAction *mSortOrderDescendingAction = nullptr;
  QActionGroup *mSortOrderActionGroup = nullptr;
};

#endif  // IMAGEVIEWER_SORTINGMENU_H
