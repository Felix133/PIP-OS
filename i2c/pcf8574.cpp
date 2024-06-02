#include "pcf8574.h"

PCF8574::PCF8574(QObject *parent) : QObject(parent), m_mutex()
{
    i2c = new QI2C(i2c_bus,i2c_multiplexer_address,this);

    // initializeFrontLaser();
}

PCF8574::~PCF8574(){
    i2c->deleteLater();
    // piVL6180X->deleteLater();
}

// void PCF8574::initializeFrontLaser(){
//     piVL6180X = new PiVL6180X(i2c_bus,i2c_vl6180x_address);
//     i2c->writeBit16(i2c_multiplexer_address, piVL6180X_bus, 0x1);
//     piVL6180X->initialize();
// }
