#include "calculos.h"

Calculos::Calculos()
{


}

/*int Calculos::calcularArreglo(){
    return totalProcesos = this->getNoTallos()+(this->getNoTallos()*this->getNoRamas())+(this->getNoTallos()*this->getNoRamas()*this->getNoHojas());
}*/


int Calculos::calcularNodo(int tallos, int ramas, int hojas, int tipo){
    int pos = 169;
    switch(tipo){
        //busco un nodo tallo
        case 1: {
            int talloTemp = tallos - 1;
            pos = (talloTemp *56);
            break;
        }
        //busco un nodo rama
        case 2:{
            int talloTemp = tallos - 1;
            int ramaTemp = ramas - 1;
            pos = (talloTemp * 56) + (1 + (ramaTemp * 1) + (1 * ramaTemp * 10));
            break;
        }
        //busco un nodo hoja
        case 3:{
            int talloTemp = tallos - 1;
            int ramaTemp = ramas - 1;
            int hojaTemp = hojas - 1;
            pos = (talloTemp * 56) + (1 + (ramaTemp * 1) + (1 * ramaTemp * 10)) + (1 + (1* hojaTemp));
            break;
        }

    }
    return pos;
}
