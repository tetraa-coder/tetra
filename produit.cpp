#include "produit.h"
#include <QMessageBox>

#include <QDebug>

produit::produit()
{
     nom_prod = "";
    id_prod = 0;
    prix_prod = 0;

     idrayon = 0;

     quantite_prod = 0 ;

}
produit::produit(int id_prod,QString nom_prod,int prix_prod,int quantite_prod,int idrayon)
{
  this->nom_prod = nom_prod;
    this->id_prod = id_prod;
    this->prix_prod = prix_prod ;

     this->idrayon = idrayon;

     this->quantite_prod = quantite_prod ;

}
QString produit::get_nom_produit(){return  nom_prod;}
int produit::get_id_produit(){return  id_prod;}

bool produit::ajouter_produit()
{
QSqlQuery query , q1 , q2;

QString res= QString::number(id_prod);
//q1.prepare(QString("select ID_rayon from rayon where nom_rayon = %1 ").arg(x) );
//q2.prepare(QString("select ID_marque from marque where nom_marque = %1 ").arg(y));
//q1.exec("select  ID_rayon from rayon where NOM_rayon = 'sd");
//q2.exec("select  ID_marque from marque where NOM_marque = 'gucci");
q1.next();
q2.next();

//q1.first();
//q2.first();
//int r1  =  q1.value(0).toInt();
//int r2 = q2.value(1).toInt();

query.prepare("INSERT INTO produit (ID_prod, NOM_prod, PRIX_prod, QUANTITE_prod, ir)"
              " VALUES(:id_prod, :nom_prod, :prix_prod, :quantite_prod, :ir)");//select ID_rayon from rayon where NOM_rayon='sd')");
query.bindValue(":id_prod", res);
query.bindValue(":nom_prod", nom_prod);
query.bindValue(":prix_prod", prix_prod);

query.bindValue(":ir",idrayon );



query.bindValue(":quantite_prod", quantite_prod);


return    query.exec();
}

QSqlQueryModel * produit::afficher_produit()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_prod"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_prod "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_prod "));

model->setHeaderData(6, Qt::Horizontal, QObject::tr("QUANTITE_prod "));



    return model;
}


QSqlQueryModel * produit::afficher_produit2(QString hh)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery(QString("select * from produit1 order by %1 ").arg(hh));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_produit"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit "));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE "));
    return model;
}

QSqlQueryModel * produit::filter_produit(QString hh)
{QSqlQueryModel * model= new QSqlQueryModel();
QString a = "%a%";
    model->setQuery("select * from produit1 where nom_produit  like ' :a ' ");
    model->query().bindValue(":a", a);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit "));
        return model;
}


bool produit::supprimer_produit(QString id)
{
QSqlQuery query;
query.prepare("Delete from produit1 where ID_produit = :idd ");
query.bindValue(":idd", id);
return    query.exec();
}
bool produit::modifier_produit(QString id)
{
    QSqlQuery query;
   // QString res= QString::number(id);
    query.prepare("Update produit1 set  NOM_produit=:nom_produit where id_produit = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":id_produit",id_prod);
    query.bindValue(":nom_produit", nom_prod);

    return  query.exec();

}
