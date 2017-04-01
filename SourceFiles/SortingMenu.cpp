#include "SortingMenu.h"

#include "File.h"
#include "Settings.h"

extern File *gFile;
extern Settings *gSettings;

SortingMenu::SortingMenu() {
  setup();
}

SortingMenu::~SortingMenu() {
}

void SortingMenu::reload() {
}

void SortingMenu::setup() {
  setTitle("Sorting");

  addSortByFileNameAction();
  addSortByDateAction();
  addSeparator();
  addSortOrderAscendingAction();
  addSortOrderDescendingAction();
}

void SortingMenu::addSortByDateAction() {
  mSortByDateAction = new QAction();
  mSortByDateAction->setText("Sort by Date");
  mSortByDateAction->setCheckable(true);
  mSortByDateAction->setActionGroup(sortByActionGroup());

  if (gSettings->sortBy() == Settings::SortBy::Date) {
    mSortByDateAction->setChecked(true);
  }

  connect(mSortByDateAction,
          &QAction::triggered,
          this,
          &SortingMenu::sortByDate);

  addAction(mSortByDateAction);
}

void SortingMenu::addSortByFileNameAction() {
  mSortByFileNameAction = new QAction();
  mSortByFileNameAction->setText("Sort by Filename");
  mSortByFileNameAction->setCheckable(true);
  mSortByFileNameAction->setActionGroup(sortByActionGroup());

  if (gSettings->sortBy() == Settings::SortBy::FileName) {
    mSortByFileNameAction->setChecked(true);
  }

  connect(mSortByFileNameAction,
          &QAction::triggered,
          this,
          &SortingMenu::sortByFileName);

  addAction(mSortByFileNameAction);
}

void SortingMenu::addSortOrderAscendingAction() {
  mSortOrderAscendingAction = new QAction();
  mSortOrderAscendingAction->setText("Ascending");
  mSortOrderAscendingAction->setCheckable(true);
  mSortOrderAscendingAction->setActionGroup(sortOrderActionGroup());

  if (gSettings->sortOrder() == Settings::SortOrder::Ascending) {
    mSortOrderAscendingAction->setChecked(true);
  }

  connect(mSortOrderAscendingAction,
          &QAction::triggered,
          this,
          &SortingMenu::sortOrderAscending);

  addAction(mSortOrderAscendingAction);
}

void SortingMenu::addSortOrderDescendingAction() {
  mSortOrderDescendingAction = new QAction();
  mSortOrderDescendingAction->setText("Descending");
  mSortOrderDescendingAction->setCheckable(true);
  mSortOrderDescendingAction->setActionGroup(sortOrderActionGroup());

  if (gSettings->sortOrder() == Settings::SortOrder::Descending) {
    mSortOrderDescendingAction->setChecked(true);
  }

  connect(mSortOrderDescendingAction,
          &QAction::triggered,
          this,
          &SortingMenu::sortOrderDescending);

  addAction(mSortOrderDescendingAction);
}

QActionGroup *SortingMenu::sortByActionGroup() {
  if (mSortByActionGroup == nullptr) {
    mSortByActionGroup = new QActionGroup(this);
  }

  return mSortByActionGroup;
}

QActionGroup *SortingMenu::sortOrderActionGroup() {
  if (mSortOrderActionGroup == nullptr) {
    mSortOrderActionGroup = new QActionGroup(this);
  }

  return mSortOrderActionGroup;
}

void SortingMenu::sortByDate() {
  gSettings->setSortBy(Settings::SortBy::Date);
  gFile->setSorting(QDir::Time);
}

void SortingMenu::sortByFileName() {
  gSettings->setSortBy(Settings::SortBy::FileName);
  gFile->setSorting(QDir::Name);
}

void SortingMenu::sortOrderAscending() {
  gSettings->setSortOrder(Settings::SortOrder::Ascending);
  gFile->setSorting(gFile->sorting() ^ QDir::Reversed);
}

void SortingMenu::sortOrderDescending() {
  gSettings->setSortOrder(Settings::SortOrder::Descending);
  gFile->setSorting(gFile->sorting() | QDir::Reversed);
}
