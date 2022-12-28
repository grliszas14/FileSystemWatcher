#ifndef WATCHEDPATHSMODEL_H
#define WATCHEDPATHSMODEL_H

#include <QAbstractListModel>
#include "watchedpath.h"

class WatchedPathsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    WatchedPathsModel(QObject * parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QList<WatchedPath> paths() const;

    enum {
        PathRole = Qt::UserRole,
        StatusRole
    };

    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void appendPath(const QString& path);
    void removePath(const int index);
    void clear();

private:
    QList<WatchedPath> m_paths;
};

#endif // WATCHEDPATHSMODEL_H
