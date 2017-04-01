#ifndef IMAGEVIEWER_SLIDESHOWTAB_H
#define IMAGEVIEWER_SLIDESHOWTAB_H

#include <QWidget>

class QBoxLayout;
class QGroupBox;
class QSlider;

class SlideshowTab : public QWidget {
public:
  SlideshowTab();
  ~SlideshowTab();

  void reload();

private:
  void setup();
  void addLayout();
  void addIntervalSetting();

  void interval(int value);

private:
  const int INTERVAL_MIN = 1;
  const int INTERVAL_MAX = 20;

  QBoxLayout *mLayout = nullptr;
  QGroupBox *mIntervalGroup = nullptr;
  QSlider *mIntervalSlider = nullptr;
};

#endif  // IMAGEVIEWER_SLIDESHOWTAB_H
