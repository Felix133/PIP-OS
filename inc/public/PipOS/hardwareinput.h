// gpiomonitor.h
#pragma once

#include <QMutex>
#include <QObject>
#include <QThread>
#include <QWaitCondition>
#include "gpio.h"
#include "inputeventhandler.h"

namespace PipOS {
class HardwareEventHandler : public InputEventHandler
{
public:
    HardwareEventHandler(QObject *parent = nullptr);
    ~HardwareEventHandler() override;

    void startMonitoring();
    void stopMonitoring();

protected:
    void run();

    static constexpr int SW_STAT = 1;
    static constexpr int SW_ITEM = 2;
    static constexpr int SW_DATA = 3;
    static constexpr int ENC_A = 4;
    static constexpr int ENC_B = 5;
    static constexpr int ENC_SW = 0;

    std::array<bool, 6> pinStates{};
    std::array<bool, 2> prevEncoderStates{};

private:
    GPIO gpio;
    QThread workerThread;
    QMutex mutex;
    QWaitCondition condition;
    bool abort;
};
} // namespace PipOS
