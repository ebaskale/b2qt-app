#include <QGuiApplication>
#include <QtCore>
#include <QQmlApplicationEngine>

#include <services/timeservice.h>

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("215"));
    qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("157"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationDomain("tr.com.pcis");
    QCoreApplication::setApplicationVersion("1.0");

    qmlRegisterType<TimeService>("tr.com.pcis", 1, 0, "TimeWatcher");

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
