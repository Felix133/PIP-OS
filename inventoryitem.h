#pragma once

#include <QString>

class InventoryItem
{
public:
    InventoryItem(const QString &name, int quantity)
        : m_name(name), m_quantity(quantity) {}

    QString name() const { return m_name; }
    int quantity() const { return m_quantity; }

private:
    QString m_name;
    int m_quantity;
};