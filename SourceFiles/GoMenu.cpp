#include "GoMenu.h"

#include "ImageView.h"
#include "MainWindow.h"
#include "Settings.h"

extern ImageView *gImageView;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

GoMenu::GoMenu() {
  setup();
}

GoMenu::~GoMenu() {
}

void GoMenu::reload() {
  mNextAction->setShortcut(gSettings->nextKey());
  mPreviousAction->setShortcut(gSettings->previousKey());
  mToggleSlideshowAction->setShortcut(gSettings->toggleSlideshowKey());
}

void GoMenu::setup() {
  setTitle("Go");

  addPreviousAction();
  addNextAction();
  addSeparator();
  addToggleSlideshowAction();
}

void GoMenu::addNextAction() {
  mNextAction = new QAction();
  mNextAction->setText("Next");
  mNextAction->setShortcut(gSettings->nextKey());

  connect(mNextAction,
          &QAction::triggered,
          this,
          &GoMenu::next);

  addAction(mNextAction);
  gMainWindow->addAction(mNextAction);
}

void GoMenu::addPreviousAction() {
  mPreviousAction = new QAction();
  mPreviousAction->setText("Previous");
  mPreviousAction->setShortcut(gSettings->previousKey());

  connect(mPreviousAction,
          &QAction::triggered,
          this,
          &GoMenu::previous);

  addAction(mPreviousAction);
  gMainWindow->addAction(mPreviousAction);
}

void GoMenu::addToggleSlideshowAction() {
  mToggleSlideshowAction = new QAction();
  mToggleSlideshowAction->setText("Play/Pause Slideshow");
  mToggleSlideshowAction->setShortcut(gSettings->toggleSlideshowKey());

  connect(mToggleSlideshowAction,
          &QAction::triggered,
          this,
          &GoMenu::toggleSlideshow);

  addAction(mToggleSlideshowAction);
  gMainWindow->addAction(mToggleSlideshowAction);
}

void GoMenu::next() {
  gImageView->nextImage();
}

void GoMenu::previous() {
  gImageView->previousImage();
}

void GoMenu::toggleSlideshow() {
  gImageView->toggleSlideshow();
}
