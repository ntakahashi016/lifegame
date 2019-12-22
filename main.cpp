#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "lifegame.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    LifeGame obj;

    QObject *root = engine.rootObjects().first();

    QObject::connect(root, SIGNAL(runButtonSignal(QString)),
                     &obj, SLOT(runButtonSlot(QString)));

    QObject::connect(root, SIGNAL(stopButtonSignal(QString)),
                     &obj, SLOT(stopButtonSlot(QString)));

    QObject::connect(&obj, SIGNAL(cppSignal(QVariant)),
                     root, SLOT(qmlSlot(QVariant)));

    return app.exec();
}
