#include "hilos.h"
#include <QtCore>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sstream>

Hilos::Hilos(QObject *parent) : QThread(parent)
{

}


void Hilos::run(){
   qDebug("Run");
   bool aux=true;
   qDebug("Buscando Planta%d\n",planta);
   while (true) {
       qDebug("Buscando Planta%d\n",planta);
       while ( planta!=0) {
           qDebug("Color");
           string myText="";
           std::ostringstream s;
            s<< "Planta"<<planta<<"/color";
            std:: string plantaFileColor(s.str());

           // Read from the text file
           ifstream MyReadFile;
                   MyReadFile.open(plantaFileColor);
           if(MyReadFile){
               while (getline (MyReadFile, myText)) {
                 // Output the text from the file
                 cout << myText;
               }
               if(myText.length()>0){
                   stringstream geek(myText);
                   int x = 0;
                       geek >> x;
                       qDebug("Color--");
              //        emit NuevoColor(x,0,0);
               }

           }

               this->sleep(1);
       }

       this->sleep(1);
   }

}
