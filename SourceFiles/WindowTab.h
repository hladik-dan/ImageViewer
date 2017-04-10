#ifndef IMAGEVIEWER_WINDOWTAB_H
#define IMAGEVIEWER_WINDOWTAB_H

#include <QWidget>

class QBoxLayout;
class QCheckBox;
class QGroupBox;
class QRadioButton;

class WindowTab : public QWidget {
public:
  WindowTab();
  ~WindowTab();

  void reload();

private:
  void setup();
  void addLayout();
  void addResizeSetting();
  void addShowFileNameInTitleBarSetting();

  void keepSize();
  void fitToImage();
  void fitToBigImage();
  void showFileNameInTitleBar(int state);

private:
  QRadioButton *mFitToBigImage = nullptr;
  QRadioButton *mFitToImage = nullptr;
  QRadioButton *mKeepSize = nullptr;
  QBoxLayout *mLayout = nullptr;
  QGroupBox *mResizeGroup = nullptr;
  QCheckBox *mShowFileNameInTitleBar = nullptr;
};

#endif  // IMAGEVIEWER_WINDOWTAB_H
