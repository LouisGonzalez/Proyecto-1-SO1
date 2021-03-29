#include <QThread>


#ifndef HILOS_H
#define HILOS_H

using namespace std;


class Hilos : public QThread
{
public:
    explicit Hilos(QObject *parent = 0);
    void run();
    int planta = 0;

signals:
    void NuevoColor(int, int, int);

public slots:

};

#endif // HILOS_H
