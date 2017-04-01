#include "KeyboardTab.h"

#include <QAction>
#include <QBoxLayout>
#include <QFileDialog>
#include <QGroupBox>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "Settings.h"

extern Settings *gSettings;

KeyboardTab::KeyboardTab() {
  setup();
}

KeyboardTab::~KeyboardTab() {
}

void KeyboardTab::reload() {
  mCopyToFolder1KeyButton->setText(gSettings->copyToFolder1Key().toString());
  mCopyToFolder2KeyButton->setText(gSettings->copyToFolder2Key().toString());
  mCopyToFolder3KeyButton->setText(gSettings->copyToFolder3Key().toString());
  mCopyToFolder4KeyButton->setText(gSettings->copyToFolder4Key().toString());
  mCopyToFolder5KeyButton->setText(gSettings->copyToFolder5Key().toString());
  mFitToCustomButton->setText(gSettings->fitToCustomKey().toString());
  mFitToWindowKeyButton->setText(gSettings->fitToWindowKey().toString());
  mFolderPath1->setText(gSettings->folderPath1());
  mFolderPath2->setText(gSettings->folderPath2());
  mFolderPath3->setText(gSettings->folderPath3());
  mFolderPath4->setText(gSettings->folderPath4());
  mFolderPath5->setText(gSettings->folderPath5());
  mFullscreenKeyButton->setText(gSettings->fullscreenKey().toString());
  mMoveToFolder1KeyButton->setText(gSettings->moveToFolder1Key().toString());
  mMoveToFolder2KeyButton->setText(gSettings->moveToFolder2Key().toString());
  mMoveToFolder3KeyButton->setText(gSettings->moveToFolder3Key().toString());
  mMoveToFolder4KeyButton->setText(gSettings->moveToFolder4Key().toString());
  mMoveToFolder5KeyButton->setText(gSettings->moveToFolder5Key().toString());
  mNextButton->setText(gSettings->nextKey().toString());
  mOriginalSizeKeyButton->setText(gSettings->originalSizeKey().toString());
  mPreviousButton->setText(gSettings->previousKey().toString());
  mToggleSlideshowKeyButton->setText(
      gSettings->toggleSlideshowKey().toString());
}

void KeyboardTab::setup() {
  addLayout();
  addOriginalSizeKeySetting();
  addFitToWindowKeySetting();
  addFitToCustomKeySetting();
  addPreviousKeySetting();
  addNextKeySetting();
  addFullscreenKeySetting();
  addToggleSlideshowKeySetting();
  addCopyMoveToFoldersSetting();
}

void KeyboardTab::addCopyMoveToFoldersSetting() {
  QGridLayout *groupLayout = new QGridLayout();

  mCopyMoveGroup = new QGroupBox();
  mCopyMoveGroup->setTitle("Copy/Move to ...");
  mCopyMoveGroup->setLayout(groupLayout);


  mPathToFolderLabel = new QLabel();
  mPathToFolderLabel->setText("Path to Folder");

  mCopyLabel = new QLabel();
  mCopyLabel->setText("Copy");

  mMoveLabel = new QLabel();
  mMoveLabel->setText("Move");


  mFolderPath1 = new QLineEdit();
  mFolderPath1->setText(gSettings->folderPath1());

  mFolderPath1Action = mFolderPath1->addAction(QIcon("Images/folder.png"),
                                               QLineEdit::TrailingPosition);

  mCopyToFolder1KeyButton = new QPushButton();
  mCopyToFolder1KeyButton->setText(gSettings->copyToFolder1Key().toString());

  mMoveToFolder1KeyButton = new QPushButton();
  mMoveToFolder1KeyButton->setText(gSettings->moveToFolder1Key().toString());


  mFolderPath2 = new QLineEdit();
  mFolderPath2->setText(gSettings->folderPath2());

  mFolderPath2Action = mFolderPath2->addAction(QIcon("Images/folder.png"),
                                               QLineEdit::TrailingPosition);

  mCopyToFolder2KeyButton = new QPushButton();
  mCopyToFolder2KeyButton->setText(gSettings->copyToFolder2Key().toString());

  mMoveToFolder2KeyButton = new QPushButton();
  mMoveToFolder2KeyButton->setText(gSettings->moveToFolder2Key().toString());


  mFolderPath3 = new QLineEdit();
  mFolderPath3->setText(gSettings->folderPath3());

  mFolderPath3Action = mFolderPath3->addAction(QIcon("Images/folder.png"),
                                               QLineEdit::TrailingPosition);

  mCopyToFolder3KeyButton = new QPushButton();
  mCopyToFolder3KeyButton->setText(gSettings->copyToFolder3Key().toString());

  mMoveToFolder3KeyButton = new QPushButton();
  mMoveToFolder3KeyButton->setText(gSettings->moveToFolder3Key().toString());


  mFolderPath4 = new QLineEdit();
  mFolderPath4->setText(gSettings->folderPath4());

  mFolderPath4Action = mFolderPath4->addAction(QIcon("Images/folder.png"),
                                               QLineEdit::TrailingPosition);

  mCopyToFolder4KeyButton = new QPushButton();
  mCopyToFolder4KeyButton->setText(gSettings->copyToFolder4Key().toString());

  mMoveToFolder4KeyButton = new QPushButton();
  mMoveToFolder4KeyButton->setText(gSettings->moveToFolder4Key().toString());


  mFolderPath5 = new QLineEdit();
  mFolderPath5->setText(gSettings->folderPath5());

  mFolderPath5Action = mFolderPath5->addAction(QIcon("Images/folder.png"),
                                               QLineEdit::TrailingPosition);

  mCopyToFolder5KeyButton = new QPushButton();
  mCopyToFolder5KeyButton->setText(gSettings->copyToFolder5Key().toString());

  mMoveToFolder5KeyButton = new QPushButton();
  mMoveToFolder5KeyButton->setText(gSettings->moveToFolder5Key().toString());


  connect(mFolderPath1Action,
          &QAction::triggered,
          this,
          &KeyboardTab::setFolderPath1);
  connect(mFolderPath2Action,
          &QAction::triggered,
          this,
          &KeyboardTab::setFolderPath2);
  connect(mFolderPath3Action,
          &QAction::triggered,
          this,
          &KeyboardTab::setFolderPath3);
  connect(mFolderPath4Action,
          &QAction::triggered,
          this,
          &KeyboardTab::setFolderPath4);
  connect(mFolderPath5Action,
          &QAction::triggered,
          this,
          &KeyboardTab::setFolderPath5);

  connect(mCopyToFolder1KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::copyToFolder1);
  connect(mCopyToFolder2KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::copyToFolder2);
  connect(mCopyToFolder3KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::copyToFolder3);
  connect(mCopyToFolder4KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::copyToFolder4);
  connect(mCopyToFolder5KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::copyToFolder5);

  connect(mMoveToFolder1KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::moveToFolder1);
  connect(mMoveToFolder2KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::moveToFolder2);
  connect(mMoveToFolder3KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::moveToFolder3);
  connect(mMoveToFolder4KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::moveToFolder4);
  connect(mMoveToFolder5KeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::moveToFolder5);

  groupLayout->addWidget(mPathToFolderLabel, 0, 0);
  groupLayout->addWidget(mCopyLabel, 0, 1, Qt::AlignHCenter);
  groupLayout->addWidget(mMoveLabel, 0, 2, Qt::AlignHCenter);
  groupLayout->addWidget(mFolderPath1, 1, 0);
  groupLayout->addWidget(mCopyToFolder1KeyButton, 1, 1);
  groupLayout->addWidget(mMoveToFolder1KeyButton, 1, 2);
  groupLayout->addWidget(mFolderPath2, 2, 0);
  groupLayout->addWidget(mCopyToFolder2KeyButton, 2, 1);
  groupLayout->addWidget(mMoveToFolder2KeyButton, 2, 2);
  groupLayout->addWidget(mFolderPath3, 3, 0);
  groupLayout->addWidget(mCopyToFolder3KeyButton, 3, 1);
  groupLayout->addWidget(mMoveToFolder3KeyButton, 3, 2);
  groupLayout->addWidget(mFolderPath4, 4, 0);
  groupLayout->addWidget(mCopyToFolder4KeyButton, 4, 1);
  groupLayout->addWidget(mMoveToFolder4KeyButton, 4, 2);
  groupLayout->addWidget(mFolderPath5, 5, 0);
  groupLayout->addWidget(mCopyToFolder5KeyButton, 5, 1);
  groupLayout->addWidget(mMoveToFolder5KeyButton, 5, 2);

  mLayout->addWidget(mCopyMoveGroup);
}

void KeyboardTab::addFitToCustomKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mFitToCustomLabel = new QLabel();
  mFitToCustomLabel->setText("Fit to Custom");

  mFitToCustomButton = new QPushButton();
  mFitToCustomButton->setText(gSettings->fitToCustomKey().toString());

  connect(mFitToCustomButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::fitToCustom);

  layout->addWidget(mFitToCustomLabel);
  layout->addWidget(mFitToCustomButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::addFitToWindowKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mFitToWindowKeyLabel = new QLabel();
  mFitToWindowKeyLabel->setText("Fit to Window");

  mFitToWindowKeyButton = new QPushButton();
  mFitToWindowKeyButton->setText(gSettings->fitToWindowKey().toString());

  connect(mFitToWindowKeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::fitToWindow);

  layout->addWidget(mFitToWindowKeyLabel);
  layout->addWidget(mFitToWindowKeyButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::addFullscreenKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mFullscreenKeyLabel = new QLabel();
  mFullscreenKeyLabel->setText("Fullscreen");

  mFullscreenKeyButton = new QPushButton();
  mFullscreenKeyButton->setText(gSettings->fullscreenKey().toString());

  connect(mFullscreenKeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::fullscreen);

  layout->addWidget(mFullscreenKeyLabel);
  layout->addWidget(mFullscreenKeyButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::addLayout() {
  mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
  mLayout->setAlignment(Qt::AlignTop);

  setLayout(mLayout);
}

void KeyboardTab::addNextKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mNextLabel = new QLabel();
  mNextLabel->setText("Next Image");

  mNextButton = new QPushButton();
  mNextButton->setText(gSettings->nextKey().toString());

  connect(mNextButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::next);

  layout->addWidget(mNextLabel);
  layout->addWidget(mNextButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::addOriginalSizeKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mOriginalSizeKeyLabel = new QLabel();
  mOriginalSizeKeyLabel->setText("Original Size");

  mOriginalSizeKeyButton = new QPushButton();
  mOriginalSizeKeyButton->setText(gSettings->originalSizeKey().toString());

  connect(mOriginalSizeKeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::originalSize);

  layout->addWidget(mOriginalSizeKeyLabel);
  layout->addWidget(mOriginalSizeKeyButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::addPreviousKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mPreviousLabel = new QLabel();
  mPreviousLabel->setText("Previous Image");

  mPreviousButton = new QPushButton();
  mPreviousButton->setText(gSettings->previousKey().toString());

  connect(mPreviousButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::previous);

  layout->addWidget(mPreviousLabel);
  layout->addWidget(mPreviousButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::addToggleSlideshowKeySetting() {
  QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

  mToggleSlideshowKeyLabel = new QLabel();
  mToggleSlideshowKeyLabel->setText("Play/Pause Slideshow");

  mToggleSlideshowKeyButton = new QPushButton();
  mToggleSlideshowKeyButton->setText(
      gSettings->toggleSlideshowKey().toString());

  connect(mToggleSlideshowKeyButton,
          &QPushButton::clicked,
          this,
          &KeyboardTab::toggleSlideshow);

  layout->addWidget(mToggleSlideshowKeyLabel);
  layout->addWidget(mToggleSlideshowKeyButton);

  mLayout->addLayout(layout);
}

void KeyboardTab::captureKeyboard(KeySetting keySetting) {
  mCapturing = true;
  mKeySetting = keySetting;
  QWidget::grabKeyboard();
}

void KeyboardTab::copyToFolder1() {
  mCopyToFolder1KeyButton->setText("<Press a Key>");
  captureKeyboard(CopyToFolder1);
}

void KeyboardTab::copyToFolder2() {
  mCopyToFolder2KeyButton->setText("<Press a Key>");
  captureKeyboard(CopyToFolder2);
}

void KeyboardTab::copyToFolder3() {
  mCopyToFolder3KeyButton->setText("<Press a Key>");
  captureKeyboard(CopyToFolder3);
}

void KeyboardTab::copyToFolder4() {
  mCopyToFolder4KeyButton->setText("<Press a Key>");
  captureKeyboard(CopyToFolder4);
}

void KeyboardTab::copyToFolder5() {
  mCopyToFolder5KeyButton->setText("<Press a Key>");
  captureKeyboard(CopyToFolder5);
}

void KeyboardTab::fitToCustom() {
  mFitToCustomButton->setText("<Press a Key>");
  captureKeyboard(FitToCustom);
}

void KeyboardTab::fitToWindow() {
  mFitToWindowKeyButton->setText("<Press a Key>");
  captureKeyboard(FitToWindow);
}

void KeyboardTab::fullscreen() {
  mFullscreenKeyButton->setText("<Press a Key>");
  captureKeyboard(Fullscreen);
}

void KeyboardTab::moveToFolder1() {
  mMoveToFolder1KeyButton->setText("<Press a Key>");
  captureKeyboard(MoveToFolder1);
}
void KeyboardTab::moveToFolder2() {
  mMoveToFolder2KeyButton->setText("<Press a Key>");
  captureKeyboard(MoveToFolder2);
}
void KeyboardTab::moveToFolder3() {
  mMoveToFolder3KeyButton->setText("<Press a Key>");
  captureKeyboard(MoveToFolder3);
}
void KeyboardTab::moveToFolder4() {
  mMoveToFolder4KeyButton->setText("<Press a Key>");
  captureKeyboard(MoveToFolder4);
}
void KeyboardTab::moveToFolder5() {
  mMoveToFolder5KeyButton->setText("<Press a Key>");
  captureKeyboard(MoveToFolder5);
}

void KeyboardTab::next() {
  mNextButton->setText("<Press a Key>");
  captureKeyboard(Next);
}

void KeyboardTab::originalSize() {
  mOriginalSizeKeyButton->setText("<Press a Key>");
  captureKeyboard(OriginalSize);
}

void KeyboardTab::previous() {
  mPreviousButton->setText("<Press a Key>");
  captureKeyboard(Previous);
}

void KeyboardTab::setFolderPath1() {
  QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");

  if (folderPath.isNull()) {
    return;
  }

  mFolderPath1->setText(folderPath);
  gSettings->setFolderPath1(folderPath);
}

void KeyboardTab::setFolderPath2() {
  QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");

  if (folderPath.isNull()) {
    return;
  }

  mFolderPath2->setText(folderPath);
  gSettings->setFolderPath2(folderPath);
}

void KeyboardTab::setFolderPath3() {
  QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");

  if (folderPath.isNull()) {
    return;
  }

  mFolderPath3->setText(folderPath);
  gSettings->setFolderPath3(folderPath);
}

void KeyboardTab::setFolderPath4() {
  QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");

  if (folderPath.isNull()) {
    return;
  }

  mFolderPath4->setText(folderPath);
  gSettings->setFolderPath4(folderPath);
}

void KeyboardTab::setFolderPath5() {
  QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");

  if (folderPath.isNull()) {
    return;
  }

  mFolderPath5->setText(folderPath);
  gSettings->setFolderPath5(folderPath);
}

void KeyboardTab::toggleSlideshow() {
  mToggleSlideshowKeyButton->setText("<Press a Key>");
  captureKeyboard(ToggleSlideshow);
}

void KeyboardTab::keyPressEvent(QKeyEvent *event) {
  if (mCapturing) {
    mModifiers = event->modifiers();
    mKey = event->key();
  }

  QWidget::keyPressEvent(event);
}

void KeyboardTab::keyReleaseEvent(QKeyEvent *event) {

  if (mCapturing) {
    QKeySequence keySequence(mKey | mModifiers);

    switch (mKeySetting) {
      case CopyToFolder1:
        gSettings->setCopyToFolder1Key(keySequence);
        break;
      case CopyToFolder2:
        gSettings->setCopyToFolder2Key(keySequence);
        break;
      case CopyToFolder3:
        gSettings->setCopyToFolder3Key(keySequence);
        break;
      case CopyToFolder4:
        gSettings->setCopyToFolder4Key(keySequence);
        break;
      case CopyToFolder5:
        gSettings->setCopyToFolder5Key(keySequence);
        break;
      case FitToCustom:
        gSettings->setFitToCustomKey(keySequence);
        break;
      case FitToWindow:
        gSettings->setFitToWindowKey(keySequence);
        break;
      case Fullscreen:
        gSettings->setFullscreenKey(keySequence);
        break;
      case MoveToFolder1:
        gSettings->setMoveToFolder1Key(keySequence);
        break;
      case MoveToFolder2:
        gSettings->setMoveToFolder2Key(keySequence);
        break;
      case MoveToFolder3:
        gSettings->setMoveToFolder3Key(keySequence);
        break;
      case MoveToFolder4:
        gSettings->setMoveToFolder4Key(keySequence);
        break;
      case MoveToFolder5:
        gSettings->setMoveToFolder5Key(keySequence);
        break;
      case Next:
        gSettings->setNextKey(keySequence);
        break;
      case OriginalSize:
        gSettings->setOriginalSizeKey(keySequence);
        break;
      case Previous:
        gSettings->setPreviousKey(keySequence);
        break;
      case ToggleSlideshow:
        gSettings->setToggleSlideshowKey(keySequence);
        break;
      default:
        break;
    }

    mCapturing = false;
    mKeySetting = None;
    QWidget::releaseKeyboard();

    reload();
  }

  QWidget::keyReleaseEvent(event);
}
