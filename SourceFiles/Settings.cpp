#include "Settings.h"

Settings::Settings() {
  load();
}

Settings::~Settings() {
}

void Settings::load() {
  mEnableAutoZoom = value("enableAutoZoom", true).toBool();
  mEnableZoomOnResize = value("enableZoomOnResize", true).toBool();
  mShowMenuBar = value("showMenuBar", true).toBool();
  mShowStatusBar = value("showStatusBar", true).toBool();
  mShowToolBar = value("showToolBar", true).toBool();

  mFitBigToCustomHeight = value("fitToCustomHeight", 480).toInt();
  mFitBigToCustomWidth = value("fitToCustomWidth", 640).toInt();
  mFitToCustomHeight = value("fitToCustomHeight", 480).toInt();
  mFitToCustomWidth = value("fitToCustomWidth", 640).toInt();
  mSlideshowInterval = value("slideshowInterval", 5).toInt();
  mZoomStep = value("zoomStep", 25).toInt();

  mAutoZoom =
      static_cast<AutoZoom>(value("autoZoom", AutoZoom ::FitToWindow).toUInt());
  mResize = static_cast<Resize>(value("resize", Resize::KeepSize).toUInt());
  mSortBy = static_cast<SortBy>(value("sortBy", SortBy::FileName).toUInt());
  mSortOrder =
      static_cast<SortOrder>(value("sortOrder", SortOrder::Ascending).toUInt());

  mCloseKey = QKeySequence(value("closeKey", "CTRL+W").toString());
  mCopyToFolder1Key =
      QKeySequence(value("copyToFolder1Key", "CTRL+ALT+1").toString());
  mCopyToFolder2Key =
      QKeySequence(value("copyToFolder2Key", "CTRL+ALT+2").toString());
  mCopyToFolder3Key =
      QKeySequence(value("copyToFolder3Key", "CTRL+ALT+3").toString());
  mCopyToFolder4Key =
      QKeySequence(value("copyToFolder4Key", "CTRL+ALT+4").toString());
  mCopyToFolder5Key =
      QKeySequence(value("copyToFolder5Key", "CTRL+ALT+5").toString());
  mFitToCustomKey = QKeySequence(value("fitToCustomKey", "CTRL+2").toString());
  mFitToWindowKey =
      QKeySequence(value("fitToWindowKey", "CTRL+1").toString());
  mFullscreenKey = QKeySequence(value("fullscreenKey", "F11").toString());
  mMoveToFolder1Key =
      QKeySequence(value("moveToFolder1Key", "CTRL+SHIFT+1").toString());
  mMoveToFolder2Key =
      QKeySequence(value("moveToFolder2Key", "CTRL+SHIFT+2").toString());
  mMoveToFolder3Key =
      QKeySequence(value("moveToFolder3Key", "CTRL+SHIFT+3").toString());
  mMoveToFolder4Key =
      QKeySequence(value("moveToFolder4Key", "CTRL+SHIFT+4").toString());
  mMoveToFolder5Key =
      QKeySequence(value("moveToFolder5Key", "CTRL+SHIFT+5").toString());
  mNextKey = QKeySequence(value("nextKey", "Right").toString());
  mOpenKey = QKeySequence(value("openKey", "CTRL+O").toString());
  mOriginalSizeKey =
      QKeySequence(value("originalSizeKey", "CTRL+0").toString());
  mPreviousKey = QKeySequence(value("previousKey", "Left").toString());
  mQuitKey = QKeySequence(value("quitKey", "CTRL+Q").toString());
  mSaveAsKey = QKeySequence(value("saveAsKey", "CTRL+S").toString());
  mShowMenuBarKey =
      QKeySequence(value("showMenuBarKey", "CTRL+SHIFT+M").toString());
  mShowStatusBarKey =
      QKeySequence(value("showStatusBarKey", "CTRL+SHIFT+S").toString());
  mShowToolBarKey =
      QKeySequence(value("showToolBarKey", "CTRL+SHIFT+T").toString());
  mToggleSlideshowKey = QKeySequence(value("toggleSlideshow", "F5").toString());
  mZoomInKey = QKeySequence(value("zoomInKey", "CTRL++").toString());
  mZoomOutKey = QKeySequence(value("zoomOutKey", "CTRL+-").toString());

  mBackgroundColor = QColor(value("backgroundColor", "#ffffff").toString());
  mBackgroundColorForSlideshow =
      QColor(value("backgroundColorForSlideshow", "#ffffff").toString());

  mFolderPath1 = value("folderPath1", "").toString();
  mFolderPath2 = value("folderPath2", "").toString();
  mFolderPath3 = value("folderPath3", "").toString();
  mFolderPath4 = value("folderPath4", "").toString();
  mFolderPath5 = value("folderPath5", "").toString();
}

void Settings::reload() {
  load();
}

void Settings::save() {
  setValue("enableAutoZoom", mEnableAutoZoom);
  setValue("enableZoomOnResize", mEnableZoomOnResize);
  setValue("showMenuBar", mShowMenuBar);
  setValue("showStatusBar", mShowStatusBar);
  setValue("showToolBar", mShowToolBar);

  setValue("fitBigToCustomHeight", mFitBigToCustomHeight);
  setValue("fitBigToCustomWidth", mFitBigToCustomWidth);
  setValue("fitToCustomHeight", mFitToCustomHeight);
  setValue("fitToCustomWidth", mFitToCustomWidth);
  setValue("slideshowInterval", mSlideshowInterval);
  setValue("zoomStep", mZoomStep);

  setValue("copyToFolder1Key", mCopyToFolder1Key);
  setValue("copyToFolder2Key", mCopyToFolder2Key);
  setValue("copyToFolder3Key", mCopyToFolder3Key);
  setValue("copyToFolder4Key", mCopyToFolder4Key);
  setValue("copyToFolder5Key", mCopyToFolder5Key);
  setValue("fitToCustomKey", mFitToCustomKey);
  setValue("fitToWindowKey", mFitToWindowKey);
  setValue("fullscreenKey", mFullscreenKey);
  setValue("moveToFolder1Key", mMoveToFolder1Key);
  setValue("moveToFolder2Key", mMoveToFolder2Key);
  setValue("moveToFolder3Key", mMoveToFolder3Key);
  setValue("moveToFolder4Key", mMoveToFolder4Key);
  setValue("moveToFolder5Key", mMoveToFolder5Key);
  setValue("nextKey", mNextKey);
  setValue("originalSizeKey", mOriginalSizeKey);
  setValue("previousKey", mPreviousKey);
  setValue("toggleSlideshowKey", mToggleSlideshowKey);
  setValue("zoomInKey", mZoomInKey);
  setValue("zoomOutKey", mZoomOutKey);

  setValue("autoZoom", mAutoZoom);
  setValue("resize", mResize);
  setValue("sortBy", mSortBy);
  setValue("sortOrder", mSortOrder);

  setValue("backgroundColor", mBackgroundColor);
  setValue("backgroundColorForSlideshow", mBackgroundColorForSlideshow);

  setValue("folderPath1", mFolderPath1);
  setValue("folderPath2", mFolderPath2);
  setValue("folderPath3", mFolderPath3);
  setValue("folderPath4", mFolderPath4);
  setValue("folderPath5", mFolderPath5);
}

bool Settings::enableAutoZoom() {
  return mEnableAutoZoom;
}

bool Settings::enableZoomOnResize() {
  return mEnableZoomOnResize;
}

bool Settings::showMenuBar() {
  return mShowMenuBar;
}

bool Settings::showStatusBar() {
  return mShowStatusBar;
}

bool Settings::showToolBar() {
  return mShowToolBar;
}

int Settings::fitBigToCustomHeight() {
  return mFitBigToCustomHeight;
}

int Settings::fitBigToCustomWidth() {
  return mFitToCustomWidth;
}

int Settings::fitToCustomHeight() {
  return mFitToCustomHeight;
}

int Settings::fitToCustomWidth() {
  return mFitToCustomWidth;
}

int Settings::slideshowInterval() {
  return mSlideshowInterval;
}

int Settings::zoomStep() {
  return mZoomStep;
}

Settings::AutoZoom Settings::autoZoom() {
  return mAutoZoom;
}

Settings::Resize Settings::resize() {
  return mResize;
}

Settings::SortBy Settings::sortBy() {
  return mSortBy;
}

Settings::SortOrder Settings::sortOrder() {
  return mSortOrder;
}

QKeySequence Settings::closeKey() {
  return mCloseKey;
}

QKeySequence Settings::copyToFolder1Key() {
  return mCopyToFolder1Key;
}

QKeySequence Settings::copyToFolder2Key() {
  return mCopyToFolder2Key;
}

QKeySequence Settings::copyToFolder3Key() {
  return mCopyToFolder3Key;
}

QKeySequence Settings::copyToFolder4Key() {
  return mCopyToFolder4Key;
}

QKeySequence Settings::copyToFolder5Key() {
  return mCopyToFolder5Key;
}

QKeySequence Settings::fitToCustomKey() {
  return mFitToCustomKey;
}

QKeySequence Settings::fitToWindowKey() {
  return mFitToWindowKey;
}

QKeySequence Settings::fullscreenKey() {
  return mFullscreenKey;
}

QKeySequence Settings::moveToFolder1Key() {
  return mMoveToFolder1Key;
}

QKeySequence Settings::moveToFolder2Key() {
  return mMoveToFolder2Key;
}

QKeySequence Settings::moveToFolder3Key() {
  return mMoveToFolder3Key;
}

QKeySequence Settings::moveToFolder4Key() {
  return mMoveToFolder4Key;
}

QKeySequence Settings::moveToFolder5Key() {
  return mMoveToFolder5Key;
}

QKeySequence Settings::nextKey() {
  return mNextKey;
}

QKeySequence Settings::openKey() {
  return mOpenKey;
}

QKeySequence Settings::originalSizeKey() {
  return mOriginalSizeKey;
}

QKeySequence Settings::previousKey() {
  return mPreviousKey;
}

QKeySequence Settings::quitKey() {
  return mQuitKey;
}

QKeySequence Settings::saveAsKey() {
  return mSaveAsKey;
}

QKeySequence Settings::showMenuBarKey() {
  return mShowMenuBarKey;
}

QKeySequence Settings::showStatusBarKey() {
  return mShowStatusBarKey;
}

QKeySequence Settings::showToolBarKey() {
  return mShowToolBarKey;
}

QKeySequence Settings::toggleSlideshowKey() {
  return mToggleSlideshowKey;
}

QKeySequence Settings::zoomInKey() {
  return mZoomInKey;
}

QKeySequence Settings::zoomOutKey() {
  return mZoomOutKey;
}

QColor Settings::backgroundColor() {
  return mBackgroundColor;
}

QColor Settings::backgroundColorForSlideshow() {
  return mBackgroundColorForSlideshow;
}

QString Settings::folderPath1() {
  return mFolderPath1;
}

QString Settings::folderPath2() {
  return mFolderPath2;
}

QString Settings::folderPath3() {
  return mFolderPath3;
}

QString Settings::folderPath4() {
  return mFolderPath4;
}

QString Settings::folderPath5() {
  return mFolderPath5;
}

void Settings::setEnableAutoZoom(bool value) {
  mEnableAutoZoom = value;
}

void Settings::setEnableZoomOnResize(bool value) {
  mEnableZoomOnResize = value;
}

void Settings::setShowMenuBar(bool value) {
  mShowMenuBar = value;
}

void Settings::setShowStatusBar(bool value) {
  mShowStatusBar = value;
}

void Settings::setShowToolBar(bool value) {
  mShowToolBar = value;
}

void Settings::setFitBigToCustomHeight(int value) {
  mFitBigToCustomHeight = value;
}

void Settings::setFitBigToCustomWidth(int value) {
  mFitToCustomWidth = value;
}

void Settings::setFitToCustomHeight(int value) {
  mFitToCustomHeight = value;
}

void Settings::setFitToCustomWidth(int value) {
  mFitToCustomWidth = value;
}

void Settings::setSlideshowInterval(int value) {
  mSlideshowInterval = value;
}

void Settings::setZoomStep(int value) {
  mZoomStep = value;
}

void Settings::setCopyToFolder1Key(QKeySequence value) {
  mCopyToFolder1Key = value;
}

void Settings::setCopyToFolder2Key(QKeySequence value) {
  mCopyToFolder2Key = value;
}

void Settings::setCopyToFolder3Key(QKeySequence value) {
  mCopyToFolder3Key = value;
}

void Settings::setCopyToFolder4Key(QKeySequence value) {
  mCopyToFolder4Key = value;
}

void Settings::setCopyToFolder5Key(QKeySequence value) {
  mCopyToFolder5Key = value;
}

void Settings::setFitToCustomKey(QKeySequence value) {
  mFitToCustomKey = value;
}

void Settings::setFitToWindowKey(QKeySequence value) {
  mFitToWindowKey = value;
}

void Settings::setFullscreenKey(QKeySequence value) {
  mFullscreenKey = value;
}

void Settings::setMoveToFolder1Key(QKeySequence value) {
}

void Settings::setMoveToFolder2Key(QKeySequence value) {
}

void Settings::setMoveToFolder3Key(QKeySequence value) {
}

void Settings::setMoveToFolder4Key(QKeySequence value) {
}

void Settings::setMoveToFolder5Key(QKeySequence value) {
}

void Settings::setNextKey(QKeySequence value) {
  mNextKey = value;
}

void Settings::setOriginalSizeKey(QKeySequence value) {
  mOriginalSizeKey = value;
}

void Settings::setPreviousKey(QKeySequence value) {
  mPreviousKey = value;
}

void Settings::setToggleSlideshowKey(QKeySequence value) {
  mToggleSlideshowKey = value;
}

void Settings::setZoomInKey(QKeySequence value) {
  mZoomInKey = value;
}

void Settings::setZoomOutKey(QKeySequence value) {
  mZoomOutKey = value;
}

void Settings::setAutoZoom(Settings::AutoZoom value) {
  mAutoZoom = value;
}

void Settings::setResize(Settings::Resize value) {
  mResize = value;
}

void Settings::setSortBy(Settings::SortBy value) {
  mSortBy = value;
}

void Settings::setSortOrder(Settings::SortOrder value) {
  mSortOrder = value;
}

void Settings::setBackgroundColor(QColor value) {
  mBackgroundColor = value;
}

void Settings::setBackgroundColorForSlideshow(QColor value) {
  mBackgroundColorForSlideshow = value;
}

void Settings::setFolderPath1(QString value) {
  mFolderPath1 = value;
}

void Settings::setFolderPath2(QString value) {
  mFolderPath2 = value;
}

void Settings::setFolderPath3(QString value) {
  mFolderPath3 = value;
}

void Settings::setFolderPath4(QString value) {
  mFolderPath4 = value;
}

void Settings::setFolderPath5(QString value) {
  mFolderPath5 = value;
}
