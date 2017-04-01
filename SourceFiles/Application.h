#ifndef IMAGEVIEWER_APPLICATION_H
#define IMAGEVIEWER_APPLICATION_H

#include <QApplication>

class Application : public QApplication {
public:
  Application(int &argc, char **argv);
  ~Application();

  int run();

private:
  void setup();
  void processArguments();

private:
};

#endif  // IMAGEVIEWER_APPLICATION_H
