#ifndef RUNTHREAD_H
#define RUNTHREAD_H

#include <QThread>
#include <QTimer>

class RunThread : public QThread
{
    Q_OBJECT

public:
    explicit RunThread(QObject *parent = 0);
    void run();

signals:
    void data_update();

public slots:

private slots:
    void timerHit();
};

#endif // RUNTHREAD_H
