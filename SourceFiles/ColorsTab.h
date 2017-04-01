#ifndef IMAGEVIEWER_COLORSTAB_H
#define IMAGEVIEWER_COLORSTAB_H

#include <QWidget>

class QGridLayout;
class QLabel;
class QPushButton;

class ColorsTab : public QWidget {
public:
  ColorsTab();
  ~ColorsTab();

  void reload();

private:
  void setup();
  void addBackgroundColorPicker();
  void addBackgroundColorPickerForSlideshow();
  void addLayout();

  void pickBackgroundColor();
  void pickBackgroundColorForSlideshow();

private:
  QPushButton *mBackgroundColorButton = nullptr;
  QPushButton *mBackgroundColorForSlideshowButton = nullptr;
  QLabel *mBackgroundColorLabel = nullptr;
  QLabel *mBackgroundColorForSlideshowLabel = nullptr;
  QGridLayout *mLayout = nullptr;
};

#endif  // IMAGEVIEWER_COLORSTAB_H
