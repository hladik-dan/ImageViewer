#include "MainWindow.h"

#include "ImageView.h"
#include "Settings.h"

extern ImageView *gImageView;
extern Settings *gSettings;

MainWindow::MainWindow() {
  setup();
}

MainWindow::~MainWindow() {
}

void MainWindow::setup() {
  resize(WIDTH, HEIGHT);
}

void MainWindow::closeEvent(QCloseEvent *event) {
  gSettings->save();
  QWidget::closeEvent(event);
}
void MainWindow::resizeEvent(QResizeEvent *event) {
  if (gSettings->enableZoomOnResize()) {
    gImageView->fitToWindow();
  }

  QWidget::resizeEvent(event);
}
