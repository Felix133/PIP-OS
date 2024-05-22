#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>

class Inventory : public QObject
{
    Q_OBJECT

public:
    explicit Inventory(QObject *parent = nullptr);
    void LoadFromFile();

signals:
};

#endif // INVENTORY_H
