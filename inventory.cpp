#include <QFile>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "inventory.h"
#include "inventoryitem.h"


void Inventory::addItem(InventoryItem &&item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(std::move(item)); // Move the item into the list
    endInsertRows();
}

// Implement other required functions for QAbstractListModel
int Inventory::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant Inventory::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_items.size())
        return QVariant();

    const InventoryItem &item = m_items[index.row()];
    if (role == Qt::DisplayRole)
    {
        return item.name(); // Adjust according to the role
    }
    // Add other roles as needed
    return QVariant();
}

// Qt::ItemFlags Inventory::flags(const QModelIndex &index) const {
//     if (!index.isValid())
//         return Qt::NoItemFlags;
//     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
// }

// void Inventory::LoadFromFile(){
//     QFile file(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+".inventory.json");
//     qDebug() << "Opening file at" << file.fileName();
//     if(!file.open(QIODevice::ReadOnly)) {
//         qWarning() << "Inventory file open error";
//         return;
//     }

//     QJsonParseError parseError;
//     QByteArray content = file.readAll();
//     file.close();
//     QJsonDocument jsonDocument = QJsonDocument::fromJson(content, &parseError);

//     if (parseError.error != QJsonParseError::NoError) {
//         qWarning() << "Parse error while loading JSON inventory, at offset" << parseError.offset << ":" << parseError.errorString();
//         return;
//     }

//     QJsonObject jsonObject = jsonDocument.object();

//     if (jsonObject.contains("Inventory") && jsonObject["Inventory"].isObject()) {
//         this->m_rootObject = jsonObject["Inventory"];

//         QJsonObject invPages = jsonObject["Inventory"].toObject();

//         for (const QString& page : invPages.keys()) {
//             if (!invPages[page].isArray()) {
//                 continue;
//             }

//             QJsonArray items = invPages[page].toArray();
//             for (const QJsonValue& itemv : items) {
//                 if (!itemv.isObject()) {
//                     continue;
//                 }
//                 // QJsonObject i = ;
//                 // qDebug() << i.value("count").toInt() << "x " << i.value("text").toString() ;

//                 // addItem(InventoryItem(itemv.toObject()));
//                 // item->setCount(i.value("count").toInt(1));

//                 // m_items<<item;
//                 // m_items.append);
//             }
//         }
//     }
// }
