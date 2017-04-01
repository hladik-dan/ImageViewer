#ifndef IMAGEVIEWER_FILE_H
#define IMAGEVIEWER_FILE_H

#include <QDir>

class File : public QObject, public QDir {
  Q_OBJECT

public:
  File();
  ~File();

  int index();
  int size();
  QFileInfo currentFile();
  QFileInfo nextFile();
  QFileInfo previousFile();

  void setCurrentFile(QFileInfo fileInfo);
  void setCurrentFile(QString filePath);
  void setSorting(SortFlags sort);

private:
  void setup();

signals:
  void updated();

private:
  QFileInfo mCurrentFile;
};

#endif  // IMAGEVIEWER_FILE_H
