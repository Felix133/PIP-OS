#include "dataprovider.h"
namespace PipOS {

DataProvider::DataProvider(QObject *parent)
    : QObject(parent)
{}

void DataProvider::setData(const QJsonObject &newData)
{
    qDebug() << "Loaded" << newData.count() << "JSON items to DataProvider";
    m_data = newData;
    emit dataChanged();
}

bool DataProvider::loadData(const QString &filename)
{
    qInfo() << "Loading app data from" << filename;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open app data:" << file.errorString();
        return false;
    }

    QByteArray jsonData = file.readAll();
    QJsonParseError jsonErr;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &jsonErr);

    if (doc.isNull()) {
        qWarning() << "Failed to parse JSON data" << jsonErr.errorString();
        return false;
    }

    setData(doc.object());

    return true;
}

} // namespace PipOS
