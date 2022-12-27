#include "event.h"

Event::Event(const QString &path, const FileState &fileState, bool isFolder, const QDateTime &timestamp)
    : m_path{path}, m_state{fileState}, m_isFolder{isFolder}, m_timestamp{timestamp}
{

}
