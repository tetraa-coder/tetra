#include "achat.h"
#include <QDebug>
Achat::Achat()
{
    ida=0 ;
    aqt=0 ;
    fournisseur="" ;

}

Achat::Achat(int ida,int aqt,QString fournisseur, QDate adate)
{
    this->ida=ida;
    this->aqt=aqt;
    this->fournisseur=fournisseur;
    this->adate=adate ;

}


int Achat::get_ida(){return  ida;}
int Achat::get_aqt(){return aqt;}
QString Achat::get_fournisseur(){return  fournisseur;}
QDate Achat::get_adate(int *year,int *month,int *day){return adate ;}


bool Achat::ajouter()
{
QSqlQuery query;
QString res= QString::number(ida);
query.prepare("INSERT INTO achat (IDA, AQT, FOURNISSEUR, ADATE) "
                    "VALUES (:ida, :aqt, :fournisseur,:adate)");
query.bindValue(":ida", res);
query.bindValue(":aqt", aqt);
query.bindValue(":fournisseur", fournisseur);
query.bindValue(":adate", adate);

return    query.exec();
}

QSqlQueryModel * Achat::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM ACHAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantiter"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d'achat"));
    return model;
}


bool Achat::supprimer(int idd)
{
    int in =idd ;
QSqlQuery query;
query.prepare("Delete from ACHAT where ROWNUM = :in ");
query.bindValue(":in", in);
return    query.exec();
}

QSqlQueryModel * Achat::fafficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT NOM FROM FOURNISSEUR");

    return model;
}

bool Achat::amodifier(int iddp)
{
QSqlQuery query;
    QString res= QString::number(iddp);
    query.prepare("update achat set IDA=:idp, AQT=:aqt,FOURNISSEUR=:fournisseur,ADATE=:adate where IDA=:idp") ;
    query.bindValue(":idp", res);
    query.bindValue(":vqt", aqt);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":adate",adate) ;

    return query.exec();
}

QSqlQueryModel * Achat::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM ACHAT ORDER BY FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantiter"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d' achat"));
    return model;
}
