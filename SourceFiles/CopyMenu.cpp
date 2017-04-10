#include "CopyMenu.h"

#include "File.h"
#include "MainWindow.h"
#include "Settings.h"

extern File *gFile;
extern MainWindow *gMainWindow;
extern Settings *gSettings;

CopyMenu::CopyMenu() {
  setup();
}

CopyMenu::~CopyMenu() {
}

void CopyMenu::setup() {
  setTitle("Copy to ...");

  addCopyToFolder1Action();
  addCopyToFolder2Action();
  addCopyToFolder3Action();
  addCopyToFolder4Action();
  addCopyToFolder5Action();
}

void CopyMenu::addCopyToFolder1Action() {
  mCopyToFolder1Action = new QAction();
  mCopyToFolder1Action->setText("Folder 1");
  mCopyToFolder1Action->setShortcut(gSettings->copyToFolder1Key());

  connect(mCopyToFolder1Action,
          &QAction::triggered,
          this,
          &CopyMenu::copyToFolder1);

  addAction(mCopyToFolder1Action);
  gMainWindow->addAction(mCopyToFolder1Action);
}

void CopyMenu::addCopyToFolder2Action() {
  mCopyToFolder2Action = new QAction();
  mCopyToFolder2Action->setText("Folder 2");
  mCopyToFolder2Action->setShortcut(gSettings->copyToFolder2Key());

  connect(mCopyToFolder2Action,
          &QAction::triggered,
          this,
          &CopyMenu::copyToFolder2);

  addAction(mCopyToFolder2Action);
  gMainWindow->addAction(mCopyToFolder2Action);
}

void CopyMenu::addCopyToFolder3Action() {
  mCopyToFolder3Action = new QAction();
  mCopyToFolder3Action->setText("Folder 3");
  mCopyToFolder3Action->setShortcut(gSettings->copyToFolder3Key());

  connect(mCopyToFolder3Action,
          &QAction::triggered,
          this,
          &CopyMenu::copyToFolder3);

  addAction(mCopyToFolder3Action);
  gMainWindow->addAction(mCopyToFolder3Action);
}

void CopyMenu::addCopyToFolder4Action() {
  mCopyToFolder4Action = new QAction();
  mCopyToFolder4Action->setText("Folder 4");
  mCopyToFolder4Action->setShortcut(gSettings->copyToFolder4Key());

  connect(mCopyToFolder4Action,
          &QAction::triggered,
          this,
          &CopyMenu::copyToFolder4);

  addAction(mCopyToFolder4Action);
  gMainWindow->addAction(mCopyToFolder4Action);
}

void CopyMenu::addCopyToFolder5Action() {
  mCopyToFolder5Action = new QAction();
  mCopyToFolder5Action->setText("Folder 5");
  mCopyToFolder5Action->setShortcut(gSettings->copyToFolder5Key());

  connect(mCopyToFolder5Action,
          &QAction::triggered,
          this,
          &CopyMenu::copyToFolder5);

  addAction(mCopyToFolder5Action);
  gMainWindow->addAction(mCopyToFolder5Action);
}

void CopyMenu::copyToFolder1() {
  if (gSettings->folderPath1().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath1()
                  + "/" + gFile->currentFile().fileName());
}

void CopyMenu::copyToFolder2() {
  if (gSettings->folderPath2().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath2()
                  + "/" + gFile->currentFile().fileName());
}

void CopyMenu::copyToFolder3() {
  if (gSettings->folderPath3().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath3()
                  + "/" + gFile->currentFile().fileName());
}

void CopyMenu::copyToFolder4() {
  if (gSettings->folderPath4().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath4()
                  + "/" + gFile->currentFile().fileName());
}

void CopyMenu::copyToFolder5() {
  if (gSettings->folderPath5().isEmpty()) {
    return;
  }

  QFile::copy(gFile->currentFile().absoluteFilePath(),
              gSettings->folderPath5()
                  + "/" + gFile->currentFile().fileName());
}
