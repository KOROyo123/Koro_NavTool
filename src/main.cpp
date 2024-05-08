#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>

#include <QQmlContext>
#include <QDir>
#include <QQuickWindow>
#include <QNetworkProxy>
#include <QSslConfiguration>
#include <QProcess>
#include <QtQml/qqmlextensionplugin.h>
#include <QLoggingCategory>

#include "Version.h"
#include "AppInfo.h"
#include "cpp/component/CircularReveal.h"
#include "cpp/component/FileWatcher.h"
#include "cpp/component/FpsItem.h"
#include "cpp/component/OpenGLItem.h"
#include "cpp/helper/SettingsHelper.h"
#include "cpp/helper/InitializrHelper.h"
#include "cpp/helper/TranslateHelper.h"
#include "cpp/helper/Network.h"
#include "cpp/helper/Log.h"

#ifdef WIN32
#include "app_dmp.h"
#endif

int main(int argc, char *argv[])
{
    const char *uri = "knt";
    int major = 1;
    int minor = 0;

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QGuiApplication::setOrganizationName("KOROyo123");
    QGuiApplication::setOrganizationDomain("https://github.com/KOROyo123");
    QGuiApplication::setApplicationName("Koro_NavTool");
    QGuiApplication::setApplicationDisplayName("Koro_NavTool");
    QGuiApplication::setApplicationVersion(PROJECT_SET_VERSION);
    QGuiApplication::setQuitOnLastWindowClosed(false);

    SettingsHelper::getInstance()->init(argv);
    Log::setup(argv,uri);

    qmlRegisterType<CircularReveal>(uri, major, minor, "CircularReveal");
    qmlRegisterType<FileWatcher>(uri, major, minor, "FileWatcher");
    qmlRegisterType<FpsItem>(uri, major, minor, "FpsItem");
    qmlRegisterType<NetworkCallable>(uri,major,minor,"NetworkCallable");
    qmlRegisterType<NetworkParams>(uri,major,minor,"NetworkParams");
    qmlRegisterType<OpenGLItem>(uri,major,minor,"OpenGLItem");
    qmlRegisterUncreatableMetaObject(NetworkType::staticMetaObject, uri, major, minor, "NetworkType", "Access to enums & flags only");

    QQmlApplicationEngine engine;
    TranslateHelper::getInstance()->init(&engine);
    engine.rootContext()->setContextProperty("AppInfo",AppInfo::getInstance());
    engine.rootContext()->setContextProperty("SettingsHelper",SettingsHelper::getInstance());
    engine.rootContext()->setContextProperty("InitializrHelper",InitializrHelper::getInstance());
    engine.rootContext()->setContextProperty("TranslateHelper",TranslateHelper::getInstance());
    engine.rootContext()->setContextProperty("Network",Network::getInstance());

    const QUrl url(QStringLiteral("qrc:qml/App.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}