#include "ToolBar.h"

#include <QFileDialog>

#include "ImageView.h"
#include "MainWindow.h"
#include "Settings.h"

extern ImageView *gImageView;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

ToolBar::ToolBar() {
  setup();
}

ToolBar::~ToolBar() {
}

void ToolBar::setup() {
  setMovable(false);
  setStyleSheet("QToolBar { border: 0px; }");

  addOpenAction();
  addSpacer();
  addPreviousAction();
  addToggleSlideshowAction();
  addNextAction();
  addSpacer();
  addZoomInAction();
  addZoomOutAction();
  addOriginalSizeAction();
  addFitToWindowAction();

  gMainWindow->addToolBar(this);

  if (!gSettings->showToolBar()) {
    hide();
  }
}

void ToolBar::addFitToWindowAction() {
  mFitToWindowAction = new QAction();
  mFitToWindowAction->setIcon(QIcon("Images/zoom-fit-window.png"));
  mFitToWindowAction->setToolTip("Fit to Window");

  connect(mFitToWindowAction,
          &QAction::triggered,
          this,
          &ToolBar::fitToWindow);

  addAction(mFitToWindowAction);
}

void ToolBar::addNextAction() {
  mNextAction = new QAction();
  mNextAction->setIcon(QIcon("Images/next.png"));
  mNextAction->setToolTip("Next Image");

  connect(mNextAction,
          &QAction::triggered,
          this,
          &ToolBar::next);

  addAction(mNextAction);
}

void ToolBar::addOpenAction() {
  mOpenAction = new QAction();
  mOpenAction->setIcon(QIcon("Images/open.png"));
  mOpenAction->setToolTip("Open Image");

  connect(mOpenAction,
          &QAction::triggered,
          this,
          &ToolBar::open);

  addAction(mOpenAction);
}

void ToolBar::addOriginalSizeAction() {
  mOriginalSizeAction = new QAction();
  mOriginalSizeAction->setIcon(QIcon("Images/zoom-original.png"));
  mOriginalSizeAction->setToolTip("Original Size");

  connect(mOriginalSizeAction,
          &QAction::triggered,
          this,
          &ToolBar::originalSize);

  addAction(mOriginalSizeAction);
}

void ToolBar::addPreviousAction() {
  mPrevousAction = new QAction();
  mPrevousAction->setIcon(QIcon("Images/previous.png"));
  mPrevousAction->setToolTip("Previous Image");

  connect(mPrevousAction,
          &QAction::triggered,
          this,
          &ToolBar::previous);

  addAction(mPrevousAction);
}

void ToolBar::addSpacer() {
  QWidget *spacer = new QWidget();
  spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  addWidget(spacer);
}

void ToolBar::addToggleSlideshowAction() {
  mToggleSlideshowAction = new QAction();
  mToggleSlideshowAction->setIcon(QIcon("Images/play.png"));
  mToggleSlideshowAction->setToolTip("Play Slideshow");

  connect(mToggleSlideshowAction,
          &QAction::triggered,
          this,
          static_cast<void (ToolBar::*)(void)>(&ToolBar::toggleSlideshow));
  connect(gImageView,
          &ImageView::slideshowToggled,
          this,
          static_cast<void (ToolBar::*)(bool)>(&ToolBar::toggleSlideshow));

  addAction(mToggleSlideshowAction);
}

void ToolBar::addZoomInAction() {
  mZoomInAction = new QAction();
  mZoomInAction->setIcon(QIcon("Images/zoom-in.png"));
  mZoomInAction->setToolTip("Zoom In");

  connect(mZoomInAction,
          &QAction::triggered,
          this,
          &ToolBar::zoomIn);

  addAction(mZoomInAction);
}

void ToolBar::addZoomOutAction() {
  mZoomOutAction = new QAction();
  mZoomOutAction->setIcon(QIcon("Images/zoom-out.png"));
  mZoomOutAction->setToolTip("Zoom Out");

  connect(mZoomOutAction,
          &QAction::triggered,
          this,
          &ToolBar::zoomOut);

  addAction(mZoomOutAction);
}

void ToolBar::fitToWindow() {
  gImageView->fitToWindow();
}

void ToolBar::next() {
  gImageView->nextImage();
}

void ToolBar::open() {
  QString fileName = QFileDialog::getOpenFileName(
      gMainWindow,
      "Open Image",
      QString(),
      "Images (*bmp *jpg *png)"
  );

  if (fileName.isNull()) {
    return;
  }

  gImageView->openImage(fileName);
}

void ToolBar::originalSize() {
  gImageView->originalSize();
}

void ToolBar::previous() {
  gImageView->previousImage();
}

void ToolBar::toggleSlideshow() {
  gImageView->toggleSlideshow();
}

void ToolBar::toggleSlideshow(bool running) {
  if (running) {
    mToggleSlideshowAction->setIcon(QIcon("Images/pause.png"));
    mToggleSlideshowAction->setToolTip("Pause Slideshow");
  } else {
    mToggleSlideshowAction->setIcon(QIcon("Images/play.png"));
    mToggleSlideshowAction->setToolTip("Play Slideshow");
  }
}

void ToolBar::zoomIn() {
  gImageView->zoomIn();
}

void ToolBar::zoomOut() {
  gImageView->zoomOut();
}
