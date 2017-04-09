#include "StatusBar.h"

#include <QLabel>

#include "File.h"
#include "ImageView.h"
#include "MainWindow.h"
#include "Settings.h"

extern File *gFile;
extern ImageView *gImageView;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

StatusBar::StatusBar() {
  setup();
}

StatusBar::~StatusBar() {
}

void StatusBar::setup() {
  setSizeGripEnabled(false);

  addFileInfo();
  addPositionInfo();
  addUpdateAction();

  gMainWindow->setStatusBar(this);

  if (!gSettings->showStatusBar()) {
    hide();
  }
}

void StatusBar::addFileInfo() {
  mFileInfo = new QLabel();
  addWidget(mFileInfo);
}

void StatusBar::addPositionInfo() {
  mPositionInfo = new QLabel();
  addPermanentWidget(mPositionInfo);
}

void StatusBar::addUpdateAction() {
  connect(gFile, &File::updated, this, &StatusBar::update);
  connect(gImageView, &ImageView::updated, this, &StatusBar::update);
}

void StatusBar::update() {
  QString fileInfo = "";
  QString filePosition = "";

  if (!gFile->currentFile().fileName().isNull()) {
    fileInfo += gFile->currentFile().fileName();
    fileInfo += "    ";
    fileInfo += QString::number(gImageView->image().width())
        + "x"
        + QString::number(gImageView->image().height());
    fileInfo += "    ";
    fileInfo += QString::number(qRound(gImageView->scale() * 100)) + "%";

    filePosition += "[";
    filePosition += QString::number(gFile->index() + 1);
    filePosition += "/";
    filePosition += QString::number(gFile->size());
    filePosition += "]";
  }

  mFileInfo->setText(fileInfo);
  mPositionInfo->setText(filePosition);
}
