#include "Level/level.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <Qt>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    qmlRegisterType<Level>( "CustomComponents", 1, 0, "Level" );
    engine.load(QUrl(QStringLiteral("qrc:/TheButcher_logics.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
