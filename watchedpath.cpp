#include "watchedpath.h"

WatchedPath::WatchedPath(const QString& path) : m_path{path}
{}

QString WatchedPath::path() const
{
    return m_path;
}

QString WatchedPath::state() const
{
    switch(m_state) {
    case FileState::Unknown:
        return QStringLiteral("Unknown");
    case FileState::Created:
        return QStringLiteral("Created");
    case FileState::Deleted:
        return QStringLiteral("Deleted");
    case FileState::Edited:
        return QStringLiteral("Edited");
    case FileState::Renamed:
        return QStringLiteral("Renamed");
    }

}
