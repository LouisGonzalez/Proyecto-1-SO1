#include "QVector"
#include "pipe.h"
#include "stdio.h"
#include "tallo.h"
#include "QLabel"


#ifndef NUCLEO_H
#define NUCLEO_H


class Nucleo
{
public:
    Nucleo();
    QVector<Pipe> conectores;

    void inicializarPipes();
    void construccion(int, int, int,QVector<QLabel*>&);
    void construccionRamas();
    void construccionHojas();

    void setNoTallos(int noTallos);
    void setNoRamas(int noRamas);
    void setNoHojas(int noHojas);

    int getNoTallos();
    int getNoRamas();
    int getNoHojas();
    QVector<Tallo> misTallos;

private:
    int noTallos = 0;
    int noRamas;
    int noHojas;
    int totalConectores = 168;

};

#endif // NUCLEO_H
