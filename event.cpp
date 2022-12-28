#include "event.h"

Event::Event(const FileState &fileState, const QString &path, bool isFolder, const QDateTime &timestamp)
    : m_state{fileState}, m_path{path}, m_isFolder{isFolder}, m_timestamp{timestamp}
{}

QString Event::path() const noexcept
{
    return m_path;
}

QString Event::state() const noexcept
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

bool Event::isDir() const noexcept
{
    return m_isFolder;
}

QDateTime Event::timestamp() const noexcept
{
    return m_timestamp;
}
