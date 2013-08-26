
#include <QUrl>
#include <QtQml>
#include <QtQuick/QQuickView>
#include <QtCore/QString>

#ifndef QT_NO_WIDGETS
#include <QtWidgets/QApplication>
#else
#include <QtGui/QGuiApplication>
#endif

#include "uicontrol.h"

#ifndef QT_NO_WIDGETS
#define Application QApplication
#else
#define Application QGuiApplication
#endif

int main(int argc, char *argv[])
{
    Application app(argc, argv);
    app.setOrganizationName("devolab");
    app.setOrganizationDomain("devolab.de");
    app.setApplicationName("QSipgateRest Example");

    QQmlApplicationEngine engine(QUrl("qrc:/qml/main.qml"));
    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    if ( !window ) {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }
    qsipgaterestlib::UIControl uiControl(topLevel);
    QObject::connect(topLevel, SIGNAL(qmlRequest()), &uiControl, SLOT(onRequest()));
    QObject::connect(topLevel, SIGNAL(qmlParse()), &uiControl, SLOT(onParse()));

    window->show();
    return app.exec();
}
