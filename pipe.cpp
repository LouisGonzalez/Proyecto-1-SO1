#include "pipe.h"

Pipe::Pipe()
{

}

Pipe::Pipe(int interruptor, int conexion[]){
    *this->conexion - *conexion;
    this->interruptor = interruptor;
}

void Pipe::setInterruptor(int interruptor){
    this->interruptor = interruptor;
}

int Pipe::getInterruptor(){
    return this->interruptor;
}

void Pipe::setConexion(int conexion[]){
    *this->conexion = *conexion;
}

int* Pipe::getConexion(){
    return this->conexion;
}
