#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include "estado.h"
#include <math.h>
#include <deque>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::deque<Trem*> listaTrens;

public slots:
    void updateInterface(int,int,int);

private slots:
    void on_btncomecar_clicked();

    void on_btnparar_clicked();

    void on_controle1_sliderReleased();

    void on_controle2_sliderReleased();

    void on_controle3_sliderReleased();

    void on_controle4_sliderReleased();

    void on_controle5_sliderReleased();

private:
    Ui::MainWindow *ui;

    Estado* estado;

    float transformarValor(int entrada);
    void popularEstadoTrens();
    void popularBlocosAreaCritica();
    void atualizarEstadoTrem(int index);
    void verificarAreaCritica();
};

#endif // MAINWINDOW_H
