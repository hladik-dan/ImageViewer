#ifndef IMAGEVIEWER_GOMENU_H
#define IMAGEVIEWER_GOMENU_H

#include <QMenu>

class GoMenu : public QMenu {
public:
  GoMenu();
  ~GoMenu();

  void reload();

private:
  void setup();
  void addNextAction();
  void addPreviousAction();
  void addToggleSlideshowAction();

  void next();
  void previous();
  void toggleSlideshow();

private:
  QAction *mNextAction = nullptr;
  QAction *mPreviousAction = nullptr;
  QAction *mToggleSlideshowAction = nullptr;
};

#endif  // IMAGEVIEWER_GOMENU_H
