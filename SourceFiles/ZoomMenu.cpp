#include "ZoomMenu.h"

#include "ImageView.h"
#include "MainWindow.h"
#include "Settings.h"

extern ImageView *gImageView;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

ZoomMenu::ZoomMenu() {
  setup();
}

ZoomMenu::~ZoomMenu() {
}

void ZoomMenu::reload() {
  mFitToCustomAction->setShortcut(gSettings->fitToCustomKey());
  mFitToWindowAction->setShortcut(gSettings->fitToWindowKey());
  mOriginalSizeAction->setShortcut(gSettings->originalSizeKey());
  mZoomInAction->setShortcut(gSettings->zoomInKey());
  mZoomOutAction->setShortcut(gSettings->zoomOutKey());
}

void ZoomMenu::setup() {
  setTitle("Zoom");

  addZoomInAction();
  addZoomOutAction();
  addOriginalSizeAction();
  addFitToWindowAction();
  addFitToCustimAction();
}

void ZoomMenu::addFitToCustimAction() {
  mFitToCustomAction = new QAction();
  mFitToCustomAction->setText("Fit to Custom");
  mFitToCustomAction->setShortcut(gSettings->fitToCustomKey());

  connect(mFitToCustomAction,
          &QAction::triggered,
          this,
          &ZoomMenu::fitToCustom);

  addAction(mFitToCustomAction);
  gMainWindow->addAction(mFitToCustomAction);
}

void ZoomMenu::addFitToWindowAction() {
  mFitToWindowAction = new QAction();
  mFitToWindowAction->setText("Fit to Window");
  mFitToWindowAction->setShortcut(gSettings->fitToWindowKey());

  connect(mFitToWindowAction,
          &QAction::triggered,
          this,
          &ZoomMenu::fitToWindow);

  addAction(mFitToWindowAction);
  gMainWindow->addAction(mFitToWindowAction);
}

void ZoomMenu::addOriginalSizeAction() {
  mOriginalSizeAction = new QAction();
  mOriginalSizeAction->setText("Original Size");
  mOriginalSizeAction->setShortcut(gSettings->originalSizeKey());

  connect(mOriginalSizeAction,
          &QAction::triggered,
          this,
          &ZoomMenu::originalSize);

  addAction(mOriginalSizeAction);
  gMainWindow->addAction(mOriginalSizeAction);
}

void ZoomMenu::addZoomInAction() {
  mZoomInAction = new QAction();
  mZoomInAction->setText("Zoom In");
  mZoomInAction->setShortcut(gSettings->zoomInKey());

  connect(mZoomInAction,
          &QAction::triggered,
          this,
          &ZoomMenu::zoomIn);

  addAction(mZoomInAction);
  gMainWindow->addAction(mZoomInAction);
}

void ZoomMenu::addZoomOutAction() {
  mZoomOutAction = new QAction();
  mZoomOutAction->setText("Zoom Out");
  mZoomOutAction->setShortcut(gSettings->zoomOutKey());

  connect(mZoomOutAction,
          &QAction::triggered,
          this,
          &ZoomMenu::zoomOut);

  addAction(mZoomOutAction);
  gMainWindow->addAction(mZoomOutAction);
}

void ZoomMenu::fitToCustom() {
  gImageView->fitToCustom();
}

void ZoomMenu::fitToWindow() {
  gImageView->fitToWindow();
}

void ZoomMenu::originalSize() {
  gImageView->originalSize();
}

void ZoomMenu::zoomIn() {
  gImageView->zoomIn();
}

void ZoomMenu::zoomOut() {
  gImageView->zoomOut();
}
