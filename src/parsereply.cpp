#include "parsereply.h"

#include <QString>
#include <QByteArray>

namespace qsipgaterestlib {

ParseReply::ParseReply(QObject *parent) :
    QObject(parent),
    m_xmlReader(),
    m_handler(new qsipgaterestlib::ReplyHandler(parent))
{
    m_xmlReader.setContentHandler(m_handler);
    m_xmlReader.setErrorHandler(m_handler);

    connect(m_handler, SIGNAL(data(QString)), SLOT(onWrite(QString)));
}

void ParseReply::parse(QNetworkReply *reply)
{
    QXmlInputSource *xmlInput = new QXmlInputSource(reply);
    m_xmlReader.parse(xmlInput);

    //emit data("ParseReply::parse");
    //emit data(QString(reply->readAll()));
    //emit data(".");
}

void ParseReply::onWrite(QString text)
{
    emit data(text);
}

} // namespace qsipgaterestlib
