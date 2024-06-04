#ifdef LINUX

#ifndef PCF8574_H
#define PCF8574_H

#include <QObject>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

#include "qi2c.h"


class PCF8574 : public QObject
{
    Q_OBJECT
public:
    explicit PCF8574(QObject *parent = nullptr);
    ~PCF8574();

public slots:
    // double getFrontLaser();

signals:
private slots:
    // void initializePwmController();

private:    
    Q_DISABLE_COPY(PCF8574)
    QMutex m_mutex;

    QI2C *i2c;

    const uint8_t i2c_bus = 0x1;
    const uint8_t i2c_multiplexer_address = 0x70;

    // const uint8_t i2c_vl6180x_address = 0x29;
    // const uint8_t i2c_vl53l1x_address = 0x29;
    // const uint8_t i2c_qmc5883l_address = 0x0D;
    // const uint8_t i2c_mpu6050_address = 0x68;
    // const uint8_t i2c_pca9685_address = 0x40;


    PiVL6180X* piVL6180X;
    const uint8_t piVL6180X_bus = 0x5;

};

#endif // PCF8574_H
#endif
