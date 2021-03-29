#include "hoja.h"

Hoja::Hoja()
{

}

Hoja::Hoja(Pipe conexion, int bandera){
    this->conexion = conexion;
    this->bandera = bandera;
}

void Hoja::setBandera(int bandera){
    this->bandera = bandera;
}

int Hoja::getBandera(){
    return this->bandera;
}

void Hoja::setMiPid(int miPid){
    this->miPid = miPid;
}

int Hoja::getMiPid(){
    return this->miPid;
}

void Hoja::setPipe(Pipe miPipe){
    this->conexion = miPipe;
}

Pipe Hoja::getPipe(){
    return this->conexion;
}
