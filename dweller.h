#ifndef DWELLER_H
#define DWELLER_H

#include <QObject>
#include <QQmlEngine>
#include <QtQml/qqmlregistration.h>

class Dweller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY levelChanged FINAL)
    Q_PROPERTY(float levelProgress READ levelProgress WRITE setLevelProgress NOTIFY levelProgressChanged FINAL)
    Q_PROPERTY(int maxHealth READ maxHealth WRITE setMaxHealth NOTIFY maxHealthChanged FINAL)
    Q_PROPERTY(int currentHealth READ currentHealth WRITE setCurrentHealth NOTIFY currentHealthChanged FINAL)
    Q_PROPERTY(float healthHead READ healthHead WRITE setHealthHead NOTIFY healthHeadChanged FINAL)
    Q_PROPERTY(float healthBody READ healthBody WRITE setHealthBody NOTIFY healthBodyChanged FINAL)
    Q_PROPERTY(float healthLeftArm READ healthLeftArm WRITE setHealthLeftArm NOTIFY healthLeftArmChanged FINAL)
    Q_PROPERTY(float healthRightArm READ healthRightArm WRITE setHealthRightArm NOTIFY healthRightArmChanged FINAL)
    Q_PROPERTY(float healthLeftLeg READ healthLeftLeg WRITE setHealthLeftLeg NOTIFY healthLeftLegChanged FINAL)
    Q_PROPERTY(float healthRightLeg READ healthRightLeg WRITE setHealthRightLeg NOTIFY healthRightLegChanged FINAL)
    Q_PROPERTY(int maxAP READ maxAP WRITE setMaxAP NOTIFY maxAPChanged FINAL)
    Q_PROPERTY(int currentAP READ currentAP WRITE setCurrentAP NOTIFY currentAPChanged FINAL)

    QML_ELEMENT
    QML_SINGLETON

public:
    explicit Dweller(QObject *parent = nullptr);
    int level() const;
    float levelProgress() const;
    int maxHealth() const;
    int currentHealth() const;
    int maxAP() const;
    int currentAP() const;

    QString name() const;
    float healthHead() const;
    float healthBody() const;
    float healthLeftArm() const;
    float healthRightArm() const;
    float healthLeftLeg() const;
    float healthRightLeg() const;

public slots:
    void setName(const QString &newName);
    void setLevel(int newLevel);
    void setLevelProgress(float newLevelProgress);
    void setHealthHead(float newHealthHead);
    void setHealthBody(float newHealthBody);
    void setHealthLeftArm(float newHealthLeftArm);
    void setHealthRightArm(float newHealthRightArm);
    void setHealthLeftLeg(float newHealthLeftLeg);
    void setHealthRightLeg(float newHealthRightLeg);
    void setMaxHealth(int newMaxHealth);
    void setCurrentHealth(int newCurrentHealth);
    void setMaxAP(int newMapAP);
    void setCurrentAP(int newCurrentAP);

signals:
    void nameChanged();
    void levelChanged();
    void levelProgressChanged();
    void maxHealthChanged();
    void currentHealthChanged();
    void maxAPChanged();
    void currentAPChanged();
    void healthHeadChanged();
    void healthBodyChanged();
    void healthLeftArmChanged();
    void healthRightArmChanged();
    void healthLeftLegChanged();
    void healthRightLegChanged();

private:
    int m_level;
    float m_levelProgress;
    int m_maxHealth;
    int m_currentHealth;
    int m_maxAP;
    int m_currentAP;
    QString m_name;
    float m_healthHead;
    float m_healthBody;
    float m_healthLeftArm;
    float m_healthRightArm;
    float m_healthLeftLeg;
    float m_healthRightLeg;
};

#endif // DWELLER_H
