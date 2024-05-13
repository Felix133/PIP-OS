#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/RobotoCondensedFallout.ttf");
    QFontDatabase::addApplicationFont(":/fonts/RobotoCondensedLightFallout.ttf");
    QFontDatabase::addApplicationFont(":/fonts/RobotoCondensedBoldFallout.ttf");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/PipOS/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
