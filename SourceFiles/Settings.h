#ifndef IMAGEVIEWER_SETTINGS_H
#define IMAGEVIEWER_SETTINGS_H

#include <QColor>
#include <QKeySequence>
#include <QSettings>

class Settings : public QSettings {
public:
  Settings();
  ~Settings();

  enum AutoZoom {
    FitToWindow,
    FitBigToWindow,
    FitToDesktop,
    FitBigToDesktop,
    FitToCustom,
    FitBigToCustom
  };
  enum Resize { KeepSize, FitToImage, FitToBigImage };
  enum SortBy { Date, FileName };
  enum SortOrder { Ascending, Descending };

  void load();
  void reload();
  void save();

  bool enableAutoZoom();
  bool enableZoomOnResize();
  bool showMenuBar();
  bool showStatusBar();
  bool showToolBar();

  int fitBigToCustomHeight();
  int fitBigToCustomWidth();
  int fitToCustomHeight();
  int fitToCustomWidth();
  int slideshowInterval();
  int zoomStep();

  AutoZoom autoZoom();
  Resize resize();
  SortBy sortBy();
  SortOrder sortOrder();

  QKeySequence closeKey();
  QKeySequence copyToFolder1Key();
  QKeySequence copyToFolder2Key();
  QKeySequence copyToFolder3Key();
  QKeySequence copyToFolder4Key();
  QKeySequence copyToFolder5Key();
  QKeySequence fitToCustomKey();
  QKeySequence fitToWindowKey();
  QKeySequence fullscreenKey();
  QKeySequence moveToFolder1Key();
  QKeySequence moveToFolder2Key();
  QKeySequence moveToFolder3Key();
  QKeySequence moveToFolder4Key();
  QKeySequence moveToFolder5Key();
  QKeySequence nextKey();
  QKeySequence openKey();
  QKeySequence originalSizeKey();
  QKeySequence previousKey();
  QKeySequence quitKey();
  QKeySequence saveAsKey();
  QKeySequence showMenuBarKey();
  QKeySequence showStatusBarKey();
  QKeySequence showToolBarKey();
  QKeySequence toggleSlideshowKey();
  QKeySequence zoomInKey();
  QKeySequence zoomOutKey();

  QColor backgroundColor();
  QColor backgroundColorForSlideshow();

  QString folderPath1();
  QString folderPath2();
  QString folderPath3();
  QString folderPath4();
  QString folderPath5();

  void setEnableAutoZoom(bool value);
  void setEnableZoomOnResize(bool value);
  void setShowMenuBar(bool value);
  void setShowStatusBar(bool value);
  void setShowToolBar(bool value);

  void setFitBigToCustomHeight(int value);
  void setFitBigToCustomWidth(int value);
  void setFitToCustomHeight(int value);
  void setFitToCustomWidth(int value);
  void setSlideshowInterval(int value);
  void setZoomStep(int value);

  void setCopyToFolder1Key(QKeySequence value);
  void setCopyToFolder2Key(QKeySequence value);
  void setCopyToFolder3Key(QKeySequence value);
  void setCopyToFolder4Key(QKeySequence value);
  void setCopyToFolder5Key(QKeySequence value);
  void setFitToCustomKey(QKeySequence value);
  void setFitToWindowKey(QKeySequence value);
  void setFullscreenKey(QKeySequence value);
  void setMoveToFolder1Key(QKeySequence value);
  void setMoveToFolder2Key(QKeySequence value);
  void setMoveToFolder3Key(QKeySequence value);
  void setMoveToFolder4Key(QKeySequence value);
  void setMoveToFolder5Key(QKeySequence value);
  void setNextKey(QKeySequence value);
  void setOriginalSizeKey(QKeySequence value);
  void setPreviousKey(QKeySequence value);
  void setToggleSlideshowKey(QKeySequence value);
  void setZoomInKey(QKeySequence value);
  void setZoomOutKey(QKeySequence value);

  void setAutoZoom(AutoZoom value);
  void setResize(Resize value);
  void setSortBy(SortBy value);
  void setSortOrder(SortOrder value);

  void setBackgroundColor(QColor value);
  void setBackgroundColorForSlideshow(QColor value);

  void setFolderPath1(QString value);
  void setFolderPath2(QString value);
  void setFolderPath3(QString value);
  void setFolderPath4(QString value);
  void setFolderPath5(QString value);

private:
  bool mEnableAutoZoom;
  bool mEnableZoomOnResize;
  bool mShowMenuBar;
  bool mShowStatusBar;
  bool mShowToolBar;

  int mFitBigToCustomHeight;
  int mFitBigToCustomWidth;
  int mFitToCustomHeight;
  int mFitToCustomWidth;
  int mSlideshowInterval;
  int mZoomStep;

  AutoZoom mAutoZoom;
  Resize mResize;
  SortBy mSortBy;
  SortOrder mSortOrder;

  QKeySequence mCloseKey;
  QKeySequence mCopyToFolder1Key;
  QKeySequence mCopyToFolder2Key;
  QKeySequence mCopyToFolder3Key;
  QKeySequence mCopyToFolder4Key;
  QKeySequence mCopyToFolder5Key;
  QKeySequence mFitToCustomKey;
  QKeySequence mFitToWindowKey;
  QKeySequence mFullscreenKey;
  QKeySequence mMoveToFolder1Key;
  QKeySequence mMoveToFolder2Key;
  QKeySequence mMoveToFolder3Key;
  QKeySequence mMoveToFolder4Key;
  QKeySequence mMoveToFolder5Key;
  QKeySequence mNextKey;
  QKeySequence mOpenKey;
  QKeySequence mOriginalSizeKey;
  QKeySequence mPreviousKey;
  QKeySequence mQuitKey;
  QKeySequence mSaveAsKey;
  QKeySequence mShowMenuBarKey;
  QKeySequence mShowStatusBarKey;
  QKeySequence mShowToolBarKey;
  QKeySequence mToggleSlideshowKey;
  QKeySequence mZoomInKey;
  QKeySequence mZoomOutKey;

  QColor mBackgroundColor;
  QColor mBackgroundColorForSlideshow;

  QString mFolderPath1;
  QString mFolderPath2;
  QString mFolderPath3;
  QString mFolderPath4;
  QString mFolderPath5;
};

#endif  // IMAGEVIEWER_SETTINGS_H
