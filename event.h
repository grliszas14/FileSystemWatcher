#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>
#include "utils.h"

class Event
{
public:
    explicit Event(const FileState& fileState, const QString& path, bool isFolder, const QDateTime& timestamp);
    QString path() const;
    QString state() const;
    bool isDir() const;
    QDateTime timestamp() const;

private:
    QString m_path;
    FileState m_state{FileState::Unknown};
    bool m_isFolder;
    QDateTime m_timestamp;
};

#endif // EVENT_H
