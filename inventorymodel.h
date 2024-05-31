#pragma once

#include <QAbstractListModel>
#include <QJsonArray>
#include <QJsonObject>
#include <vector>
#include "inventoryitem.h"

class InventoryModel : public QAbstractListModel
{
  Q_OBJECT

public:
  InventoryModel(QObject *parent = nullptr);

  void addItems(const QJsonArray &jsonArray);
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
  QHash<int, QByteArray> roleNames() const override;

private:
  std::vector<InventoryItem> m_items;
};
