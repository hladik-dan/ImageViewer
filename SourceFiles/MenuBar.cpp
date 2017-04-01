#include "MenuBar.h"

#include "EditMenu.h"
#include "FileMenu.h"
#include "GoMenu.h"
#include "MainWindow.h"
#include "ViewMenu.h"
#include "Settings.h"

extern MainWindow *gMainWindow;
extern Settings *gSettings;

MenuBar::MenuBar() {
  setup();
}

MenuBar::~MenuBar() {
}

void MenuBar::reload() {
  mEditMenu->reload();
  mViewMenu->reload();
  mGoMenu->reload();
}

EditMenu *MenuBar::editMenu() {
  return mEditMenu;
}

FileMenu *MenuBar::fileMenu() {
  return mFileMenu;
}

GoMenu *MenuBar::goMenu() {
  return mGoMenu;
}

ViewMenu *MenuBar::viewMenu() {
  return mViewMenu;
}

void MenuBar::setup() {
  addMenu(mFileMenu = new FileMenu());
  addMenu(mEditMenu = new EditMenu());
  addMenu(mViewMenu = new ViewMenu());
  addMenu(mGoMenu = new GoMenu());

  gMainWindow->setMenuBar(this);

  if (!gSettings->showMenuBar()) {
    hide();
  }
}
