#ifndef DIALOG_H
#define DIALOG_H
#include "categorie.h"
#include "fournisseur.h"
#include <QObject>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_6_clicked();

    void on_modifiercat_clicked();

    void on_filter_textChanged(const QString &arg1);

    void on_affichercategorie_clicked();


    void on_ajouterfournisseur_clicked();


    void on_supp_fournisseur_clicked();

    void on_modifiercat_2_clicked();

    void on_modifier_fournisseur_clicked();

    void on_afficher_fournisseur_clicked();

    void on_filter_2_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    categorie tmpcategorie ;
    fournisseur tmpfournisseur;
    categorie tmpcombo ;
};

#endif // DIALOG_H
