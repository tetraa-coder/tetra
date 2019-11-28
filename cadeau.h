#ifndef CADEAU_H
#define CADEAU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Cadeau
{public:
    Cadeau();
    Cadeau(int,int,QString,float);
    QString get_type();
    float get_prix();
    int get_id();
    int get_points();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    bool affecter;
    Cadeau(00000000int,int,int);
    QSqlQueryModel * verifier(QString);
private:
    QString type;
    float prix;
    int point;
    int id;
};

#endif // CADEAU_H

