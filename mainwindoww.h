#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cadeau.h"
#include "clients.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_clicked_cadeaux();

    void on_pb_supprimer_clicked_cadeaux();


    void on_modif_cadeaux_clicked();

    void on_modifclient_clicked();

private:
    Ui::MainWindow *ui;
    Cadeau tmpcadeau;
    Client tmpclient;
};

#endif // MAINWINDOW_H


