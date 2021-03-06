#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <QObject>
#include <QVariant>
#include <iostream>
#include <thread>
#include "cell.h"
#include "runthread.h"

class LifeGame : public QObject
{
    Q_OBJECT
    Cell* cells;
    int culmn;
    RunThread runThread;


public:
    explicit LifeGame(QObject *parent = 0);
    ~LifeGame();

signals:
    void setArray(QVariant array);

public slots:
    void runButtonSlot(QVariant array);
    void stopButtonSlot(QString msg);
    void run();
};

#endif // LIFEGAME_H
