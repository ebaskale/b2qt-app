#include "networktest.h"

#include <QGuiApplication>
#include <QtCore>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
//    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
//    qputenv("QT_QPA_PLATFORM", QByteArray("eglfs"));
    qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("215"));
    qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("157"));

    qDebug() << "ne oluyor";
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<networktest>("tr.com.pcis", 1, 0, "NetworkTester");
    static QTextStream ts( stdout );
    ts << "fuck";
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
