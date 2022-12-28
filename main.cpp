#include "eventmodel.h"
#include "filewatcher.h"
#include "qstringliteral.h"
#include "watchedpathsmodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "FileSystemWatcher_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    WatchedPathsModel watchedPathsModel = WatchedPathsModel();
    EventModel eventModel = EventModel();
    FileWatcher fileWatcher = FileWatcher(nullptr, &watchedPathsModel, &eventModel);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty(QStringLiteral("watchedPathsModel"), &watchedPathsModel);
    engine.rootContext()->setContextProperty(QStringLiteral("eventModel"), &eventModel);
    engine.rootContext()->setContextProperty(QStringLiteral("fileWatcher"), &fileWatcher);
    engine.load(url);

    return app.exec();
}
