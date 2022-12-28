#include "watchedpathsmodel.h"

WatchedPathsModel::WatchedPathsModel(QObject *parent)
{
}

int WatchedPathsModel::rowCount(const QModelIndex& parent) const
{
    return m_paths.size();
}

QVariant WatchedPathsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role) {
    case PathRole:
        return QVariant(m_paths.at(index.row()).path());
    case StatusRole:
        return QVariant(m_paths.at(index.row()).state());
    }

    return QVariant();
}

void WatchedPathsModel::appendPath(const QString &path)
{
    beginResetModel();
    m_paths.append(WatchedPath(path));
    endResetModel();
}

void WatchedPathsModel::removePath(const int index)
{
    beginResetModel();
    m_paths.removeAt(index);
    endResetModel();
}

void WatchedPathsModel::clear()
{
    beginResetModel();
    m_paths.clear();
    endResetModel();
}

QList<WatchedPath> WatchedPathsModel::paths() const
{
    return m_paths;
}

QHash<int, QByteArray> WatchedPathsModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PathRole] = "path";
    names[StatusRole] = "status";

    return names;
}
