#ifndef IMAGEVIEWER_STATUSBAR_H
#define IMAGEVIEWER_STATUSBAR_H

#include <QStatusBar>

class QLabel;

class StatusBar : public QStatusBar {
public:
  StatusBar();
  ~StatusBar();

private:
  void setup();
  void addFileInfo();
  void addPositionInfo();
  void addUpdateAction();

  void update();

private:
  QLabel *mFileInfo = nullptr;
  QLabel *mPositionInfo = nullptr;
};

#endif  // IMAGEVIEWER_STATUSBAR_H
