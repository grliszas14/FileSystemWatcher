#include "eventmodel.h"

EventModel::EventModel(QObject *parent)
{}

int EventModel::rowCount(const QModelIndex &parent) const
{
    return m_events.size();
}

int EventModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant EventModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role) {
    case TableDataRole:
        if (index.column() == 0)
        {
            return QVariant(m_events.at(index.row()).state());
        } else if (index.column() == 1)
        {
            return QVariant(m_events.at(index.row()).path());
        } else if (index.column() == 2)
        {
            return QVariant(m_events.at(index.row()).isDir());
        } else
        {
            return QVariant(m_events.at(index.row()).timestamp());
        }
    }

    return QVariant();
}

QHash<int, QByteArray> EventModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[TableDataRole] = "tabledata";

    return names;
}

void EventModel::addEvent(const Event &event)
{
    beginResetModel();
    m_events.append(event);
    endResetModel();
}

void EventModel::clear()
{
    beginResetModel();
    m_events.clear();
    endResetModel();
}
