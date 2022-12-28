#include "event.h"

Event::Event(const FileState &fileState, const QString &path, bool isFolder, const QDateTime &timestamp)
    : m_state{fileState}, m_path{path}, m_isFolder{isFolder}, m_timestamp{timestamp}
{}

QString Event::path() const
{
    return m_path;
}

QString Event::state() const
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

bool Event::isDir() const
{
    return m_isFolder;
}

QDateTime Event::timestamp() const
{
    return m_timestamp;
}
