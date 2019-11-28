#include "clients.h"
#include <QDebug>
Client::Client()
{
identifiant=0;
nom="";
prenom="";
}
Client::Client(int identifiant,int pt,QString nom,QString prenom)
{
  this->identifiant=identifiant;
  this->nom=nom;
    this->prenom=prenom;
    this->pt=pt;
}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_identifiant(){return  identifiant;}
int Client::get_pt(){return  pt;}

bool Client::ajouter()
{
QSqlQuery query;
QString res= QString::number(identifiant);
query.prepare("INSERT INTO client (IDENTIFIANT, NOM, PRENOM,PT) "
                    "VALUES (:identfiant, :nom, :prenom, :pt)");
query.bindValue(":identifiant", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":pt", pt);

return    query.exec();
}

bool Client::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("UPDATE client SET NOM=:nom, PRENOM=:prenom, PT=:pt where IDENTIFIANT=:identifiant)");
query.bindValue(":identifiant", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":pt", pt);

return    query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Points"));
    return model;
}

QSqlQueryModel * Client::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client order by pt");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool Client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where IDENTIFIANT = :identifiant ");
query.bindValue(":identifiant", res);
return    query.exec();
}


