#ifndef KPPTCPSERVER_H
#define KPPTCPSERVER_H

#include <QObject>
#include "kppqtcommonlib_global.h"
#include <QTcpServer>
#include "kpptcpclientthread.h"



namespace KPPQtCommon {


class KPPQTCOMMONLIBSHARED_EXPORT KPPTCPServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit KPPTCPServer(QObject *parent = 0);
    void startServer();
protected:
    void incomingConnection(qintptr socketDescriptor);
};

}

#endif // KPPTCPSERVER_H
