#ifndef IMAGEVIEWER_MAINWINDOW_H
#define IMAGEVIEWER_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
public:
  MainWindow();
  ~MainWindow();

  void resize(int w, int h);

private:
  void setup();

  bool eventFilter(QObject *object, QEvent *event);
  void closeEvent(QCloseEvent *event);
  void resizeEvent(QResizeEvent *event);

private:
  const int WIDTH = 640;
  const int HEIGHT = 480;
};

#endif  // IMAGEVIEWER_MAINWINDOW_H
