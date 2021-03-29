#ifndef CREACIONES_H
#define CREACIONES_H
#include "tallo.h"
#include "rama.h"
#include "hoja.h"
#include "qtextedit.h"
#include "qstring.h"
#include <iostream>
#include <vector>

class Creaciones
{
public:
    Creaciones();
    void crearTallos(int, int, int);
    void crearRamas(int, int);
    void crearHojas(int);

private:
    int noTallos = 0;
    int noRamas = 0;
    int noHojas = 0;
    QVector<Tallo> misTallos;
    QVector<rama> misRamas;
    QVector<Hoja> misHojas;
    int pid;

};

#endif // CREACIONES_H
