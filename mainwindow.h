#include "QVector"
#include "QLabel"
#include "graficos.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void inicializarLabels();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnAccion_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> misLabels;

};

#endif // MAINWINDOW_H
