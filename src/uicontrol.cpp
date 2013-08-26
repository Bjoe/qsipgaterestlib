#include "uicontrol.h"

#include <QVariant>
#include <QSettings>

namespace qsipgaterestlib {

UIControl::UIControl(QObject *qmlComponent, QObject *parent) :
    QObject(parent),
    m_networkManager(new QNetworkAccessManager(parent)),
    m_parseReply(new qsipgaterestlib::ParseReply(parent)),
    m_qmlComponent(qmlComponent)
{
    m_parseReply->connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), m_parseReply, SLOT(parse(QNetworkReply*)));
    connect(m_parseReply, SIGNAL(data(QString)), SLOT(onWrite(QString)));
}

void UIControl::onRequest()
{
    QSettings settings;
    QVariant username = settings.value("username");
    QVariant password = settings.value("password");
    QVariant url = settings.value("url");
    QVariant uri = settings.value("uri");
    QVariant webUser = settings.value("webuser");

    QUrl urlRequest;
    urlRequest.setUrl(url.toString());
    urlRequest.setUserName(username.toString());
    urlRequest.setPassword(password.toString());
    urlRequest.setPath(QString("/%1/events/").arg(webUser.toString()));
    urlRequest.setFragment("version=2.41.0&complexity=full");

    QNetworkRequest networkRequest;
    networkRequest.setUrl(urlRequest);
    onWrite(urlRequest.toString());

    m_networkManager->get(networkRequest);
}

void UIControl::onWrite(QString text)
{
    QVariant variant = QVariant(text);
    QMetaObject::invokeMethod(m_qmlComponent, "write",
                              Q_ARG(QVariant, variant));
}

} // namespace qsipgaterestlib
