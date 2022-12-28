#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractTableModel>
#include "event.h"

class EventModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    EventModel(QObject * parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum {
        TableDataRole = Qt::UserRole,
    };

    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void addEvent(const Event& event);
    void clear();

private:
    QVector<Event> m_events;
};

#endif // EVENTMODEL_H
