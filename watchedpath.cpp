#include "watchedpath.h"

WatchedPath::WatchedPath(const QString& path)
{
    if (path.contains("file://"))
    {
        QString preparedPath = path;
        m_path = preparedPath.replace("file://", "");
    } else
    {
        m_path = path;
    }
}

QString WatchedPath::path() const
{
    return m_path;
}

QString WatchedPath::state() const
{
    switch(m_state) {
    case FileState::Created:
        return QStringLiteral("Created");
    case FileState::Removed:
        return QStringLiteral("Removed");
    case FileState::Edited:
        return QStringLiteral("Edited");
    case FileState::Renamed:
        return QStringLiteral("Renamed");
    default:
        return QStringLiteral("Unknown");
    }
}
