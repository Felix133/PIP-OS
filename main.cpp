#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QQmlContext>
#include <QSettings>

#include "constants.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationName("RobCo");
    app.setOrganizationDomain("example.com");
    app.setApplicationName("PipOS");

    QSettings::setDefaultFormat(QSettings::IniFormat);

    QFontDatabase::addApplicationFont(":/fonts/Share-TechMono.ttf");
    QFontDatabase::addApplicationFont(":/fonts/RobotoCondensedFallout.ttf");
    QFontDatabase::addApplicationFont(":/fonts/RobotoCondensedLightFallout.ttf");
    QFontDatabase::addApplicationFont(":/fonts/RobotoCondensedBoldFallout.ttf");

    QQmlApplicationEngine engine;

    // Access root context
    QQmlContext* context = engine.rootContext();

    // Set context property
    GlobalConstants globalConstants;
    context->setContextProperty("constants", &globalConstants);

    const QUrl url(QStringLiteral("qrc:/RobCo/PipOS/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
