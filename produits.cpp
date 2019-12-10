#include "produits.h"
produits::produits(){
     nbr=0;
     id=0;
     nom_type="";
     nom_produit="";

}
produits::produits(int n,int i,std::string t,std::string p){
     nbr=n;
     id=i;
     nom_type=t;
     nom_produit=p;

}
int produits::get_nbr(){return nbr;}
int produits::get_id(){return id;}
std::string produits::get_nom_type(){return nom_type;}
std::string produits::get_nom_produit(){return nom_produit;}

produits::~produits()
{

}
bool produits::ajouter_produit()
{
    QSqlQuery query;

    query.prepare("INSERT INTO tab_produit (nbr,id,nom_type,nom_produit)""VALUES(:nbr,:id,:nom_type,:nom_produit)");
    query.bindValue(":id",id);
    query.bindValue(":nbr",nbr);
    query.bindValue(":nom_produit",QString::fromStdString (nom_produit));
    query.bindValue(":nom_type",QString::fromStdString(nom_type));
    return query.exec();
}
QSqlQueryModel * produits::afficher_produit()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    model->setQuery("select nbr,ID,NOM_type,NOM_produit FROM tab_produit",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NBR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_produit"));
    return model;
}
bool produits::supprimer_produit(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tab_produit WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool produits::modifier_produit(int id,int nbr,QString nom_produit,QString nom_type)
{
    QSqlQuery query;
    query.prepare("UPDATE tab_produit SET  nbr= :nbr, nom_type= :nom_type , nom_produit= :nom_produit  WHERE id= :id");
    query.bindValue(":id",id);
    query.bindValue(":nbr",nbr);
    query.bindValue(":nom_type",nom_type);
    query.bindValue(":nom_produit",nom_produit);
    return query.exec();
}
QSqlQueryModel * produits::recherche_produit(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from tab_produit where(id LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
        return model;
}

