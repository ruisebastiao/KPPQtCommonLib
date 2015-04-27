#ifndef KPPQTTHREAD_H
#define KPPQTTHREAD_H

#include "kppqtcommonlib_global.h"
#include "QThread"
#include "QWaitCondition"

namespace KPPQtCommon {

class KPPQTCOMMONLIBSHARED_EXPORT KPPQtThread : public QThread
{
public:
    KPPQtThread(QObject *parent,bool Paused=false);
    void Pause();
    void Resume();


    QMutex sync;
    QWaitCondition pauseCond;
    bool m_pause;
private:
    // QThread interface
protected:
    void run();
};

}
#endif // KPPQTTHREAD_H
