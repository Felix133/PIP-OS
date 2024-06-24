#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QSettings>

namespace PipOS {
class ActiveProfile;

class Settings : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("")
    Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

    Q_PROPERTY(QString interfaceColor READ interfaceColor WRITE setInterfaceColor NOTIFY
                   interfaceColorChanged FINAL)
    Q_PROPERTY(bool skipBoot READ skipBoot WRITE setSkipBoot NOTIFY skipBootChanged FINAL)
    Q_PROPERTY(bool scanLines READ scanLines WRITE setScanLines NOTIFY scanLinesChanged FINAL)
    Q_PROPERTY(
        QString dwellerName READ dwellerName WRITE setDwellerName NOTIFY dwellerNameChanged FINAL)

    Q_PROPERTY(int specialStrength READ specialStrength WRITE setSpecialStrength NOTIFY
                   specialStrengthChanged FINAL)
    Q_PROPERTY(int specialPerception READ specialPerception WRITE setSpecialPerception NOTIFY
                   specialPerceptionChanged FINAL)
    Q_PROPERTY(int specialEndurance READ specialEndurance WRITE setSpecialEndurance NOTIFY
                   specialEnduranceChanged FINAL)
    Q_PROPERTY(int specialCharisma READ specialCharisma WRITE setSpecialCharisma NOTIFY
                   specialCharismaChanged FINAL)
    Q_PROPERTY(int specialIntelligence READ specialIntelligence WRITE setSpecialIntelligence NOTIFY
                   specialIntelligenceChanged FINAL)
    Q_PROPERTY(int specialAgility READ specialAgility WRITE setSpecialAgility NOTIFY
                   specialAgilityChanged FINAL)
    Q_PROPERTY(int specialLuck READ specialLuck WRITE setSpecialLuck NOTIFY specialLuckChanged FINAL)

public:
    explicit Settings(QObject *parent = nullptr);

    QString interfaceColor() const;
    bool skipBoot() const;
    bool scanLines() const;
    QString dwellerName() const;

    int specialStrength() const;
    int specialPerception() const;
    int specialEndurance() const;
    int specialCharisma() const;
    int specialIntelligence() const;
    int specialAgility() const;
    int specialLuck() const;

signals:
    void interfaceColorChanged();
    void skipBootChanged();
    void scanLinesChanged();
    void dwellerNameChanged();

    void specialStrengthChanged();
    void specialPerceptionChanged();
    void specialEnduranceChanged();
    void specialCharismaChanged();
    void specialIntelligenceChanged();
    void specialAgilityChanged();
    void specialLuckChanged();

public slots:
    void setInterfaceColor(const QString &newInterfaceColor);
    void setSkipBoot(bool newSkipBoot);
    void setScanLines(bool newScanLines);
    void setDwellerName(const QString &newDwellerName);

    void setSpecialIntelligence(int newSpecialIntelligence);
    void setSpecialAgility(int newSpecialAgility);
    void setSpecialLuck(int newSpecialLuck);
    void setSpecialCharisma(int newSpecialCharisma);
    void setSpecialEndurance(int newSpecialEndurance);
    void setSpecialPerception(int newSpecialPerception);
    void setSpecialStrength(int newSpecialStrength);

private:
    QSettings m_qSettings;

    QString m_interfaceColor;
    bool m_skipBoot;
    bool m_scanLines;
    QString m_dwellerName;

    int m_specialStrength;
    int m_specialPerception;
    int m_specialEndurance;
    int m_specialCharisma;
    int m_specialIntelligence;
    int m_specialAgility;
    int m_specialLuck;
};
}
