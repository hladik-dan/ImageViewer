#ifndef IMAGEVIEWER_WINDOWTAB_H
#define IMAGEVIEWER_WINDOWTAB_H

#include <QWidget>

class QBoxLayout;
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

  void keepSize();
  void fitToImage();
  void fitToBigImage();

private:
  QRadioButton *mFitToBigImage = nullptr;
  QRadioButton *mFitToImage = nullptr;
  QRadioButton *mKeepSize = nullptr;
  QBoxLayout *mLayout = nullptr;
  QGroupBox *mResizeGroup = nullptr;
};

#endif  // IMAGEVIEWER_WINDOWTAB_H
