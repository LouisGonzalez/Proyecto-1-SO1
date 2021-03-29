#include <stdio.h>
#include <unistd.h>
#include <QVector>
#include "rama.h"
#include "pipe.h"
#include "QLabel"

#ifndef TALLO_H
#define TALLO_H


class Tallo
{
public:
    Tallo();
    Tallo(Pipe, int);
    void iniciarEspera();
    void construccionRamas(QVector<Pipe>, int, int, int, QVector<QLabel*>&);

    void setBandera(int);
    int getBandera();
    void setMiPid(int);
    int getMiPid();
    void setPipe(Pipe);
    Pipe getPipe();
    QVector<rama> misRamas;


private:
    int bandera;
    int miPid;
    int pidPadre;
    Pipe conexion;
    int noRamas = 0;
};

#endif // TALLO_H
