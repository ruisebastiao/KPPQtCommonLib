#include "kppqtthread.h"

using namespace KPPQtCommon;

KPPQtThread::KPPQtThread(QObject *parent, bool Paused):
    QThread(parent)
{
    m_pause=Paused;

}

void KPPQtThread::Pause()
{
    sync.lock();
    m_pause = true;
    sync.unlock();
}

void KPPQtThread::Resume()
{
    sync.lock();
    m_pause = false;
    sync.unlock();
    pauseCond.wakeAll();
}

void KPPQtThread::run()
{
    while(isInterruptionRequested()==false) // gues it's your loop
    {
        sync.lock();
        if(m_pause)
            pauseCond.wait(&sync); // in this place, your thread will stop to execute until someone calls resume
        sync.unlock();
        msleep(10);
        // do your operation
    }
}

