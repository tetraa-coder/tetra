#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{public:
    fournisseur();
    fournisseur(int,QString);
    QString get_nom_fournisseur();

    int get_id_fournisseur();
    bool ajouter_fournisseur();
    QSqlQueryModel * afficher_fournisseur();
    bool supprimer_fournisseur(QString);
    QSqlQueryModel * afficher_fournisseur2(QString);
     bool modifier_fournisseur(QString);
 QSqlQueryModel * afficherNomFournisseur();
     QSqlQueryModel * filter_fournisseur(QString);
private:
    QString nom_fournisseur;
    int id_fournisseur;
};
#endif // FOURNISSEUR_H
