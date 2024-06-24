#include <QGuiApplication>

#include "PipOS/app.h"


int main(int argc, char *argv[])
{
    QGuiApplication qtGuiApp(argc, argv);
    PipOS::App app;

    app.init();
    const int status = qtGuiApp.exec();

    return status;
}
