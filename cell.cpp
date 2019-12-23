#include "cell.h"
#include <QDebug>

Cell::Cell()
{
    alive = false;
    neighborhood = new Cell*[8];
    neighborhood_num = 0;
}

Cell::~Cell()
{
    delete[] neighborhood;
}

void Cell::setAlive(bool _alive)
{
    alive = _alive;
}

bool Cell::getAlive()
{
    return alive;
}

void Cell::addNeighborhood(Cell* c)
{
    if (neighborhood_num < 8) {
        neighborhood[neighborhood_num++] = c;
    }
}

bool Cell::getNextGeneration()
{
    bool next = alive;
    int count = 0;
    for (int i = 0; i < neighborhood_num; i++) {
        if (neighborhood[i]->getAlive() == true) {
            count++;
        }
    }
    switch (count) {
    case 0:
    case 1:
        // 過疎
        if (alive == true) {
            next = false;
        }
        break;
    case 2:
        if (alive == true) {
            next = true;
        }
        break;
    case 3:
        // 生存＋誕生
        if (alive == false) {
            next = true;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        // 過密
        if (alive == true) {
            next = false;
        }
        break;
    default:
        break;
    }
    return next;
}
