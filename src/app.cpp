#include <QDebug>
#include <QDirIterator>
#include <QEvent>
#include <QFile>
#include <QFontDatabase>
#include <QGuiApplication>
#include <QInputDevice>
#include <QKeyEvent>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QStandardPaths>

#include "PipOS/app.h"
#include "PipOS/bootscreen.h"
#include "PipOS/hid.h"

namespace PipOS {
App::App() : QObject(nullptr) {
  QGuiApplication::setOrganizationName("RobCo-Industries");
  QGuiApplication::setOrganizationDomain("robco-industries.org");
  QGuiApplication::setApplicationName("PipOS");

  QSettings::setDefaultFormat(QSettings::IniFormat);
}

void App::init() {
  qInfo() << "Init PipOS";

  qRegisterMetaType<CollectionItem *>("CollectionItem*");

  QDirIterator it(":", {"*.ttf", "*.otf"}, QDir::Files, QDirIterator::Subdirectories);
  while (it.hasNext()) {
    QString font = it.next();
    qDebug() << "Loading font" << font;
    QFontDatabase::addApplicationFont(font);
  }

  using std::make_shared, std::make_unique;

  m_settings = make_shared<Settings>();
  m_dweller = make_shared<Dweller>();

  m_mainWindowEngine = make_unique<QQmlApplicationEngine>();

  qmlRegisterType<BootScreen>("BootScreen", 1, 0, "BootScreen");

  auto *guiAppInst =
      dynamic_cast<QGuiApplication *>(QGuiApplication::instance());

  qmlRegisterSingletonInstance("PipOS", 1, 0, "App", this);
  m_mainWindowEngine->addImportPath(guiAppInst->applicationDirPath() + "/qml");
  guiAppInst->addLibraryPath(guiAppInst->applicationDirPath() + "/qml");

  m_hid = make_shared<HumanInterfaceDevice>();
  guiAppInst->installEventFilter(m_hid.get());

  m_mainWindowEngine->load(QUrl(QStringLiteral("qrc:/qml/PipOSApp/main.qml")));
}

void App::setMainWindowEngine(QQmlApplicationEngine *mainWindowEngine) {
  if (m_mainWindowEngine.get() == mainWindowEngine)
    return;

  m_mainWindowEngine.reset(mainWindowEngine);
  emit mainWindowEngineChanged(m_mainWindowEngine.get());
}

void App::setSettings(Settings *settings) {
  if (m_settings.get() == settings)
    return;

  m_settings.reset(settings);
  emit settingsChanged(m_settings.get());
}

void App::setDweller(Dweller *dweller) {
  if (m_dweller.get() == dweller)
    return;

  m_dweller.reset(dweller);
  emit dwellerChanged(m_dweller.get());
}

} // namespace PipOS
