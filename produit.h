#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>




class produit
{public:
    produit();
    produit(int,QString,int,int,int);
    QString get_nom_produit();

    int get_id_produit();

    bool ajouter_produit();
    QSqlQueryModel * afficher_produit();
   // QSqlQueryModel * afficherNomMarque();

    QSqlQueryModel * afficher_produit2(QString);
    QSqlQueryModel * filter_produit(QString);


    bool supprimer_produit(QString);
     bool modifier_produit(QString);

private:
    QString nom_prod;
    int id_prod;
    int prix_prod;
    int idrayon;


    int quantite_prod ;
};
#endif // PRODUIT_H
