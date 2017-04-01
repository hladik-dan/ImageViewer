#ifndef IMAGEVIEWER_FILEMENU_H
#define IMAGEVIEWER_FILEMENU_H

#include <QMenu>

class FileMenu : public QMenu {
public:
  FileMenu();
  ~FileMenu();

private:
  void setup();
  void addCloseAction();
  void addOpenAction();
  void addQuitAction();
  void addSaveAsAction();

  void close();
  void open();
  void quit();
  void saveAs();

private:
  QAction *mCloseAction = nullptr;
  QAction *mOpenAction = nullptr;
  QAction *mQuitAction = nullptr;
  QAction *mSaveAsAction = nullptr;
};

#endif  // IMAGEVIEWER_FILEMENU_H
