#include <stdio.h>
#include <unistd.h>
#include <QVector>
#include "pipe.h"

#ifndef HOJA_H
#define HOJA_H


class Hoja
{
public:
    Hoja();
    Hoja(Pipe, int);
    void iniciarEspera();


    void setBandera(int);
    int getBandera();
    void setMiPid(int);
    int getMiPid();
    void setPipe(Pipe);
    Pipe getPipe();

private:
    int bandera;
    int miPid;
    int pidPadre;
    Pipe conexion;


};

#endif // HOJA_H
