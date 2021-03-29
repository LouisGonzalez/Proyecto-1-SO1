#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <QVector>

#ifndef PIPE_H
#define PIPE_H


class Pipe
{
public:
    Pipe();
    Pipe(int,int[2]);

    void setInterruptor(int interruptor);
    int getInterruptor();
    void setConexion(int[2]);
    int* getConexion();

private:
    int interruptor;
    int conexion[2];

};

#endif // PIPE_H
