#include "ZoomTab.h"

#include <QBoxLayout>
#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>

#include "Settings.h"

extern Settings *gSettings;

ZoomTab::ZoomTab() {
  setup();
}

ZoomTab::~ZoomTab() {
}

void ZoomTab::reload() {
  mEnableAutoZoomCheckBox->setChecked(gSettings->enableAutoZoom());
  mEnableZoomOnResizeCheckBox->setChecked(gSettings->enableZoomOnResize());
  mFitBigToCustom->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitBigToCustom);
  mFitBigToDesktop->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitBigToDesktop);
  mFitBigToWindow->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitBigToWindow);
  mFitToCustom->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitToCustom);
  mFitToDesktop->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitToDesktop);
  mFitToWindow->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitToWindow);
  mZoomStepGroup->setTitle(
      "Zoom Step - " + QString::number(gSettings->zoomStep()));
  mZoomStepSlider->setValue(gSettings->zoomStep());
}

void ZoomTab::setup() {
  addLayout();
  addEnableAutoZoomSetting();
  addEnableZoomOnResizeSetting();
  addAutoZoomSetting();
  addZoomStepSetting();
}

void ZoomTab::addAutoZoomSetting() {
  QGridLayout *groupLayout = new QGridLayout();

  mAutoZoomGroup = new QGroupBox();
  mAutoZoomGroup->setTitle("Auto Zoom");
  mAutoZoomGroup->setLayout(groupLayout);
  mAutoZoomGroup->setEnabled(gSettings->enableAutoZoom());

  mFitToWindow = new QRadioButton();
  mFitToWindow->setText("Fit to Window");
  mFitToWindow->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitToWindow);

  mFitBigToWindow = new QRadioButton();
  mFitBigToWindow->setText("Fit Big Images to Window");
  mFitBigToWindow->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitBigToWindow);

  mFitToDesktop = new QRadioButton();
  mFitToDesktop->setText("Fit to Desktop");
  mFitToDesktop->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitToDesktop);

  mFitBigToDesktop = new QRadioButton();
  mFitBigToDesktop->setText("Fit Big Images to Desktop");
  mFitBigToDesktop->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitBigToDesktop);

  mFitToCustom = new QRadioButton();
  mFitToCustom->setText("Fit to ...");
  mFitToCustom->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitToCustom);

  mFitToCustomWidth = new QSpinBox();
  mFitToCustomWidth->setRange(CUSTOM_WIDTH_MIN, CUSTOM_WIDTH_MAX);
  mFitToCustomWidth->setValue(gSettings->fitToCustomWidth());

  mFitToCustomHeight = new QSpinBox();
  mFitToCustomHeight->setRange(CUSTOM_HEIGHT_MIN, CUSTOM_HEIGHT_MAX);
  mFitToCustomHeight->setValue(gSettings->fitToCustomHeight());

  mFitBigToCustom = new QRadioButton();
  mFitBigToCustom->setText("Fit only Big Images to ...");
  mFitBigToCustom->setChecked(
      gSettings->autoZoom() == Settings::AutoZoom::FitBigToCustom);

  mFitBigToCustomWidth = new QSpinBox();
  mFitBigToCustomWidth->setRange(CUSTOM_WIDTH_MIN, CUSTOM_WIDTH_MAX);
  mFitBigToCustomWidth->setValue(gSettings->fitBigToCustomWidth());

  mFitBigToCustomHeight = new QSpinBox();
  mFitBigToCustomHeight->setRange(CUSTOM_HEIGHT_MIN, CUSTOM_HEIGHT_MAX);
  mFitBigToCustomHeight->setValue(gSettings->fitBigToCustomHeight());

  connect(mFitToWindow,
          &QRadioButton::clicked,
          this,
          &ZoomTab::fitToWindow);
  connect(mFitBigToWindow,
          &QRadioButton::clicked,
          this,
          &ZoomTab::fitBigToWindow);
  connect(mFitToDesktop,
          &QRadioButton::clicked,
          this,
          &ZoomTab::fitToDesktop);
  connect(mFitBigToDesktop,
          &QRadioButton::clicked,
          this,
          &ZoomTab::fitBigToDesktop);
  connect(mFitToCustom,
          &QRadioButton::clicked,
          this,
          &ZoomTab::fitToCustom);
  connect(mFitBigToCustom,
          &QRadioButton::clicked,
          this,
          &ZoomTab::fitBigToCustom);
  connect(mFitToCustomHeight,
          static_cast<void (QSpinBox::*)(int i)>(&QSpinBox::valueChanged),
          this,
          &ZoomTab::saveFitToCustomHeight);
  connect(mFitToCustomWidth,
          static_cast<void (QSpinBox::*)(int i)>(&QSpinBox::valueChanged),
          this,
          &ZoomTab::saveFitToCustomWidth);
  connect(mFitBigToCustomHeight,
          static_cast<void (QSpinBox::*)(int i)>(&QSpinBox::valueChanged),
          this,
          &ZoomTab::saveFitBigToCustomHeight);
  connect(mFitBigToCustomWidth,
          static_cast<void (QSpinBox::*)(int i)>(&QSpinBox::valueChanged),
          this,
          &ZoomTab::saveFitBigToCustomWidth);

  groupLayout->addWidget(mFitToWindow, 0, 0);
  groupLayout->addWidget(mFitBigToWindow, 1, 0);
  groupLayout->addWidget(mFitToDesktop, 2, 0);
  groupLayout->addWidget(mFitBigToDesktop, 3, 0);
  groupLayout->addWidget(mFitToCustom, 4, 0);
  groupLayout->addWidget(mFitToCustomWidth, 4, 1);
  groupLayout->addWidget(mFitToCustomHeight, 4, 2);
  groupLayout->addWidget(mFitBigToCustom, 5, 0);
  groupLayout->addWidget(mFitBigToCustomWidth, 5, 1);
  groupLayout->addWidget(mFitBigToCustomHeight, 5, 2);

  mLayout->addWidget(mAutoZoomGroup);
}

void ZoomTab::addEnableAutoZoomSetting() {
  mEnableAutoZoomCheckBox = new QCheckBox();
  mEnableAutoZoomCheckBox->setText("Enable Auto Zoom");
  mEnableAutoZoomCheckBox->setChecked(gSettings->enableAutoZoom());

  connect(mEnableAutoZoomCheckBox,
          &QCheckBox::stateChanged,
          this,
          &ZoomTab::enableAutoZoom);

  mLayout->addWidget(mEnableAutoZoomCheckBox);
}

void ZoomTab::addEnableZoomOnResizeSetting() {
  mEnableZoomOnResizeCheckBox = new QCheckBox();
  mEnableZoomOnResizeCheckBox->setText("Enable Zoom on Resize");
  mEnableZoomOnResizeCheckBox->setChecked(gSettings->enableZoomOnResize());

  connect(mEnableZoomOnResizeCheckBox,
          &QCheckBox::stateChanged,
          this,
          &ZoomTab::enableZoomOnResize);

  mLayout->addWidget(mEnableZoomOnResizeCheckBox);
}

void ZoomTab::addLayout() {
  mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
  mLayout->setAlignment(Qt::AlignTop);

  setLayout(mLayout);
}

void ZoomTab::addZoomStepSetting() {
  QBoxLayout *groupLayout = new QBoxLayout(QBoxLayout::TopToBottom);

  mZoomStepGroup = new QGroupBox();
  mZoomStepGroup->setTitle(
      "Zoom Step - " + QString::number(gSettings->zoomStep()));
  mZoomStepGroup->setLayout(groupLayout);

  mZoomStepSlider = new QSlider();
  mZoomStepSlider->setOrientation(Qt::Horizontal);
  mZoomStepSlider->setRange(ZOOM_STEP_MIN, ZOOM_STEP_MAX);
  mZoomStepSlider->setValue(gSettings->zoomStep());

  connect(mZoomStepSlider,
          &QSlider::valueChanged,
          this,
          &ZoomTab::zoomStep);

  groupLayout->addWidget(mZoomStepSlider);

  mLayout->addWidget(mZoomStepGroup);
}

void ZoomTab::enableAutoZoom(int state) {
  if (state == Qt::Unchecked) {
    gSettings->setEnableAutoZoom(false);
    mAutoZoomGroup->setEnabled(false);
  } else if (state == Qt::Checked) {
    gSettings->setEnableAutoZoom(true);
    mAutoZoomGroup->setEnabled(true);
  }
}

void ZoomTab::enableZoomOnResize(int state) {
  if (state == Qt::Unchecked) {
    gSettings->setEnableZoomOnResize(false);
  } else if (state == Qt::Checked) {
    gSettings->setEnableZoomOnResize(true);
  }
}

void ZoomTab::fitBigToCustom() {
  gSettings->setAutoZoom(Settings::AutoZoom::FitBigToCustom);
}

void ZoomTab::fitBigToDesktop() {
  gSettings->setAutoZoom(Settings::AutoZoom::FitBigToDesktop);
}

void ZoomTab::fitBigToWindow() {
  gSettings->setAutoZoom(Settings::AutoZoom::FitBigToWindow);
}

void ZoomTab::fitToCustom() {
  gSettings->setAutoZoom(Settings::AutoZoom::FitToCustom);
}

void ZoomTab::fitToDesktop() {
  gSettings->setAutoZoom(Settings::AutoZoom::FitToDesktop);
}

void ZoomTab::fitToWindow() {
  gSettings->setAutoZoom(Settings::AutoZoom::FitToWindow);
}

void ZoomTab::saveFitBigToCustomHeight(int i) {
  gSettings->setFitBigToCustomHeight(i);
}

void ZoomTab::saveFitBigToCustomWidth(int i) {
  gSettings->setFitBigToCustomWidth(i);
}

void ZoomTab::saveFitToCustomHeight(int i) {
  gSettings->setFitToCustomHeight(i);
}

void ZoomTab::saveFitToCustomWidth(int i) {
  gSettings->setFitToCustomWidth(i);
}

void ZoomTab::zoomStep(int value) {
  gSettings->setZoomStep(value);
  mZoomStepGroup->setTitle(
      "Zoom Step - " + QString::number(gSettings->zoomStep()));
}
