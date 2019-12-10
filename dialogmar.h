#ifndef DIALOGMAR_H
#define DIALOGMAR_H

#include <QDialog>
#include "employe.h"
#include "departement.h"
#include <QDateTime>
#include<QTimer>
namespace Ui {
class Dialogmar;
}

class Dialogmar : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogmar(QWidget *parent = nullptr);
    ~Dialogmar();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();



    void on_pb_ajouter_dep_clicked();



    void on_pb_modif_dep_clicked();



    void on_pb_supp_dep_clicked();

    void on_pb_affecter_conge_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pb_afficher_employe_du_mois_clicked();
    void myfunction();

    void on_pushButton_clicked();

    void on_pb_prime_clicked();

private:
    Ui::Dialogmar *ui;
    employe tmp_employe;
       departement tmp_departement;
        QTimer *timer;
};

#endif // DIALOGMAR_H
