#include "EditMenu.h"

#include "CopyMenu.h"
#include "MoveMenu.h"
#include "SettingsDialog.h"
#include "SortingMenu.h"

extern SettingsDialog *gSettingsDialog;

EditMenu::EditMenu() {
  setup();
}

EditMenu::~EditMenu() {
}

void EditMenu::reload() {
  mSortingMenu->reload();
}

void EditMenu::setup() {
  setTitle("Edit");

  addMenu(mCopyMenu = new CopyMenu());
  addMenu(mMoveMenu = new MoveMenu());
  addSeparator();
  addMenu(mSortingMenu = new SortingMenu());
  addSeparator();
  addSettingsAction();
}

void EditMenu::addSettingsAction() {
  mSettingsAction = new QAction();
  mSettingsAction->setText("Settings");

  connect(mSettingsAction,
          &QAction::triggered,
          this,
          &EditMenu::settings);

  addAction(mSettingsAction);
}

void EditMenu::settings() {
  gSettingsDialog->exec();
}
