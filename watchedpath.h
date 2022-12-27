#ifndef WATCHEDPATH_H
#define WATCHEDPATH_H

#include <QString>
#include "utils.h"

class WatchedPath
{
public:
    explicit WatchedPath(const QString& path);
    QString path() const;
    QString state() const;

private:
    QString m_path;
    FileState m_state{FileState::Unknown};
};

#endif // WATCHEDPATH_H
