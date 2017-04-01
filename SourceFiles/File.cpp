#include "File.h"

#include "Settings.h"

extern Settings *gSettings;

File::File() {
  setup();
}

File::~File() {
}

int File::index() {
  return entryInfoList().indexOf(mCurrentFile);
}

int File::size() {
  return entryInfoList().size();
}

QFileInfo File::currentFile() {
  return mCurrentFile;
}

QFileInfo File::nextFile() {
  if (index() + 1 >= size()) {
    return QFileInfo();
  }

  setCurrentFile(entryInfoList().at(index() + 1));

  return mCurrentFile;
}

QFileInfo File::previousFile() {
  if (index() - 1 < 0) {
    return QFileInfo();
  }

  setCurrentFile(entryInfoList().at(index() - 1));

  return mCurrentFile;
}

void File::setCurrentFile(QFileInfo fileInfo) {
  setCurrentFile(fileInfo.absoluteFilePath());
}

void File::setCurrentFile(QString filePath) {
  if (filePath.isNull()) {
    mCurrentFile = QFileInfo(QString());
    setPath(QString());
    return;
  }

  mCurrentFile = QFileInfo(filePath);
  setPath(mCurrentFile.absolutePath());
}

void File::setSorting(QDir::SortFlags sort) {
  if (gSettings->sortOrder() == Settings::SortOrder::Descending) {
    sort |= QDir::Reversed;
  }

  QDir::setSorting(sort);

  emit updated();
}

void File::setup() {
  setFilter(QDir::Files | QDir::NoDotAndDotDot);
  setNameFilters(QStringList({"*.bmp", "*.jpg", "*.png"}));

  if (gSettings->sortBy() == Settings::SortBy::Date) {
    setSorting(QDir::Time);
  } else if (gSettings->sortBy() == Settings::SortBy::FileName) {
    setSorting(QDir::Name);
  }
}
