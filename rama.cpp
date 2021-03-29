#include "rama.h"
#include "pipe.h"
#include "calculos.h"
#include "hoja.h"
#include "QVector"
#include <stdio.h>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "QLabel"
#include <iostream>
#include <unistd.h>

using namespace std;

rama::rama()
{

}



rama::rama(Pipe conexion, int bandera){
    this->conexion = conexion;
    this->bandera = bandera;
}


void rama::construccionHojas(QVector<Pipe> conexiones, int tallos, int ramas, int hojas, QVector<QLabel*> &misLabels){
    char buffer[16];
    int noBytes;
    int hijos = 0;
    Calculos *calc = new Calculos();
    int status, espera, pidd;
    for (int i = 0; i < hojas; ++i) {
        QString iterador;
        iterador.setNum(calc->calcularNodo(tallos,ramas,i+1,3));
        QString colorLabel = "QLabel { background-color : red; color : blue; }";
        misLabels.at(calc->calcularNodo(tallos,ramas,i+1,3))->setStyleSheet(colorLabel);
        misLabels.at(calc->calcularNodo(tallos,ramas,i+1,3))->update();
        Hoja nuevaHoja;
        if(i < this->noHojas){
            nuevaHoja = this->misHojas.at(i);
        } else {
            nuevaHoja = Hoja(conexiones.at(calc->calcularNodo(tallos+1, ramas+1, i+1, 3)), 1);
            nuevaHoja.setMiPid(fork());
            if(nuevaHoja.getMiPid() == -1){
                perror("Error al hacer el fork");
                exit(1);
                break;
            } else if(nuevaHoja.getMiPid() == 0){
                //PROCESO HIJO
                cout << "\t\t[hoja] pid "<<getpid() <<" from [rama] pid "<< getppid() <<"\n"<<endl;
                break;
            }  else {
                hijos++;
                this->misHojas.append(nuevaHoja);
                this->noHojas++;
            }
        }
    }

}


/*GETTERS Y SETTERS*/

void rama::setBandera(int bandera){
    this->bandera = bandera;
}

int rama::getBandera(){
   return this->bandera;
}

void rama::setPipe(Pipe miPipe){
    this->conexion = miPipe;
}

Pipe rama::getPipe(){
    return this->conexion;
}

void rama::setMiPid(int miPid){
    this->miPid = miPid;
}

int rama::getMiPid(){
    return this->miPid;
}
