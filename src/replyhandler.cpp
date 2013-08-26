#include "replyhandler.h"

namespace qsipgaterestlib {

ReplyHandler::ReplyHandler(QObject *parent) : QObject(parent), m_data("")
{
}

bool ReplyHandler::startElement(const QString &namespaceURI,
                                const QString &localName,
                                const QString &qName,
                                const QXmlAttributes &attributes)
{
    //emit data(qName);
    m_data.clear();
    return true;
}

bool ReplyHandler::endElement(const QString &namespaceURI,
                              const QString &localName,
                              const QString &qName)
{
    if(qName == "numberE164") {
        emit data(m_data);
    }
    return true;
}

bool ReplyHandler::characters(const QString &str)
{
    m_data += str;
    return true;
}

bool ReplyHandler::fatalError(const QXmlParseException &exception)
{
    emit data("Error");
    emit data(QString("Line: %1").arg(exception.lineNumber()));
    emit data(QString("Column: %1").arg(exception.columnNumber()));
    emit data("Message: " + exception.message());
    return false;
}

QString ReplyHandler::errorString() const
{
    return "";
}

} // namespace qsipgaterestlib
