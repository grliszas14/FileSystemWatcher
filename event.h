#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>
#include "utils.h"

class Event
{
public:
    explicit Event(const QString& path, const FileState& fileState, bool isFolder, const QDateTime& timestamp);

private:
    QString m_path;
    FileState m_state{FileState::Unknown};
    bool m_isFolder;
    QDateTime m_timestamp;
};

#endif // EVENT_H
