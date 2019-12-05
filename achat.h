#ifndef ACHAT_H
#define ACHAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Achat
{
public:
    Achat();
    Achat(int,int,QString,QDate);
    int get_ida() ;
    int get_aqt() ;
    QString get_fournisseur() ;
     QDate get_adate(int *year ,int *month,int *day) ;
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * fafficher();
    bool supprimer(int);
    bool amodifier(int iddp) ;
     QSqlQueryModel * trier();
private:
    QString fournisseur;
    int ida,aqt;
    QDate adate ;
};

#endif // ACHAT_H
