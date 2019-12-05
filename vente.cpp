#include "vente.h"
#include <QDebug>

Vente::Vente()
{
    idp=0 ;
    vqt=0 ;
    client="" ;
}

Vente::Vente(int idp,int vqt,QString client, QDate vdate)
{
    this->idp=idp;
    this->vqt=vqt;
    this->client=client;
    this->vdate=vdate ;

}


int Vente::get_idp(){return  idp;}
int Vente::get_vqt(){return vqt;}
QString Vente::get_client(){return  client;}
//QString Vente::get_vdate(){return vdate;}

QDate Vente::get_vdate(int *year,int *month,int *day){return vdate ;}


bool Vente::ajouter()
{
QSqlQuery query;
QString res= QString::number(idp);
query.prepare("INSERT INTO vente (IDP, VQT, CLIENT,VDATE) "
                    "VALUES (:idp, :vqt, :client,:vdate)");
query.bindValue(":idp", res);
query.bindValue(":vqt", vqt);
query.bindValue(":client", client);
query.bindValue(":vdate", vdate);

return    query.exec();
}

QSqlQueryModel * Vente::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM VENTE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quntiter"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Client"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de vente"));
    return model;
}

bool Vente::supprimer(int idd)
{
    int in =idd ;
QSqlQuery query;
query.prepare("Delete from vente where ROWNUM = :in ");
query.bindValue(":in", in);
return    query.exec();
}

QSqlQueryModel * Vente::cafficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT NOM, PRENOM FROM CLIENT");

    return model;
}

bool Vente::vmodifier(int iddp)
{
QSqlQuery query;
    QString res= QString::number(iddp);
    query.prepare("update vente set IDP=:idp, VQT=:vqt,CLIENT=:client,VDATE=:vdate where IDP=:idp") ;
    query.bindValue(":idp", res);
    query.bindValue(":vqt", vqt);
    query.bindValue(":client", client);
    query.bindValue(":vdate",vdate) ;

    return query.exec();
}

QSqlQueryModel * Vente::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM VENTE ORDER BY CLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantiter"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Client"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de vente"));
    return model;
}



int Vente::calculquantiter()
{

    QSqlQuery query;
        int qt;
      qt= query.exec("SELECT SUM(VQT) FROM VENTE");
          return qt ;

}
