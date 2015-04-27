#ifndef KPPTCPCLIENTTHREAD_H
#define KPPTCPCLIENTTHREAD_H

#include <QObject>
#include "kppqtcommonlib_global.h"
#include <QTcpSocket>
#include <QThread>
#include "qimage.h"



namespace KPPQtCommon {


class KPPQTCOMMONLIBSHARED_EXPORT KPPTCPClientThread : public QThread
{
    Q_OBJECT
public:    
    explicit KPPTCPClientThread(qintptr ID, QObject *parent = 0);

    void run();


signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void SendImage(const QImage&);
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;

};

}

#endif // KPPTCPCLIENTTHREAD_H
