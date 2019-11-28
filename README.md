#ifndef VENTE_H
#define VENTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Vente
{
public:
    Vente();
    Vente(int,int,QString,QDate);
    int get_idp() ;
    int get_vqt() ;
    QString get_client() ;
     QDate get_vdate(int *year ,int *month,int *day) ;
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * cafficher();
    bool supprimer(int);
    bool vmodifier(int iddp) ;

    QSqlQueryModel * getiddp(int idd) ;
    QSqlQueryModel * trier();
     QSqlQueryModel * recherche(QString) ;
     int calculquantiter() ;

private:
    QString client;
    int idp,vqt;
    QDate vdate ;
};

#endif // VENTE_H
