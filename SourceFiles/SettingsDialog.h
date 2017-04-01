#ifndef IMAGEVIEWER_SETTINGSDIALOG_H
#define IMAGEVIEWER_SETTINGSDIALOG_H

#include <QDialog>

class ColorsTab;
class KeyboardTab;
class QBoxLayout;
class QDialogButtonBox;
class QTabWidget;
class SlideshowTab;
class WindowTab;
class ZoomTab;

class SettingsDialog : public QDialog {
public:
  SettingsDialog(QWidget *parent = Q_NULLPTR);
  ~SettingsDialog();

private:
  void setup();
  void addButtonBox();
  void addLayout();
  void addTabWidget();

  void accept();
  void reject();

private:
  const int WIDTH_MIN = 500;

  ColorsTab *mColorsTab = nullptr;
  KeyboardTab *mKeyboardTab = nullptr;
  QDialogButtonBox *mButtonBox = nullptr;
  QBoxLayout *mLayout = nullptr;
  QTabWidget *mTabWidget = nullptr;
  SlideshowTab *mSlideshowTab = nullptr;
  WindowTab *mWindowTab = nullptr;
  ZoomTab *mZoomTab = nullptr;
};

#endif  // IMAGEVIEWER_SETTINGSDIALOG_H
