#include "hid.h"
#include <QKeyEvent>

namespace PipOS {
bool HumanInterfaceDevice::eventFilter(QObject *object, QEvent *event)
{
    switch (event->type()) {
    case QEvent::KeyPress: {
        // Handle key press events
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        Qt::Key qtKey = Qt::Key(keyEvent->key());
        if (keymap.contains(qtKey)) {
            QString activity = keymap.value(qtKey);

            // Catch an app quit event and handle that here
            if (activity == "APP_QUIT") {
                QCoreApplication::quit();
                return true;
            }

            // qInfo() << qtKey << keymap.value(qtKey);

            // Emit all other user activity as a signal that can be handled in the QML
            emit userActivity(activity);
            return true;
        } else {
            // qInfo() << qtKey << "not mapped";
            return QObject::eventFilter(object, event);
        }
    }

    default:
        // standard event processing for non key press
        return QObject::eventFilter(object, event);
    }
}

void HumanInterfaceDevice::setKeyMap(Qt::Key key, QString activity)
{
    keymap.insert(key, activity);
}
} // namespace PipOS
