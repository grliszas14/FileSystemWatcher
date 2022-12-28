#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include "eventmodel.h"
#include "watchedpath.h"
#include "watchedpathsmodel.h"
#include "event.h"
#include <QFileSystemWatcher>

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    FileWatcher(QObject *parent = nullptr, WatchedPathsModel *model = nullptr, EventModel *eventModel = nullptr);
    QStringList getCurrentPaths(QList<WatchedPath> paths);
    void scan(const QList<WatchedPath>& paths);
    QString substraction(const QStringList& biggerList, const QStringList& smallerList);
    bool compare(const QStringList& listA, const QStringList& listB) const;
    Event evaluateEvent(const QString& eventPath, FileType type);

public slots:
    void start();
    void stop();
    void dirChanged(const QString &path);
    void fileChanged(const QString &path);

private:
    QFileSystemWatcher m_watcher;
    QStringList m_paths;
    WatchedPathsModel *m_watchedPathsModel;
    EventModel * m_eventModel;
};

#endif // FILEWATCHER_H
