#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QStyleFactory>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    QApplication app(argc, argv);
    app.setApplicationName("SeriesIndexer");
    app.setApplicationVersion("2.0");
    app.setOrganizationName("SeriesIndexer");
    app.setStyle(QStyleFactory::create("Fusion"));

    // Load QSS stylesheet
    QFile styleFile(":/resources/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        app.setStyleSheet(QString::fromUtf8(styleFile.readAll()));
        styleFile.close();
    }

    MainWindow w;
    w.show();
    return app.exec();
}
