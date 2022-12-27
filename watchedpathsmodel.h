#ifndef WATCHEDPATHSMODEL_H
#define WATCHEDPATHSMODEL_H

#include <QAbstractListModel>
#include "watchedpath.h"

class WatchedPathsModel : public QAbstractListModel
{
    Q_OBJECT
//    Q_PROPERTY(QList<WatchedPath> paths READ paths WRITE setPaths NOTIFY pathsChanged)

public:
    WatchedPathsModel(QObject * parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void populate(); // test method to remove later

    enum {
        PathRole = Qt::UserRole,
        StatusRole
    };

    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void appendPath(const QString& path);
    void removePath(const QModelIndex &index);
    void clear();

private:
    QList<WatchedPath> m_paths;
};

#endif // WATCHEDPATHSMODEL_H
