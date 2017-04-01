#ifndef IMAGEVIEWER_MENUBAR_H
#define IMAGEVIEWER_MENUBAR_H

#include <QMenuBar>

class EditMenu;
class FileMenu;
class GoMenu;
class ViewMenu;

class MenuBar : public QMenuBar {
public:
  MenuBar();
  ~MenuBar();

  void reload();

  EditMenu *editMenu();
  FileMenu *fileMenu();
  GoMenu *goMenu();
  ViewMenu *viewMenu();

private:
  void setup();

private:
  EditMenu *mEditMenu;
  FileMenu *mFileMenu;
  GoMenu *mGoMenu;
  ViewMenu *mViewMenu;
};

#endif  // IMAGEVIEWER_MENUBAR_H
