#ifndef INVENTORY_H
#define INVENTORY_H

#include <QAbstractListModel>
#include <QList>
#include "inventoryitem.h"

class Inventory : public QAbstractListModel {
    Q_OBJECT

public:
    void addItem(InventoryItem&& item);

    // Required overrides for QAbstractListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QList<InventoryItem> m_items;
};

#endif // INVENTORY_H
