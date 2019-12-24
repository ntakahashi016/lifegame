#include "runthread.h"
#include <stdio.h>

RunThread::RunThread(QObject *parent) :
    QThread(parent)
{

}
void RunThread::run(){
    QTimer timer;
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(timerHit()), Qt::DirectConnection );

    timer.setInterval(100);
    timer.start();

    exec();

    timer.stop();
}

void RunThread::timerHit(){
    static int i;
    emit data_update();
}
