#ifndef QSIPGATERESTLIB_REPLYHANDLER_H
#define QSIPGATERESTLIB_REPLYHANDLER_H

#include <QXmlDefaultHandler>

namespace qsipgaterestlib {

class ReplyHandler : public QObject, public QXmlDefaultHandler
{
    Q_OBJECT

public:
    explicit ReplyHandler(QObject *parent = 0);
    
    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);
    QString errorString() const;

signals:
    void data(QString);

private:
    QString m_data;
};

} // namespace qsipgaterestlib

#endif // QSIPGATERESTLIB_REPLYHANDLER_H
