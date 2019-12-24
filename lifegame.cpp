#include "lifegame.h"
#include <QDebug>
#include <stdio.h>
#include <unistd.h>

using namespace std;

LifeGame::LifeGame(QObject *parent) : QObject(parent)
{
    culmn = 50;
    cells = new Cell[culmn*culmn];
    QObject::connect(&runThread, SIGNAL(data_update()),
                     this, SLOT(run()));
    // 近傍のセルを追加する
    for (int i = 0; i < culmn*culmn; i++)
    {
        // 一番上の行を除く
        if (i >= culmn) {
            // 左端を除く
            if (i % culmn != 0) {
                cells[i].addNeighborhood(&cells[i-culmn-1]);
            }
            cells[i].addNeighborhood(&cells[i-culmn]);
            //右端を除く
            if (i % culmn != culmn - 1) {
                cells[i].addNeighborhood(&cells[i-culmn+1]);
            }
        }
        // 左端を除く
        if (i % culmn != 0) {
            cells[i].addNeighborhood(&cells[i-1]);
        }
        // 右端を除く
        if (i % culmn != culmn - 1) {
            cells[i].addNeighborhood(&cells[i+1]);
        }
        // 一番下の行を除く
        if (i < culmn * culmn - culmn) {
            // 左端を除く
            if (i % culmn != 0) {
                cells[i].addNeighborhood(&cells[i+culmn-1]);
            }
            cells[i].addNeighborhood(&cells[i+culmn]);
            // 右端を除く
            if (i % culmn != culmn - 1) {
                cells[i].addNeighborhood(&cells[i+culmn+1]);
            }
        }
    }
}
LifeGame::~LifeGame()
{
    runThread.quit();
    runThread.wait();
    delete[] cells;
}


void LifeGame::runButtonSlot(QVariant array)
{
    QVariantList list;
    list = array.toList();
    for (int i = 0; i < list.size(); i++) {
        cells[i].setAlive(list[i].toBool());
    }
    runThread.start();
}

void LifeGame::stopButtonSlot(QString msg)
{
    runThread.quit();
    runThread.wait();
}

void LifeGame::run()
{
    QVariantList list;
    Cell* nextGeneration;
    nextGeneration = new Cell[culmn*culmn];
    for (int j = 0; j < culmn*culmn; j++) {
        nextGeneration[j].setAlive(cells[j].getNextGeneration());
    }
    for (int i = 0; i < culmn*culmn; i++) {
        cells[i].setAlive(nextGeneration[i].getAlive());
    }
    for (int i = 0; i < culmn*culmn; i++) {
        list << cells[i].getAlive();
    }
    emit setArray(list);
}
