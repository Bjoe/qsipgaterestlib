#ifndef QSIPGATERESTLIB_UICONTROL_H
#define QSIPGATERESTLIB_UICONTROL_H

#include <QObject>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "parsereply.h"

namespace qsipgaterestlib {

class UIControl : public QObject
{
    Q_OBJECT
public:
    explicit UIControl(QObject *qmlComponent, QObject *parent = 0);
    
signals:
    
public slots:
    void onRequest();
    void onWrite(QString);

private:
    QNetworkAccessManager *m_networkManager;
    QObject *m_qmlComponent;
    qsipgaterestlib::ParseReply *m_parseReply;
};

} // namespace qsipgaterestlib

#endif // QSIPGATERESTLIB_UICONTROL_H
