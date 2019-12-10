#ifndef PROMOTION_H
#define PROMOTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>




class promotion
{public:
    promotion();
    promotion(int,int,int,int);
   // QString get_nom_promotion();

    int get_id_promotion();
    bool ajouter_promotion(QString);
    QSqlQueryModel * afficher_promotion();
    QSqlQueryModel * afficherNomPromotion();

    QSqlQueryModel * afficher_promotion2(QString);
    QSqlQueryModel * filterpromo(QString);


    bool supprimer_promotion(QString);
     bool modifier_promotion(QString);

private:

    int id_promo;
    int id_produit;
    int pourcentage ;
    int nouvp ;
};
#endif // PROMOTION_H
