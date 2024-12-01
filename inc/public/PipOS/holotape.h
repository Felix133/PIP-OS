#ifndef HOLOTAPE_H
#define HOLOTAPE_H

#include <QObject>
#include <QQmlEngine>

namespace PipOS {
class HolotapeProvider : public QObject {
  Q_OBJECT

public:
  explicit HolotapeProvider(QObject *parent = nullptr);

  signals:
  void holotapeLoaded(QString tape);
};
} // namespace PipOS
#endif
