#include "SlideshowTab.h"

#include <QBoxLayout>
#include <QGroupBox>
#include <QSlider>

#include "Settings.h"

extern Settings *gSettings;

SlideshowTab::SlideshowTab() {
  setup();
}

SlideshowTab::~SlideshowTab() {
}

void SlideshowTab::reload() {
  mIntervalSlider->setValue(gSettings->slideshowInterval());
}

void SlideshowTab::setup() {
  addLayout();
  addIntervalSetting();
}

void SlideshowTab::addLayout() {
  mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
  mLayout->setAlignment(Qt::AlignTop);

  setLayout(mLayout);
}

void SlideshowTab::addIntervalSetting() {
  QBoxLayout *groupLayout = new QBoxLayout(QBoxLayout::TopToBottom);

  mIntervalGroup = new QGroupBox();
  mIntervalGroup->setTitle(
      "Interval - "
          + QString::number(gSettings->slideshowInterval()));
  mIntervalGroup->setLayout(groupLayout);

  mIntervalSlider = new QSlider();
  mIntervalSlider->setOrientation(Qt::Horizontal);
  mIntervalSlider->setRange(INTERVAL_MIN, INTERVAL_MAX);
  mIntervalSlider->setValue(gSettings->slideshowInterval());

  connect(mIntervalSlider,
          &QSlider::valueChanged,
          this,
          &SlideshowTab::interval);

  groupLayout->addWidget(mIntervalSlider);

  mLayout->addWidget(mIntervalGroup);
}

void SlideshowTab::interval(int value) {
  gSettings->setSlideshowInterval(value);
  mIntervalGroup->setTitle(
      "Interval - "
          + QString::number(gSettings->slideshowInterval()));
}
