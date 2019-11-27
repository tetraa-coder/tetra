#include "departement.h"
departement::departement(){
     nbr=0;
     id=0;
     nom_chef="";
     nom_dep="";

}
departement::departement(int n,int i,std::string c,std::string d){
     nbr=n;
     id=i;
     nom_chef=c;
     nom_dep=d;

}
int departement::get_nbr(){return nbr;}
int departement::get_id(){return id;}
std::string departement::get_nom_chef(){return nom_chef;}
std::string departement::get_nom_dep(){return nom_dep;}

departement::~departement()
{

}
bool departement::ajouter_dep()
{
    QSqlQuery query;

    query.prepare("INSERT INTO tab_departement (nbr,id,nom_chef,nom_dep)""VALUES(:nbr,:id,:nom_chef,:nom_dep)");
    query.bindValue(":id",id);
    query.bindValue(":nbr",nbr);
    query.bindValue(":nom_dep",QString::fromStdString (nom_dep));
    query.bindValue(":nom_chef",QString::fromStdString(nom_chef));
    return query.exec();
}
QSqlQueryModel * departement::afficher_dep()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    model->setQuery("select ID,NOM_DEP,NOM_chef,NBR FROM tab_departement",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_DEPARTEMENT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_CHEF"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NBR"));
    return model;
}
bool departement::supprimer_dep(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tab_departement WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool departement::modifier_dep(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE tab_departement SET  nbr= :nbr, nom_dep= :nom_dep , nom_chef= :nom_chef  WHERE id= :id");
    query.bindValue(":id",id);
    query.bindValue(":nbr",nbr);
    query.bindValue(":nom_dep",QString::fromStdString(nom_dep));
    query.bindValue(":nom_chef",QString::fromStdString(nom_chef));
    return query.exec();
}

