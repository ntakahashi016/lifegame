#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <QObject>
#include <QVariant>
#include <iostream>
#include <thread>

class LifeGame : public QObject
{
    Q_OBJECT

public:
    explicit LifeGame(QObject *parent = 0);

signals:
    void cppSignal(QVariant text);

public slots:
    void runButtonSlot(QString msg);
    void stopButtonSlot(QString msg);

private:
    void run();
};

#endif // LIFEGAME_H
