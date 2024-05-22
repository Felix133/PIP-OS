#ifndef INVENTORY_H
#define INVENTORY_H

#include <QAbstractListModel>
#include <QJsonObject>

class InventoryItem : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)

public:
    explicit InventoryItem(const QString& name, QObject* parent = nullptr);
    QString name() const;
signals:
    void nameChanged();
private:
    QString m_name;
};

class Inventory : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Inventory(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void LoadFromFile();

private:
    QJsonValue m_rootObject;
    QList<InventoryItem*> m_items;
};

#endif // INVENTORY_H
