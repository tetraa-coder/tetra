#ifndef DIALOGYUSSEF_H
#define DIALOGYUSSEF_H

#include <QDialog>
#include "depot.h"
#include "produits.h"
namespace Ui {
class Dialogyussef;
}

class Dialogyussef : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogyussef(QWidget *parent = nullptr);
    ~Dialogyussef();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();



    void on_pb_ajouter_produit_clicked();



    void on_pb_modif_produit_clicked();

    void on_pb_supp_produit_clicked();

    void on_pb_affecter_conge_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pb_afficher_employe_du_mois_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_ajouter_dep_clicked();

    void on_pb_modif_dep_clicked();

    void on_pb_supp_dep_clicked();

    void on_pushButton_rechercher_clicked();
private:
    Ui::Dialogyussef *ui;
    depot tmp_dep;
        produits tmp_produit;
};

#endif // DIALOGYUSSEF_H
