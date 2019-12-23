#ifndef CELL_H
#define CELL_H


class Cell
{
    bool alive;
    Cell** neighborhood;
    int neighborhood_num;
public:
    Cell();
    ~Cell();
    void setAlive(bool _alive);
    bool getAlive();
    void addNeighborhood(Cell* c);
    bool getNextGeneration();
};

#endif // CELL_H
