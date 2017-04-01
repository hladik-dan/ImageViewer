#include "MoveMenu.h"

#include "File.h"
#include "MainWindow.h"
#include "Settings.h"

extern File *gFile;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

MoveMenu::MoveMenu() {
  setup();
}

MoveMenu::~MoveMenu() {
}

void MoveMenu::setup() {
  setTitle("Move to ...");

  addMoveToFolder1Action();
  addMoveToFolder2Action();
  addMoveToFolder3Action();
  addMoveToFolder4Action();
  addMoveToFolder5Action();
}

void MoveMenu::addMoveToFolder1Action() {
  mMoveToFolder1Action = new QAction();
  mMoveToFolder1Action->setText("Folder 1");
  mMoveToFolder1Action->setShortcut(gSettings->moveToFolder1Key());

  connect(mMoveToFolder1Action,
          &QAction::triggered,
          this,
          &MoveMenu::moveToFolder1);

  addAction(mMoveToFolder1Action);
  gMainWindow->addAction(mMoveToFolder1Action);
}

void MoveMenu::addMoveToFolder2Action() {
  mMoveToFolder2Action = new QAction();
  mMoveToFolder2Action->setText("Folder 2");
  mMoveToFolder2Action->setShortcut(gSettings->moveToFolder2Key());

  connect(mMoveToFolder2Action,
          &QAction::triggered,
          this,
          &MoveMenu::moveToFolder2);

  addAction(mMoveToFolder2Action);
  gMainWindow->addAction(mMoveToFolder2Action);
}

void MoveMenu::addMoveToFolder3Action() {
  mMoveToFolder3Action = new QAction();
  mMoveToFolder3Action->setText("Folder 3");
  mMoveToFolder3Action->setShortcut(gSettings->moveToFolder3Key());

  connect(mMoveToFolder3Action,
          &QAction::triggered,
          this,
          &MoveMenu::moveToFolder3);

  addAction(mMoveToFolder3Action);
  gMainWindow->addAction(mMoveToFolder3Action);
}

void MoveMenu::addMoveToFolder4Action() {
  mMoveToFolder4Action = new QAction();
  mMoveToFolder4Action->setText("Folder 4");
  mMoveToFolder4Action->setShortcut(gSettings->moveToFolder4Key());

  connect(mMoveToFolder4Action,
          &QAction::triggered,
          this,
          &MoveMenu::moveToFolder4);

  addAction(mMoveToFolder4Action);
  gMainWindow->addAction(mMoveToFolder4Action);
}

void MoveMenu::addMoveToFolder5Action() {
  mMoveToFolder5Action = new QAction();
  mMoveToFolder5Action->setText("Folder 5");
  mMoveToFolder5Action->setShortcut(gSettings->moveToFolder5Key());

  connect(mMoveToFolder5Action,
          &QAction::triggered,
          this,
          &MoveMenu::moveToFolder5);

  addAction(mMoveToFolder5Action);
  gMainWindow->addAction(mMoveToFolder5Action);
}

void MoveMenu::moveToFolder1() {
  if (gSettings->folderPath1().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath1()
                  + "/" + gFile->currentFile().fileName());

  QFile::remove(gFile->currentFile().absoluteFilePath());
}

void MoveMenu::moveToFolder2() {
  if (!gSettings->folderPath2().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath2()
                  + "/" + gFile->currentFile().fileName());

  QFile::remove(gFile->currentFile().absoluteFilePath());
}

void MoveMenu::moveToFolder3() {
  if (!gSettings->folderPath3().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath3()
                  + "/" + gFile->currentFile().fileName());

  QFile::remove(gFile->currentFile().absoluteFilePath());
}

void MoveMenu::moveToFolder4() {
  if (!gSettings->folderPath4().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath4()
                  + "/" + gFile->currentFile().fileName());

  QFile::remove(gFile->currentFile().absoluteFilePath());
}

void MoveMenu::moveToFolder5() {
  if (!gSettings->folderPath5().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath5()
                  + "/" + gFile->currentFile().fileName());

  QFile::remove(gFile->currentFile().absoluteFilePath());
}
