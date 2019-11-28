#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class rayon
{public:
    rayon();
    rayon(int,QString);
    QString get_nom_rayon();

    int get_id_rayon();
    bool ajouter_rayon();
    QSqlQueryModel * afficher_rayon();
    bool supprimer_rayon(QString);
    QSqlQueryModel * afficher_rayon2(QString);
     bool modifier_rayon(QString);
 QSqlQueryModel * afficherNomRayon();
     QSqlQueryModel * filter_rayon(QString);
private:
    QString nom_rayon;
    int id_rayon;
};
#endif // RAYON_H
