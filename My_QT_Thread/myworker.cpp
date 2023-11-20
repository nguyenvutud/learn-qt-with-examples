#include "myworker.h"
#include <QDebug>

MyWorker::MyWorker() :
    m_pause(false), m_stop(false)
{

}

void MyWorker::resume()
{
    sync.lock();
    m_pause = false;
    sync.unlock();
    pauseCond.wakeAll();
}

void MyWorker::pause()
{
    sync.lock();
    m_pause = true;
    sync.unlock();
}

void MyWorker::run()
{
    while(!m_stop)
    {
        sync.lock();
        if(m_pause)
            pauseCond.wait(&sync);//in this place, your thread will stop executing until someone calls resume
        sync.unlock();

        //do your operation
        for(int i = 0; i < 100; i++)
        {
            qInfo() << "In Thread:" << i;
            this->usleep(10);
        }
    }
    qInfo() << "Stopped run()";
}

void MyWorker::stop()
{
    sync.lock();
    m_stop = true;
    sync.unlock();
}
