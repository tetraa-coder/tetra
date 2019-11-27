#include "employe.h"
#include <QDebug>

employe::employe()
{
    id=0;
    nom="";
    prenom="";
    heures=0;
    heures_s=0;
    salaire=0;
}

employe::employe(int i,std::string n,std::string p,int h,int hs,int s)
{
    id=i;
    prenom=p;
    heures=h;
    heures_s=hs;
    nom=n;
    salaire=s;
}
/*employe::employe(int i,std::string n,std::string p,int h,int hs,int s,int c)
{
    id=i;
    prenom=p;
    heures=h;
    heures_s=hs;
    nom=n;
    salaire=s;
    conge=c;
}
int employe::get_conge(){

    return conge;
}*/

int employe::get_id()
{
    return id;
}

std::string employe::get_nom()
{
    return nom;
}

std::string employe::get_prenom()
{
    return prenom;
}

int employe::get_heures()
{
    return heures;
}

int employe::get_heures_s()
{
    return heures_s;
}
int employe::get_salaire()
{return salaire;}
bool employe::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO tab_employe (id,nom,prenom,heures,heures_s,salaire)""VALUES(:id,:nom,:prenom,:heures,:heures_s,:salaire)");
    query.bindValue(":id",id);
    query.bindValue(":nom",QString::fromStdString(nom));
    query.bindValue(":prenom",QString::fromStdString(prenom));
    query.bindValue(":heures",heures);
    query.bindValue(":heures_s",heures_s);
    query.bindValue(":salaire",salaire);
    return query.exec();
}

QSqlQueryModel * employe::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    //UPDATE tab_employe SET salaires = salaires + 500 WHERE (SELECT ID FROM tab_employe WHERE Checked='N' ORDER BY ID LIMIT 1);ORDER BY heures_s
    model->setQuery("select ID,NOM,PRENOM,HEURES,HEURES_S,SALAIRE FROM tab_employe",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEURES"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("HEURES_S"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("SALAIRE"));
    return model;
}

bool employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tab_employe WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}

bool employe::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE tab_employe SET salaire= :salaire, heures_s= :heures_s, heures= :heures, prenom= :prenom, nom= :nom WHERE id= :id");
    qDebug() << "employe modifier avec succee" ;
    query.bindValue(":id",id);
    query.bindValue(":nom",QString::fromStdString(nom));
    query.bindValue(":prenom",QString::fromStdString(prenom)) ;
    query.bindValue(":heures",heures);
    query.bindValue(":heures_s",heures_s);
    query.bindValue(":salaire",salaire);
    return query.exec();
}
/*bool employe::affecter_conge(int id,employe e,int congex){
     QSqlQuery query;
     query.prepare("SELECT * from tab_employe where id =:id");
     query.bindValue(":id",id);
      query.bindValue(":conge",conge);
      query.bindValue(":nom",QString::fromStdString(e.get_nom()));
      query.bindValue(":prenom",QString::fromStdString(e.get_prenom()));
      query.bindValue(":heures",e.get_heures());
      query.bindValue(":heures_s",e.get_heures_s());
      query.bindValue(":salaire",e.get_salaire());

      return query.exec();
}
QSqlQueryModel * employe::afficher_conge(){

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();

    model->setQuery("select ID,NOM,PRENOM,HEURES,HEURES_S,SALAIRE,CONGE FROM tab_employe",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEURES"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("HEURES_S"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("SALAIRE"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("CONGE"));
    return model;
}*/
/*QSqlQueryModel * employe::select_e()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    //UPDATE tab_employe SET salaires = salaires + 500 WHERE (SELECT ID FROM tab_employe WHERE Checked='N' ORDER BY ID LIMIT 1);ORDER BY heures_s
    model->setQuery("SELECT ID,NOM,PRENOM,HEURES,HEURES_S,SALAIRE FROM tab_employe ORDER BY heures",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEURES"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("HEURES_S"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("SALAIRE"));
    return model;
}*/
