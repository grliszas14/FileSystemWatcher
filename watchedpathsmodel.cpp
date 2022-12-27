#include "watchedpathsmodel.h"

WatchedPathsModel::WatchedPathsModel(QObject *parent)
{
//    populate();
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
//        return m_paths[index.row()].path();

    return QVariant();
}

void WatchedPathsModel::appendPath(const QString &path)
{
    beginResetModel();
    m_paths.append(WatchedPath(path));
    endResetModel();
}

void WatchedPathsModel::removePath(const QModelIndex &index)
{
    beginResetModel();
    m_paths.removeAt(index.row());
    endResetModel();
}

void WatchedPathsModel::clear()
{
    beginResetModel();
    m_paths.clear();
    endResetModel();
}

// test method to remove later
void WatchedPathsModel::populate()
{
    beginResetModel();
    m_paths.clear();
    m_paths.append(WatchedPath("/home/grliszas14/toWatch"));
    m_paths.append(WatchedPath("/home/grliszas14/toWatch2"));
    m_paths.append(WatchedPath("/home/grliszas14/toWatch3"));
    m_paths.append(WatchedPath("/home/grliszas14/toWatch4"));
    m_paths.append(WatchedPath("/home/grliszas14/toWatch5"));
    m_paths.append(WatchedPath("/home/grliszas14/toWatch6"));
    m_paths.append(WatchedPath("/home/grliszas14/toWatch7"));
    endResetModel();
}

QHash<int, QByteArray> WatchedPathsModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PathRole] = "path";
    names[StatusRole] = "status";

    return names;
}
