#include "ColorsTab.h"

#include <QColorDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include "Settings.h"

extern Settings *gSettings;

ColorsTab::ColorsTab() {
  setup();
}

ColorsTab::~ColorsTab() {
}

void ColorsTab::reload() {
  mBackgroundColorButton->setPalette(QPalette(gSettings->backgroundColor()));
  mBackgroundColorForSlideshowButton->setPalette(
      QPalette(gSettings->backgroundColorForSlideshow()));
}

void ColorsTab::setup() {
  addLayout();
  addBackgroundColorPicker();
  addBackgroundColorPickerForSlideshow();
}

void ColorsTab::addBackgroundColorPicker() {
  mBackgroundColorLabel = new QLabel();
  mBackgroundColorLabel->setText("Background Color");

  mBackgroundColorButton = new QPushButton();
  mBackgroundColorButton->setAutoFillBackground(true);
  mBackgroundColorButton->setFlat(true);
  mBackgroundColorButton->setPalette(QPalette(gSettings->backgroundColor()));

  connect(mBackgroundColorButton,
          &QPushButton::clicked,
          this,
          &ColorsTab::pickBackgroundColor);

  mLayout->addWidget(mBackgroundColorLabel, 0, 0);
  mLayout->addWidget(mBackgroundColorButton, 0, 1);
}

void ColorsTab::addBackgroundColorPickerForSlideshow() {
  mBackgroundColorForSlideshowLabel = new QLabel();
  mBackgroundColorForSlideshowLabel->setText("Background Color - Slideshow");

  mBackgroundColorForSlideshowButton = new QPushButton();
  mBackgroundColorForSlideshowButton->setAutoFillBackground(true);
  mBackgroundColorForSlideshowButton->setFlat(true);
  mBackgroundColorForSlideshowButton->setPalette(
      QPalette(gSettings->backgroundColorForSlideshow()));

  connect(mBackgroundColorForSlideshowButton,
          &QPushButton::clicked,
          this,
          &ColorsTab::pickBackgroundColorForSlideshow);

  mLayout->addWidget(mBackgroundColorForSlideshowLabel, 1, 0);
  mLayout->addWidget(mBackgroundColorForSlideshowButton, 1, 1);
}

void ColorsTab::addLayout() {
  mLayout = new QGridLayout();
  mLayout->setAlignment(Qt::AlignTop);

  setLayout(mLayout);
}

void ColorsTab::pickBackgroundColor() {
  QColor color = QColorDialog::getColor();
  if (!color.isValid()) {
    return;
  }

  gSettings->setBackgroundColor(color);
  mBackgroundColorButton->setPalette(QPalette(color));
}

void ColorsTab::pickBackgroundColorForSlideshow() {
  QColor color = QColorDialog::getColor();
  if (!color.isValid()) {
    return;
  }

  gSettings->setBackgroundColorForSlideshow(color);
  mBackgroundColorForSlideshowButton->setPalette(QPalette(color));
}
