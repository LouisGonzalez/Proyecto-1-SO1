#include <stdio.h>
#include <unistd.h>
#include <QVector>
#include "hoja.h"
#include "pipe.h"
#include "QLabel"

#ifndef RAMA_H
#define RAMA_H


class rama
{
public:
    rama();
    rama(Pipe, int);
    void iniciarEspera();
    void construccionHojas(QVector<Pipe>, int, int, int, QVector<QLabel*>&);


    void setBandera(int);
    int getBandera();
    void setMiPid(int);
    int getMiPid();
    void setPipe(Pipe);
    Pipe getPipe();
    QVector<Hoja> misHojas;

private:
    int bandera;
    int miPid;
    int pidPadre;
    Pipe conexion;
    int noHojas = 0;

};

#endif // RAMA_H
