#include "creaciones.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "QString"
#include "QTextEdit"
#include <iostream>
#include <vector>
#include "tallo.h"

using namespace std;


Creaciones::Creaciones()
{

}
/*
void Creaciones::crearTallos(int tallos, int ramas, int hojas){

    int status;
    for (int i = 0; i < tallos; i++) {


        Tallo nuevoTallo;
        //significa que el tallo no existe dentro de la aplicacion
        if(i > this->noTallos){
            int conexion[2];
            pipe(conexion);
            nuevoTallo = Tallo(conexion, 0);
            status = fork();
            if(status == 0) {
                //agregar ramas
                //cout << "[tallo] pid "<<getpid() <<" from [programa] pid "<< getppid() <<"\n"<<endl;
                //crearRamas(ramas, hojas);
                nuevoTallo.iniciarEspera();
                sleep(100);
                break;
            }
            this->misTallos.append(nuevoTallo);
            this->noTallos++;
        } else if(i < this->noTallos){
            nuevoTallo = this->misTallos.at(i);
        }
    }

    if(tallos < this->noTallos){
        for (int i = tallos; i < noTallos; ++i) {
            this->misTallos[i].setBandera(1);


        }
    }

}*/


void Creaciones::crearRamas(int ramas, int hojas){
    int status;
    for (int i = 0; i < ramas; i++) {
        status = fork();
        if(status == 0){
            //agregar hojas
            cout << "\t[rama] pid "<<getpid() <<" from [tallo] pid "<< getppid() <<"\n"<<endl;
            sleep(100);
            break;
        }
    }
}

void Creaciones::crearHojas(int hojas){
    int status;
    for (int i = 0; i < hojas; ++i) {
        status = fork();
        if(status == 0){
            cout << "[hoja] pid "<<getpid() <<" from [rama] pid "<< getppid() <<"\n"<<endl;
            sleep(100);
            break;
        }
    }
}
