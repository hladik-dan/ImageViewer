#include "Application.h"

#include <QTime>

#include "File.h"
#include "ImageView.h"
#include "MainWindow.h"
#include "MenuBar.h"
#include "Settings.h"
#include "SettingsDialog.h"
#include "StatusBar.h"
#include "ToolBar.h"

File *gFile;
ImageView *gImageView;
MainWindow *gMainWindow;
MenuBar *gMenuBar;
Settings *gSettings;
SettingsDialog *gSettingsDialog;
StatusBar *gStatusBar;
ToolBar *gToolBar;

Application::Application(int &argc, char **argv) : QApplication(argc, argv) {
  setup();

  gSettings = new Settings();
  gFile = new File();

  gMainWindow = new MainWindow();
  gImageView = new ImageView();
  gMenuBar = new MenuBar();
  gToolBar = new ToolBar();
  gStatusBar = new StatusBar();

  gSettingsDialog = new SettingsDialog(gMainWindow);

  gMainWindow->show();
  processArguments();
}

Application::~Application() {
  delete gMainWindow;
  delete gFile;
  delete gSettings;
}

int Application::run() {
  return exec();
}

void Application::setup() {
  setApplicationName("ImageViewer");
  setOrganizationName("ImageViewer");
}

void Application::processArguments() {
  QTime waitTime = QTime::currentTime().addMSecs(100);
  while (QTime::currentTime() < waitTime) {
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  }

  if (QApplication::arguments().size() < 2) {
    return;
  }

  gImageView->openImage(QApplication::arguments().at(1));
}
