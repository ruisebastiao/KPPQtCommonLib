#include "kpptcpclientthread.h"

using namespace KPPQtCommon;


KPPTCPClientThread::KPPTCPClientThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void KPPTCPClientThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    socket = new QTcpSocket();

    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies
    QString msg("Connected\n\r");
    socket->write(msg.toStdString().c_str(),msg.size());
    exec();
}

void KPPTCPClientThread::readyRead()
{

    if(socket->canReadLine())
    {
        QByteArray ba = socket->readLine();

       // QByteArray response;

        // will write on server side window
        qDebug() << socketDescriptor << " Data in: " << ba;


        // some code which parses arrived message
        // and prepares response

        //socket->write(response);
    }

    /*
    // get the information
    QByteArray Data = socket->readAll();

    // will write on server side window
    qDebug() << socketDescriptor << " Data in: " << Data;

   // socket->write(Data);
   */
}

void KPPTCPClientThread::SendImage(const QImage &image)
{
 //   image.
    do {
        sleep(10000000);
    } while (true);
}

void KPPTCPClientThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}
