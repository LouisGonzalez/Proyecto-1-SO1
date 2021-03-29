#include "tallo.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "rama.h"
#include "pipe.h"
#include "QVector"
#include "calculos.h"
#include <stdio.h>
#include <bits/stdc++.h>
#include "QLabel"

using namespace std;

Tallo::Tallo()
{

}

Tallo::Tallo(Pipe conexion, int bandera){
    this->conexion = conexion;
    this->bandera = bandera;
}

void Tallo::construccionRamas(QVector<Pipe> conexiones, int tallos, int ramas, int hojas, QVector<QLabel*> &misLabels){
    char buffer[16];
    int noBytes;
    int hijos = 0;
    Calculos *calc = new Calculos();
    int status, espera, pidd;
    QString cadena = QString(buffer);
    for (int i = 0; i < ramas; ++i) {
        QString colorLabel = "QLabel { background-color : blue; color : black; }";
        misLabels.at(calc->calcularNodo(tallos,i+1,0,2))->setStyleSheet(colorLabel);
        QString no;
        no.setNum(calc->calcularNodo(tallos,i+1,0,2));
        misLabels.at(calc->calcularNodo(tallos,i+1,0,2))->setText(no);
        misLabels.at(calc->calcularNodo(tallos,i+1,0,2))->update();
        rama nuevaRama;
        if (i < this->noRamas) {
            nuevaRama =  this->misRamas.at(i);
        } else {
            nuevaRama = rama(conexiones.at(calc->calcularNodo(tallos+1,i+1,0,2)), 1);
            nuevaRama.setMiPid(fork());
            if(nuevaRama.getMiPid() == -1){
                perror("Error al hacer el fork");
                exit(1);
                break;
            } else if(nuevaRama.getMiPid() == 0){
                //PROCESO HIJO
                cout << "\t[rama] pid "<<getpid() <<" from [tallo] pid "<< getppid() <<"\n"<<endl;
                nuevaRama.construccionHojas(conexiones, tallos, i+1, hojas, misLabels);
                break;
            } else {
                hijos++;
                this->misRamas.append(nuevaRama);
                this->noRamas++;
            }
        }
    }
}


/*GETTERS Y SETTERS*/

int Tallo::getBandera(){
    return this->bandera;
}

void Tallo::setBandera(int bandera){
    this->bandera = bandera;
}

int Tallo::getMiPid(){
    return this->miPid;
}

void Tallo::setMiPid(int miPid){
    this->miPid = miPid;
}

Pipe Tallo::getPipe(){
    return this->conexion;
}

void Tallo::setPipe(Pipe miPipe){
    this->conexion = miPipe;
}



