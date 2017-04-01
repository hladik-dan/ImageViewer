#ifndef IMAGEVIEWER_KEYBOARDTAB_H
#define IMAGEVIEWER_KEYBOARDTAB_H

#include <QWidget>

class QBoxLayout;
class QGroupBox;
class QKeyEvent;
class QLabel;
class QLineEdit;
class QPushButton;

class KeyboardTab : public QWidget {
public:
  KeyboardTab();
  ~KeyboardTab();

  void reload();

private:
  enum KeySetting {
    None,
    CopyToFolder1,
    CopyToFolder2,
    CopyToFolder3,
    CopyToFolder4,
    CopyToFolder5,
    FitToCustom,
    FitToWindow,
    Fullscreen,
    MoveToFolder1,
    MoveToFolder2,
    MoveToFolder3,
    MoveToFolder4,
    MoveToFolder5,
    Next,
    OriginalSize,
    Previous,
    ToggleSlideshow
  };

  void setup();
  void addCopyMoveToFoldersSetting();
  void addFitToCustomKeySetting();
  void addFitToWindowKeySetting();
  void addFullscreenKeySetting();
  void addLayout();
  void addNextKeySetting();
  void addOriginalSizeKeySetting();
  void addPreviousKeySetting();
  void addToggleSlideshowKeySetting();

  void captureKeyboard(KeySetting keySetting);
  void copyToFolder1();
  void copyToFolder2();
  void copyToFolder3();
  void copyToFolder4();
  void copyToFolder5();
  void fitToCustom();
  void fitToWindow();
  void fullscreen();
  void moveToFolder1();
  void moveToFolder2();
  void moveToFolder3();
  void moveToFolder4();
  void moveToFolder5();
  void next();
  void originalSize();
  void previous();
  void setFolderPath1();
  void setFolderPath2();
  void setFolderPath3();
  void setFolderPath4();
  void setFolderPath5();
  void toggleSlideshow();

  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);

private:
  bool mCapturing = false;
  int mKey = -1;
  KeySetting mKeySetting = None;
  Qt::KeyboardModifiers mModifiers = Qt::KeyboardModifiers();

  QLabel *mCopyLabel = nullptr;
  QGroupBox *mCopyMoveGroup = nullptr;
  QPushButton *mCopyToFolder1KeyButton = nullptr;
  QPushButton *mCopyToFolder2KeyButton = nullptr;
  QPushButton *mCopyToFolder3KeyButton = nullptr;
  QPushButton *mCopyToFolder4KeyButton = nullptr;
  QPushButton *mCopyToFolder5KeyButton = nullptr;
  QPushButton *mFitToCustomButton = nullptr;
  QLabel *mFitToCustomLabel = nullptr;
  QPushButton *mFitToWindowKeyButton = nullptr;
  QLabel *mFitToWindowKeyLabel = nullptr;
  QLineEdit *mFolderPath1 = nullptr;
  QAction *mFolderPath1Action = nullptr;
  QLineEdit *mFolderPath2 = nullptr;
  QAction *mFolderPath2Action = nullptr;
  QLineEdit *mFolderPath3 = nullptr;
  QAction *mFolderPath3Action = nullptr;
  QLineEdit *mFolderPath4 = nullptr;
  QAction *mFolderPath4Action = nullptr;
  QLineEdit *mFolderPath5 = nullptr;
  QAction *mFolderPath5Action = nullptr;
  QPushButton *mFullscreenKeyButton = nullptr;
  QLabel *mFullscreenKeyLabel = nullptr;
  QBoxLayout *mLayout = nullptr;
  QLabel *mMoveLabel = nullptr;
  QPushButton *mMoveToFolder1KeyButton = nullptr;
  QPushButton *mMoveToFolder2KeyButton = nullptr;
  QPushButton *mMoveToFolder3KeyButton = nullptr;
  QPushButton *mMoveToFolder4KeyButton = nullptr;
  QPushButton *mMoveToFolder5KeyButton = nullptr;
  QPushButton *mNextButton = nullptr;
  QLabel *mNextLabel = nullptr;
  QPushButton *mOriginalSizeKeyButton = nullptr;
  QLabel *mOriginalSizeKeyLabel = nullptr;
  QLabel *mPathToFolderLabel = nullptr;
  QPushButton *mPreviousButton = nullptr;
  QLabel *mPreviousLabel = nullptr;
  QPushButton *mToggleSlideshowKeyButton = nullptr;
  QLabel *mToggleSlideshowKeyLabel = nullptr;
};

#endif  // IMAGEVIEWER_KEYBOARDTAB_H
