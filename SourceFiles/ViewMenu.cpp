#include "ViewMenu.h"

#include "MainWindow.h"
#include "MenuBar.h"
#include "RotationMenu.h"
#include "Settings.h"
#include "StatusBar.h"
#include "ToolBar.h"
#include "ZoomMenu.h"

extern MainWindow *gMainWindow;
extern MenuBar *gMenuBar;
extern Settings *gSettings;
extern StatusBar *gStatusBar;
extern ToolBar *gToolBar;

ViewMenu::ViewMenu() {
  setup();
}

ViewMenu::~ViewMenu() {
}

void ViewMenu::reload() {
  mFullScreenAction->setShortcut(gSettings->fullscreenKey());

  mRotationMenu->reload();
  mZoomMenu->reload();
}

void ViewMenu::setup() {
  setTitle("View");

  addShowMenuBarAction();
  addShowToolBarAction();
  addShowStatusBarAction();
  addSeparator();
  addMenu(mZoomMenu = new ZoomMenu());
  addMenu(mRotationMenu = new RotationMenu());
  addSeparator();
  addFullscreenAction();
}

void ViewMenu::addFullscreenAction() {
  mFullScreenAction = new QAction();
  mFullScreenAction->setText("Fullscreen");
  mFullScreenAction->setShortcut(gSettings->fullscreenKey());

  connect(mFullScreenAction,
          &QAction::triggered,
          this,
          &ViewMenu::fullscreen);

  addAction(mFullScreenAction);
  gMainWindow->addAction(mFullScreenAction);
}

void ViewMenu::addShowMenuBarAction() {
  mShowMenuBarAction = new QAction();
  mShowMenuBarAction->setText("Show Menu");
  mShowMenuBarAction->setShortcut(gSettings->showMenuBarKey());
  mShowMenuBarAction->setCheckable(true);
  mShowMenuBarAction->setChecked(gSettings->showMenuBar());

  connect(mShowMenuBarAction,
          &QAction::triggered,
          this,
          &ViewMenu::toggleMenuBar);

  addAction(mShowMenuBarAction);
  gMainWindow->addAction(mShowMenuBarAction);
}

void ViewMenu::addShowStatusBarAction() {
  mShowStatusBarAction = new QAction();
  mShowStatusBarAction->setText("Show Status Bar");
  mShowStatusBarAction->setShortcut(gSettings->showStatusBarKey());
  mShowStatusBarAction->setCheckable(true);
  mShowStatusBarAction->setChecked(gSettings->showStatusBar());

  connect(mShowStatusBarAction,
          &QAction::triggered,
          this,
          &ViewMenu::toggleStatusBar);

  addAction(mShowStatusBarAction);
  gMainWindow->addAction(mShowStatusBarAction);
}

void ViewMenu::addShowToolBarAction() {
  mShowToolBarAction = new QAction();
  mShowToolBarAction->setText("Show Toolbar");
  mShowToolBarAction->setShortcut(gSettings->showToolBarKey());
  mShowToolBarAction->setCheckable(true);
  mShowToolBarAction->setChecked(gSettings->showToolBar());

  connect(mShowToolBarAction,
          &QAction::triggered,
          this,
          &ViewMenu::toggleToolBar);

  addAction(mShowToolBarAction);
  gMainWindow->addAction(mShowToolBarAction);
}

void ViewMenu::fullscreen() {
  if (gMainWindow->isFullScreen()) {
    if (gSettings->showMenuBar()) {
      gMenuBar->show();
    }

    if (gSettings->showToolBar()) {
      gToolBar->show();
    }

    if (gSettings->showStatusBar()) {
      gStatusBar->show();
    }

    gMainWindow->showNormal();
  } else {
    gMenuBar->hide();
    gToolBar->hide();
    gStatusBar->hide();
    gMainWindow->showFullScreen();
  }
}

void ViewMenu::toggleMenuBar() {
  if (gMenuBar->isVisible()) {
    gMenuBar->hide();
    mShowMenuBarAction->setChecked(false);
    gSettings->setShowMenuBar(false);
  } else {
    gMenuBar->show();
    mShowMenuBarAction->setChecked(true);
    gSettings->setShowMenuBar(true);
  }
}

void ViewMenu::toggleStatusBar() {
  if (gStatusBar->isVisible()) {
    gStatusBar->hide();
    mShowStatusBarAction->setChecked(false);
    gSettings->setShowStatusBar(false);
  } else {
    gStatusBar->show();
    mShowStatusBarAction->setChecked(true);
    gSettings->setShowStatusBar(true);
  }
}

void ViewMenu::toggleToolBar() {
  if (gToolBar->isVisible()) {
    gToolBar->hide();
    mShowToolBarAction->setChecked(false);
    gSettings->setShowToolBar(false);
  } else {
    gToolBar->show();
    mShowToolBarAction->setChecked(true);
    gSettings->setShowToolBar(true);
  }
}
