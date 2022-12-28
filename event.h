#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>
#include "utils.h"

class Event
{
public:
    explicit Event(const FileState& fileState, const QString& path, bool isFolder, const QDateTime& timestamp);
    QString path() const noexcept;
    QString state() const noexcept;
    bool isDir() const noexcept;
    QDateTime timestamp() const noexcept;

private:
    QString m_path;
    FileState m_state{FileState::Unknown};
    bool m_isFolder;
    QDateTime m_timestamp;
};

#endif // EVENT_H
