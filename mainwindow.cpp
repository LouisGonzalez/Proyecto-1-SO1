#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QString"
#include <QStringList>
#include <string>
#include "creaciones.h"
#include "nucleo.h"
#include "graficos.h"
#include "QMessageBox"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAccion_clicked()
{
    this->inicializarLabels();
    Creaciones *creando = new Creaciones();
    Nucleo *nucleo = new Nucleo();
    nucleo->inicializarPipes();
    QString parametros = ui->txtEntrada->toPlainText();
    parametros.remove(')');
    parametros.remove('(');
    QList<QString> lista = parametros.split(",");
    if(lista.size() <= 4){
        QString total;
        total.setNum(lista.size());
        ui->prueba->setText(total);
        if(lista.size() == 2){
            if(lista[0] == "P"){
                //METODO
            } else if(lista[0] == "M"){
                //METODO
            } else if(lista[0] == "I"){
                //METODO
            }
        } else if(lista.size() == 3){
            nucleo->construccion(lista.at(1).toInt(), lista.at(2).toInt(), 0, *&this->misLabels);
        } else if(lista.size() == 4){
            nucleo->construccion(lista.at(1).toInt(),lista.at(2).toInt(),lista.at(3).toInt(), *&this->misLabels);
        }
    } else {
        ui->prueba->setText("error en parametros");
        QMessageBox error;
        error.setText("Error dentro de los parametros");
        error.exec();
    }
}

void MainWindow::inicializarLabels(){

    this->misLabels.append(*&ui->label);
    this->misLabels.append(*&ui->label_2);
    this->misLabels.append(*&ui->label_3);
    this->misLabels.append(*&ui->label_4);
    this->misLabels.append(*&ui->label_5);
    this->misLabels.append(*&ui->label_6);
    this->misLabels.append(*&ui->label_7);
    this->misLabels.append(*&ui->label_12);
    this->misLabels.append(*&ui->label_8);
    this->misLabels.append(*&ui->label_9);
    this->misLabels.append(*&ui->label_10);
    this->misLabels.append(*&ui->label_11);
    this->misLabels.append(*&ui->label_37);
    this->misLabels.append(*&ui->label_42);
    this->misLabels.append(*&ui->label_41);
    this->misLabels.append(*&ui->label_38);
    this->misLabels.append(*&ui->label_36);
    this->misLabels.append(*&ui->label_44);
    this->misLabels.append(*&ui->label_35);
    this->misLabels.append(*&ui->label_45);
    this->misLabels.append(*&ui->label_39);
    this->misLabels.append(*&ui->label_40);
    this->misLabels.append(*&ui->label_43);
    this->misLabels.append(*&ui->label_15);
    this->misLabels.append(*&ui->label_22);
    this->misLabels.append(*&ui->label_14);
    this->misLabels.append(*&ui->label_16);
    this->misLabels.append(*&ui->label_19);
    this->misLabels.append(*&ui->label_20);
    this->misLabels.append(*&ui->label_21);
    this->misLabels.append(*&ui->label_18);
    this->misLabels.append(*&ui->label_17);
    this->misLabels.append(*&ui->label_23);
    this->misLabels.append(*&ui->label_13);
    this->misLabels.append(*&ui->label_48);
    this->misLabels.append(*&ui->label_53);
    this->misLabels.append(*&ui->label_52);
    this->misLabels.append(*&ui->label_49);
    this->misLabels.append(*&ui->label_47);
    this->misLabels.append(*&ui->label_55);
    this->misLabels.append(*&ui->label_46);
    this->misLabels.append(*&ui->label_56);
    this->misLabels.append(*&ui->label_50);
    this->misLabels.append(*&ui->label_51);
    this->misLabels.append(*&ui->label_54);
    this->misLabels.append(*&ui->label_26);
    this->misLabels.append(*&ui->label_33);
    this->misLabels.append(*&ui->label_25);
    this->misLabels.append(*&ui->label_27);
    this->misLabels.append(*&ui->label_30);
    this->misLabels.append(*&ui->label_31);
    this->misLabels.append(*&ui->label_32);
    this->misLabels.append(*&ui->label_29);
    this->misLabels.append(*&ui->label_28);
    this->misLabels.append(*&ui->label_34);
    this->misLabels.append(*&ui->label_24);


}
