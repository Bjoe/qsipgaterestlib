#ifndef QSIPGATERESTLIB_PARSEREPLY_H
#define QSIPGATERESTLIB_PARSEREPLY_H

#include <QObject>

#include <QNetworkReply>
#include <QXmlInputSource>
#include <QXmlSimpleReader>

#include "replyhandler.h"

namespace qsipgaterestlib {

class ParseReply : public QObject
{
    Q_OBJECT
public:
    explicit ParseReply(QObject *parent = 0);
    
signals:
    void data(QString textData);

public slots:
    void parse(QNetworkReply *reply);
    void onWrite(QString text);

private:
    QXmlSimpleReader m_xmlReader;
    qsipgaterestlib::ReplyHandler *m_handler;
};

} // namespace qsipgaterestlib

#endif // QSIPGATERESTLIB_PARSEREPLY_H
