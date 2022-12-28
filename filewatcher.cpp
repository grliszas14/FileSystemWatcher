#include "filewatcher.h"
#include "event.h"
#include <QDir>
#include <QDateTime>

FileWatcher::FileWatcher(QObject *parent, WatchedPathsModel *model, EventModel *eventModel)
    : QObject{parent}, m_watchedPathsModel{model}, m_eventModel{eventModel}, m_watcher{QFileSystemWatcher(this)}
{}

QStringList FileWatcher::getCurrentPaths(QList<WatchedPath> watchedPaths)
{
    QStringList currentPaths;
    QList<WatchedPath> recursiveList;
    for (const auto& watchedPath : watchedPaths)
    {
        QDir watchedDir{watchedPath.path()};
        watchedDir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

        if (!watchedDir.exists())
        {
            continue;
        }

        if (!currentPaths.contains(watchedDir.absolutePath()))
        {
            currentPaths.append(watchedDir.absolutePath());
        }

        QFileInfoList fileList = watchedDir.entryInfoList();
        for (const auto& entry : fileList)
        {
            if (!currentPaths.contains(entry.filePath()))
            {
                currentPaths.append(entry.filePath());

                // recursive call
                if (entry.isDir() && entry.filePath() != watchedDir.absolutePath())
                {
                    recursiveList.append(WatchedPath(entry.filePath()));
                }
            }
        }
    }
    if (!recursiveList.isEmpty())
    {
        currentPaths.append(getCurrentPaths(recursiveList));
    }

    currentPaths.removeDuplicates();
    return currentPaths;
}

void FileWatcher::scan(QList<WatchedPath> watchedPaths)
{
    auto sortedPaths = getCurrentPaths(watchedPaths);
    std::sort(sortedPaths.begin(), sortedPaths.end());
    m_paths.append(sortedPaths);
}

void FileWatcher::start()
{
    scan(m_watchedPathsModel->paths());

    m_watcher.addPaths(m_paths);
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &FileWatcher::fileChanged);
    connect(&m_watcher, &QFileSystemWatcher::directoryChanged, this, &FileWatcher::dirChanged);
}

void FileWatcher::stop()
{
    disconnect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &FileWatcher::fileChanged);
    disconnect(&m_watcher, &QFileSystemWatcher::directoryChanged, this, &FileWatcher::dirChanged);
    m_watcher.removePaths(m_paths);
}

void FileWatcher::dirChanged(const QString &path)
{
    auto event = evaluateEvent(path, FileType::Directory);
    m_eventModel->addEvent(event);
}

void FileWatcher::fileChanged(const QString &path)
{
    auto event = evaluateEvent(path, FileType::File);
    m_eventModel->addEvent(event);
}

QString FileWatcher::substraction(QStringList biggerList, QStringList smallerList)
{
    for (auto i = 0; i < smallerList.size(); i++)
    {
        if (biggerList[i] == smallerList[i])
        {
            continue;
        }
        return biggerList[i];
    }
    return biggerList.last();
}

bool FileWatcher::compare(QStringList listA, QStringList listB) const
{
    for (auto i = 0; i < listA.size(); i++)
    {
        if (listA[i] == listB[i])
        {
            continue;
        }
        return false;
    }
    return true;
}

Event FileWatcher::evaluateEvent(const QString &eventPath, FileType type)
{
    m_paths.removeDuplicates();
    QStringList newList = getCurrentPaths(m_watchedPathsModel->paths());
    QStringList oldList = m_paths;
    std::sort(newList.begin(), newList.end());
    std::sort(oldList.begin(), oldList.end());

    m_paths = newList;
    stop();
    start();

    if (newList.size() > oldList.size())
    {
        auto newPath = substraction(newList, oldList);
        qDebug() << "Event: (Created, " << newPath << ", dir=" << static_cast<int>(type) << ", " << QDateTime::currentDateTime() << ")";
        return Event(FileState::Created, newPath, static_cast<bool>(type), QDateTime::currentDateTime());
    } else if (newList.size() < oldList.size())
    {
        auto newPath = substraction(oldList, newList);
        qDebug() << "Event: (Removed, " << newPath << ", dir=" << static_cast<int>(type) << ", " << QDateTime::currentDateTime() << ")";

        return Event(FileState::Removed, newPath, static_cast<bool>(type), QDateTime::currentDateTime());
    } else if (newList.size() == oldList.size())
    {
        if (compare(newList, oldList))
        {
            qDebug() << "Event: (Edited, " << eventPath << ", dir=" << static_cast<int>(type) << ", " << QDateTime::currentDateTime() << ")";
            return Event(FileState::Edited, eventPath, static_cast<bool>(type), QDateTime::currentDateTime());
        } else
        {
            auto newPath = substraction(newList, oldList);
            qDebug() << "Event: (Renamed, " << newPath << ", dir=" << static_cast<int>(type) << ", " << QDateTime::currentDateTime() << ")";
            return Event(FileState::Renamed, newPath, static_cast<bool>(type), QDateTime::currentDateTime());
        }
    }
}


