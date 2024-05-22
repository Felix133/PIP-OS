#include "inventory.h"
#include <QFile>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QString InventoryItem::name() const
{
    return m_name;
}

Inventory::Inventory(QObject *parent) : QAbstractListModel(parent) {}

int Inventory::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0; // No children for valid parent indices
    return m_items.size();
}

QVariant Inventory::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        // Return the name property of the custom object
        return m_items.at(index.row())->name();
    }

    return QVariant();
}

QHash<int, QByteArray> Inventory::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "displayRole"; // Role name for QML
    return roles;
}

void Inventory::LoadFromFile(){
    QFile file(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+".inventory.json");
    qDebug() << "Opening file at" << file.fileName();
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Inventory file open error";
        return;
    }

    QJsonParseError parseError;
    QByteArray content = file.readAll();
    file.close();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(content, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error while loading JSON inventory, at offset" << parseError.offset << ":" << parseError.errorString();
        return;
    }

    QJsonObject jsonObject = jsonDocument.object();

    if (jsonObject.contains("Inventory") && jsonObject["Inventory"].isObject()) {
        this->m_rootObject = jsonObject["Inventory"];

        QJsonObject invPages = jsonObject["Inventory"].toObject();

        for (const QString& page : invPages.keys()) {
            if (!invPages[page].isArray()) {
                continue;
            }

            QJsonArray items = invPages[page].toArray();
            for (const QJsonValue& itemv : items) {
                if (!itemv.isObject()) {
                    continue;
                }
                QJsonObject item = itemv.toObject();
                qDebug() << item.value("count").toInt() << "x " << item.value("text").toString() ;

                // TODO: Idk what I'm doing wrong here
                QString itemName = item.value("text").toString();
                m_items.append(new InventoryItem(itemName));
            }
        }
    }
}


