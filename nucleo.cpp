#include "nucleo.h"
#include "pipe.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include "tallo.h"
#include "calculos.h"
#include <unistd.h>
#include <stdio.h>
#include "QVector"
#include "QLabel"

#define MSGSIZE 16

using namespace std;

Nucleo::Nucleo()
{

}



void Nucleo::construccion(int tallos, int ramas, int hojas, QVector<QLabel*> &misLabels){
    int status, espera, pidd;
    Calculos *calc = new Calculos();
    int hijos = 0;
    for (int i = 0; i < tallos; ++i) {
        QString colorLabel = "QLabel { background-color : black; color : blue; }";
        misLabels.at(calc->calcularNodo(i+1,0,0,1))->setStyleSheet(colorLabel);
        misLabels.at(calc->calcularNodo(i+1,0,0,1))->update();
        Tallo nuevoTallo;
        if(i < this->noTallos){
             nuevoTallo = this->misTallos[i];
         } else {
             //bandera en 1 significa que el tallo esta activado
//             pipe(this->conectores[calc->calcularNodo(i+1,0,0,1)].getConexion());
             nuevoTallo = Tallo(this->conectores[calc->calcularNodo(i+1,0,0,1)], 1);
             nuevoTallo.setMiPid(fork());
             if(nuevoTallo.getMiPid()< 0){
                 perror("Error al hacer el fork");
                 exit(1);
                 break;
             } else if(nuevoTallo.getMiPid() == 0){
                //PROCESO HIJO
                cout << "[tallo] pid "<<getpid() <<" from [programa] pid "<< getppid() << "\n"<<endl;
                nuevoTallo.construccionRamas(this->conectores, tallos, ramas, hojas, *&misLabels);
                break;
             }  else { //PROCESO PADRE
                 //cerrando canal de escucha
                 hijos++;
                 this->misTallos.append(nuevoTallo);
                 this->noTallos++;
            }
        }
    }

}


void Nucleo::construccionRamas(){

}

void Nucleo::construccionHojas(){

}


void Nucleo::inicializarPipes(){
    for (int i = 0; i <= this->totalConectores; ++i) {
        int conexion[2];
      //  pipe(conexion);
        //0 significa que la tuberia esta desactivada
        Pipe miPipe = Pipe(0, conexion);
        this->conectores.append(miPipe);
    }
}




/*GETTERS Y SETTERS*/

void Nucleo::setNoHojas(int noHojas){
    this->noHojas = noHojas;
}

void Nucleo::setNoRamas(int noRamas){
    this->noRamas = noRamas;
}

void Nucleo::setNoTallos(int noTallos){
    this->noTallos = noTallos;
}

int Nucleo::getNoHojas(){
    return noHojas;
}

int Nucleo::getNoRamas(){
    return noRamas;
}

int Nucleo::getNoTallos(){
    return noTallos;
}
