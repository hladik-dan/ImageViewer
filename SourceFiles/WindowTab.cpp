#include "WindowTab.h"

#include <QBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>

#include "Settings.h"

extern Settings *gSettings;

WindowTab::WindowTab() {
  setup();
}

WindowTab::~WindowTab() {
}

void WindowTab::reload() {
  mKeepSize->setChecked(gSettings->resize() == Settings::Resize::KeepSize);
  mFitToImage->setChecked(gSettings->resize() == Settings::Resize::FitToImage);
  mFitToBigImage->setChecked(
      gSettings->resize() == Settings::Resize::FitToBigImage);
  mShowFileNameInTitleBar->setChecked(gSettings->showFileNameInTitleBar());
}

void WindowTab::setup() {
  addLayout();
  addShowFileNameInTitleBarSetting();
  addResizeSetting();
}

void WindowTab::addLayout() {
  mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
  mLayout->setAlignment(Qt::AlignTop);

  setLayout(mLayout);
}

void WindowTab::addResizeSetting() {
  QBoxLayout *groupLayout = new QBoxLayout(QBoxLayout::TopToBottom);

  mResizeGroup = new QGroupBox();
  mResizeGroup->setTitle("Resize");
  mResizeGroup->setLayout(groupLayout);

  mKeepSize = new QRadioButton();
  mKeepSize->setText("Keep Size");
  mKeepSize->setChecked(gSettings->resize() == Settings::Resize::KeepSize);

  mFitToImage = new QRadioButton();
  mFitToImage->setText("Fit to Image");
  mFitToImage->setChecked(gSettings->resize() == Settings::Resize::FitToImage);

  mFitToBigImage = new QRadioButton();
  mFitToBigImage->setText("Fit only to Big Image");
  mFitToBigImage->setChecked(
      gSettings->resize() == Settings::Resize::FitToBigImage);

  connect(mKeepSize,
          &QRadioButton::clicked,
          this,
          &WindowTab::keepSize);
  connect(mFitToImage,
          &QRadioButton::clicked,
          this,
          &WindowTab::fitToImage);
  connect(mFitToBigImage,
          &QRadioButton::clicked,
          this,
          &WindowTab::fitToBigImage);

  groupLayout->addWidget(mKeepSize);
  groupLayout->addWidget(mFitToImage);
  groupLayout->addWidget(mFitToBigImage);

  mLayout->addWidget(mResizeGroup);
}

void WindowTab::addShowFileNameInTitleBarSetting() {
  mShowFileNameInTitleBar = new QCheckBox();
  mShowFileNameInTitleBar->setText("Show Filename in Title Bar");
  mShowFileNameInTitleBar->setChecked(gSettings->showFileNameInTitleBar());

  connect(mShowFileNameInTitleBar,
          &QCheckBox::stateChanged,
          this,
          &WindowTab::showFileNameInTitleBar);

  mLayout->addWidget(mShowFileNameInTitleBar);
}

void WindowTab::keepSize() {
  gSettings->setResize(Settings::Resize::KeepSize);
}

void WindowTab::fitToImage() {
  gSettings->setResize(Settings::Resize::FitToImage);
}

void WindowTab::fitToBigImage() {
  gSettings->setResize(Settings::Resize::FitToBigImage);
}

void WindowTab::showFileNameInTitleBar(int state) {
  if (state == Qt::Unchecked) {
    gSettings->setShowFileNameInTitleBar(false);
  } else if (state == Qt::Checked) {
    gSettings->setShowFileNameInTitleBar(true);
  }
}
