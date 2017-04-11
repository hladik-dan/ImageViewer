#include "FileMenu.h"

#include <QFileDialog>

#include "ImageView.h"
#include "MainWindow.h"
#include "Settings.h"

extern ImageView *gImageView;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

FileMenu::FileMenu() {
  setup();
}

FileMenu::~FileMenu() {
}

void FileMenu::setup() {
  setTitle("File");

  addOpenAction();
  addSeparator();
  addSaveAsAction();
  addCloseAction();
  addSeparator();
  addQuitAction();
}

void FileMenu::addCloseAction() {
  mCloseAction = new QAction();
  mCloseAction->setText("Close");
  mCloseAction->setShortcut(gSettings->closeKey());

  connect(mCloseAction,
          &QAction::triggered,
          this,
          &FileMenu::close);

  addAction(mCloseAction);
  gMainWindow->addAction(mCloseAction);
}

void FileMenu::addOpenAction() {
  mOpenAction = new QAction();
  mOpenAction->setText("Open");
  mOpenAction->setShortcut(gSettings->openKey());

  connect(mOpenAction,
          &QAction::triggered,
          this,
          &FileMenu::open);

  addAction(mOpenAction);
  gMainWindow->addAction(mOpenAction);
}

void FileMenu::addQuitAction() {
  mQuitAction = new QAction();
  mQuitAction->setText("Quit");
  mQuitAction->setShortcut(gSettings->quitKey());

  connect(mQuitAction,
          &QAction::triggered,
          this,
          &FileMenu::quit);

  addAction(mQuitAction);
  gMainWindow->addAction(mQuitAction);
}

void FileMenu::addSaveAsAction() {
  mSaveAsAction = new QAction();
  mSaveAsAction->setText("Save As");
  mSaveAsAction->setShortcut(gSettings->saveAsKey());

  connect(mSaveAsAction,
          &QAction::triggered,
          this,
          &FileMenu::saveAs);

  addAction(mSaveAsAction);
  gMainWindow->addAction(mSaveAsAction);
}

void FileMenu::close() {
  gImageView->closeImage();
}

void FileMenu::open() {
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

void FileMenu::quit() {
  gMainWindow->close();
}

void FileMenu::saveAs() {
  QString filters = "BMP Image (*.bmp);;JPEG Image (*.jpg);;PNG Image (*.png)";
  QString selectedFilter = "PNG Image (*.png)";
  QString fileName = QFileDialog::getSaveFileName(gMainWindow,
                                                  "Save Image",
                                                  QString(),
                                                  filters,
                                                  &selectedFilter);

  if (fileName.isNull()) {
    return;
  }

  if (selectedFilter == "BMP Image (*.bmp)") {
    fileName += ".bmp";
  } else if (selectedFilter == "JPEG Image (*.jpg)") {
    fileName += ".jpg";
  } else if (selectedFilter == "PNG Image (*.png)") {
    fileName += ".png";
  }

  gImageView->saveImage(fileName);
}
