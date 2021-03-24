#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include <string>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Verifica se a coordenada não está ocupada por um trem
    bool podeMover(int x, int y);

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

    Trem* listaTrem[5];

};
#endif // MAINWINDOW_H
