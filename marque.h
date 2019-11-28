#ifndef MARQUE_H
#define MARQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>




class marque
{public:
    marque();
    marque(int,QString);
    QString get_nom_marque();

    int get_id_marque();
    bool ajouter_marque();
    QSqlQueryModel * afficher_marque();
    QSqlQueryModel * afficherNomMarque();

    QSqlQueryModel * afficher_marque2(QString);
    QSqlQueryModel * filter(QString);


    bool supprimer_marque(QString);
     bool modifier_marque(QString);

private:
    QString nom_marque;
    int id_marque;
};
#endif // MARQUE_H
