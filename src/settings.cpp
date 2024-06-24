#include "PipOS/settings.h"

namespace PipOS {
Settings::Settings(QObject *parent)
    : QObject(parent)
{
    setInterfaceColor("#00ff66");
    setSkipBoot(false);
    setScanLines(false);
    setDwellerName("Albert");

    setSpecialStrength(1);
    setSpecialPerception(1);
    setSpecialEndurance(1);
    setSpecialCharisma(1);
    setSpecialIntelligence(1);
    setSpecialAgility(1);
    setSpecialLuck(1);
}

QString Settings::interfaceColor() const
{
    return m_interfaceColor;
}

void Settings::setInterfaceColor(const QString &newInterfaceColor)
{
    if (m_interfaceColor == newInterfaceColor)
        return;
    m_interfaceColor = newInterfaceColor;
    emit interfaceColorChanged();
}

bool Settings::skipBoot() const
{
    return m_skipBoot;
}

void Settings::setSkipBoot(bool newSkipBoot)
{
    if (m_skipBoot == newSkipBoot)
        return;
    m_skipBoot = newSkipBoot;
    emit skipBootChanged();
}

bool Settings::scanLines() const
{
    return m_scanLines;
}

void Settings::setScanLines(bool newScanLines)
{
    if (m_scanLines == newScanLines)
        return;
    m_scanLines = newScanLines;
    emit scanLinesChanged();
}

QString Settings::dwellerName() const
{
    return m_dwellerName;
}

void Settings::setDwellerName(const QString &newDwellerName)
{
    if (m_dwellerName == newDwellerName)
        return;
    m_dwellerName = newDwellerName;
    emit dwellerNameChanged();
}

int Settings::specialStrength() const
{
    return m_specialStrength;
}

void Settings::setSpecialStrength(int newSpecialStrength)
{
    if (m_specialStrength == newSpecialStrength)
        return;
    m_specialStrength = newSpecialStrength;
    emit specialStrengthChanged();
}

int Settings::specialPerception() const
{
    return m_specialPerception;
}

void Settings::setSpecialPerception(int newSpecialPerception)
{
    if (m_specialPerception == newSpecialPerception)
        return;
    m_specialPerception = newSpecialPerception;
    emit specialPerceptionChanged();
}

int Settings::specialEndurance() const
{
    return m_specialEndurance;
}

void Settings::setSpecialEndurance(int newSpecialEndurance)
{
    if (m_specialEndurance == newSpecialEndurance)
        return;
    m_specialEndurance = newSpecialEndurance;
    emit specialEnduranceChanged();
}

int Settings::specialCharisma() const
{
    return m_specialCharisma;
}

void Settings::setSpecialCharisma(int newSpecialCharisma)
{
    if (m_specialCharisma == newSpecialCharisma)
        return;
    m_specialCharisma = newSpecialCharisma;
    emit specialCharismaChanged();
}

int Settings::specialIntelligence() const
{
    return m_specialIntelligence;
}

void Settings::setSpecialIntelligence(int newSpecialIntelligence)
{
    if (m_specialIntelligence == newSpecialIntelligence)
        return;
    m_specialIntelligence = newSpecialIntelligence;
    emit specialIntelligenceChanged();
}

int Settings::specialAgility() const
{
    return m_specialAgility;
}

void Settings::setSpecialAgility(int newSpecialAgility)
{
    if (m_specialAgility == newSpecialAgility)
        return;
    m_specialAgility = newSpecialAgility;
    emit specialAgilityChanged();
}

int Settings::specialLuck() const
{
    return m_specialLuck;
}

void Settings::setSpecialLuck(int newSpecialLuck)
{
    if (m_specialLuck == newSpecialLuck)
        return;
    m_specialLuck = newSpecialLuck;
    emit specialLuckChanged();
}

} // namespace PipOS
