#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QUrl>
#include <QQmlContext>
#include <qqml.h>

#include <QStandardPaths>
#include <QStringList>
#include <filereader.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    QUrl appPath(QString("%1").arg(app.applicationDirPath()));
    QUrl moviesPath;

    const QStringList moviesLocation = QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);

    if (moviesLocation.isEmpty())
        moviesPath = appPath.resolved(QUrl("/"));
    else
        moviesPath = moviesLocation.first();

    engine.rootContext()->setContextProperty("appPath",appPath);
    engine.rootContext()->setContextProperty("moviesPath",moviesPath);

    qmlRegisterType<FileReader>("Files", 0, 1, "ReadFile");

//    qDebug() << "This is where the applicaiton runs " << appPath;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
