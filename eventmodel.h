#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include "qabstractitemmodel.h"

class EventModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    EventModel(QObject * parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole );
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole);

private:
//    QVector<Event> m_events;
};

#endif // EVENTMODEL_H
