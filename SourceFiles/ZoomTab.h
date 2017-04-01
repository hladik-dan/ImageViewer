#ifndef IMAGEVIEWER_ZOOMTAB_H
#define IMAGEVIEWER_ZOOMTAB_H

#include <QWidget>

class QBoxLayout;
class QCheckBox;
class QGroupBox;
class QRadioButton;
class QSlider;
class QSpinBox;

class ZoomTab : public QWidget {
public:
  ZoomTab();
  ~ZoomTab();

  void reload();

private:
  void setup();
  void addAutoZoomSetting();
  void addEnableAutoZoomSetting();
  void addEnableZoomOnResizeSetting();
  void addLayout();
  void addZoomStepSetting();

  void enableAutoZoom(int state);
  void enableZoomOnResize(int state);
  void fitBigToCustom();
  void fitBigToDesktop();
  void fitBigToWindow();
  void fitToCustom();
  void fitToDesktop();
  void fitToWindow();
  void saveFitBigToCustomHeight(int i);
  void saveFitBigToCustomWidth(int i);
  void saveFitToCustomHeight(int i);
  void saveFitToCustomWidth(int i);
  void zoomStep(int value);

private:
  const int CUSTOM_HEIGHT_MIN = 1;
  const int CUSTOM_HEIGHT_MAX = 99999;
  const int CUSTOM_WIDTH_MIN = 1;
  const int CUSTOM_WIDTH_MAX = 99999;
  const int ZOOM_STEP_MIN = 1;
  const int ZOOM_STEP_MAX = 100;

  QGroupBox *mAutoZoomGroup = nullptr;
  QCheckBox *mEnableAutoZoomCheckBox = nullptr;
  QCheckBox *mEnableZoomOnResizeCheckBox = nullptr;
  QRadioButton *mFitBigToCustom = nullptr;
  QRadioButton *mFitBigToDesktop = nullptr;
  QRadioButton *mFitBigToWindow = nullptr;
  QRadioButton *mFitToCustom = nullptr;
  QSpinBox *mFitBigToCustomHeight = nullptr;
  QSpinBox *mFitBigToCustomWidth = nullptr;
  QSpinBox *mFitToCustomHeight = nullptr;
  QSpinBox *mFitToCustomWidth = nullptr;
  QRadioButton *mFitToDesktop = nullptr;
  QRadioButton *mFitToWindow = nullptr;
  QBoxLayout *mLayout = nullptr;
  QGroupBox *mZoomStepGroup = nullptr;
  QSlider *mZoomStepSlider = nullptr;
};

#endif //IMAGEVIEWER_ZOOMTAB_H
