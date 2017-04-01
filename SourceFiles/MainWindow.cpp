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

void MainWindow::resize(int w, int h) {
  installEventFilter(this);
  QWidget::resize(w, h);
  removeEventFilter(this);
}

void MainWindow::setup() {
  resize(WIDTH, HEIGHT);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::Resize) {
    return true;
  }

  return QObject::eventFilter(object, event);
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
