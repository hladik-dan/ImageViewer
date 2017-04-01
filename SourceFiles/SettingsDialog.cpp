#include "SettingsDialog.h"

#include <QBoxLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QTabWidget>

#include "ColorsTab.h"
#include "ImageView.h"
#include "KeyboardTab.h"
#include "MenuBar.h"
#include "Settings.h"
#include "SlideshowTab.h"
#include "WindowTab.h"
#include "ZoomTab.h"

extern ImageView *gImageView;
extern MenuBar *gMenuBar;
extern Settings *gSettings;

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent) {
  setup();
}

SettingsDialog::~SettingsDialog() {
}

void SettingsDialog::setup() {
  setWindowTitle("Settings");
  setMinimumWidth(WIDTH_MIN);

  addLayout();
  addTabWidget();
  addButtonBox();
}

void SettingsDialog::addButtonBox() {
  mButtonBox = new QDialogButtonBox(this);
  mButtonBox->setStandardButtons(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

  connect(mButtonBox,
          &QDialogButtonBox::accepted,
          this,
          &QDialog::accept);
  connect(mButtonBox,
          &QDialogButtonBox::rejected,
          this,
          &QDialog::reject);

  mLayout->addWidget(mButtonBox);
}

void SettingsDialog::addLayout() {
  mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
  setLayout(mLayout);
}

void SettingsDialog::addTabWidget() {
  mTabWidget = new QTabWidget();
  mTabWidget->addTab(mColorsTab = new ColorsTab(), "Colors");
  mTabWidget->addTab(mKeyboardTab = new KeyboardTab(), "Keyboard");
  mTabWidget->addTab(mSlideshowTab = new SlideshowTab(), "Slideshow");
  mTabWidget->addTab(mWindowTab = new WindowTab(), "Window");
  mTabWidget->addTab(mZoomTab = new ZoomTab(), "Zoom");

  mLayout->addWidget(mTabWidget);
}

void SettingsDialog::accept() {
  if ((gSettings->autoZoom() == Settings::AutoZoom::FitToWindow
       || gSettings->autoZoom() == Settings::AutoZoom::FitBigToWindow)
      && gSettings->resize() != Settings::Resize::KeepSize) {

    QMessageBox messageBox;
    messageBox.setText("Invalid settings");
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.exec();

    return;
  }

  gSettings->save();

  gImageView->reload();
  gMenuBar->reload();

  QDialog::accept();
}

void SettingsDialog::reject() {
  gSettings->reload();
  mColorsTab->reload();
  mKeyboardTab->reload();
  mSlideshowTab->reload();
  mWindowTab->reload();
  mZoomTab->reload();

  QDialog::reject();
}
