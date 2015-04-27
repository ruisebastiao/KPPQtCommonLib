#include "kpptcpserver.h"

using namespace KPPQtCommon;


KPPTCPServer::KPPTCPServer(QObject *parent) :
    QTcpServer(parent)
{
}

void KPPTCPServer::startServer()
{
    int port = 9600;

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
}

// This function is called by QTcpServer when a new connection is available.
void KPPTCPServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
    KPPTCPClientThread *thread = new KPPTCPClientThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();

    emit NewClientConnected(thread);
}
