#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client
{public:
    Client();
    Client(int,int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_identifiant();
    int get_pt();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * trier();
    bool supprimer(int);
    bool modifier(int);
private:
    QString nom,prenom;
        int identifiant,pt;
};

#endif // CLIENTS_H
