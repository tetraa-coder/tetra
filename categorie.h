#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>




class categorie
{public:
    categorie();
    categorie(int,QString);
    QString get_nom_categorie();

    int get_id_categorie();
    bool ajouter_categorie();
    QSqlQueryModel * afficher_categorie();
     QSqlQueryModel * afficher_categorie2(QString);
    QSqlQueryModel * afficherNomcategorie();

    QSqlQueryModel * trier_categorie2(QString);
    QSqlQueryModel * filter(QString);


    bool supprimer_categorie(QString);
     bool modifier_categorie(QString);

private:
    QString nom_categorie;
    int id_categorie;
};
#endif // CATEGORIE_H
