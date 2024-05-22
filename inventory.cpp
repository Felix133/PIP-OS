#include "inventory.h"
#include <QFile>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>

Inventory::Inventory(QObject *parent)
    : QObject{parent}
{}

void Inventory::LoadFromFile(){
    QFile file(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+".test.json");
    // QFile file(QStandardPaths::AppDataLocation + ".test.json");

    qDebug() << "Opening file at" << file.fileName();
    if(!file.open(stderr, QIODevice::ReadOnly)) {
        qWarning() << "Inventory file open error";
        return;
    }

    QJsonParseError parseError;
    QByteArray content = file.readAll();
    qDebug() << content;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(content, &parseError);

    file.close();

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at offset" << parseError.offset << ":" << parseError.errorString();
        return;
    }

    QJsonObject jsonObject = jsonDocument.object();

    this;
}
