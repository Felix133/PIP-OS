#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QObject>
#include <QQmlEngine>
#include <QtQml/qqmlregistration.h>

class GlobalConstants: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString bootText READ bootText CONSTANT FINAL)
    Q_PROPERTY(QString systemText READ systemText CONSTANT FINAL)
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit GlobalConstants(QObject *parent = nullptr);
    QString bootText() const;
    QString systemText() const;

private:
    QString m_bootText;
    QString m_systemText;
};

#endif // CONSTANTS_H
