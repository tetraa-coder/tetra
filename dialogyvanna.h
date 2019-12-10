#ifndef DIALOGYVANNA_H
#define DIALOGYVANNA_H
#include "cadeau.h"
#include "clients.h"
#include <QDialog>

namespace Ui {
class Dialogyvanna;
}

class Dialogyvanna : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogyvanna(QWidget *parent = nullptr);
    ~Dialogyvanna();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_supprimer_clicked_cadeaux();


    void on_modif_cadeaux_clicked();

    void on_modifclient_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Dialogyvanna *ui;
    Cadeau tmpcadeau;
        Client tmpclient;
};

#endif // DIALOGYVANNA_H
