#include "lifegame.h"
#include <QDebug>
#include <stdio.h>
#include <unistd.h>

using namespace std;

LifeGame::LifeGame(QObject *parent) : QObject(parent)
{

}


void LifeGame::runButtonSlot(QString msg)
{
    qDebug() << "runButtonSlot is called with the message: " << msg;
    emit cppSignal("Hello from C++");
    std::thread th(&LifeGame::run,this);

    th.join();
}

void LifeGame::stopButtonSlot(QString msg)
{
    qDebug() << "stopButtonSlot is called with the message: " << msg;
}

void LifeGame::run()
{
    for(int i = 0; i < 10; i++) {
        qDebug() << "test thread";
        sleep(1);
    }
}
