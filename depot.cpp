#include "depot.h"
#include <QDebug>
#include <QString>

depot::depot()
{
    id=0;
    nom="";
    prenom="";
    cin=0;

}

depot::depot(int i,std::string n,std::string p,int h)
{
    id=i;
    prenom=p;
    cin=h;

    nom=n;

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

int depot::get_id()
{
    return id;
}

std::string depot::get_nom()
{
    return nom;
}

std::string depot::get_prenom()
{
    return prenom;
}

int depot::get_cin()
{
    return cin;
}


bool depot::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO depot (id,nom,prenom,cin)""VALUES(:id,:nom,:prenom,:cin)");
    query.bindValue(":id",id);
    query.bindValue(":nom",QString::fromStdString(nom));
    query.bindValue(":prenom",QString::fromStdString(prenom));
    query.bindValue(":cin",cin);

    return query.exec();
}

QSqlQueryModel * depot::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    //UPDATE tab_employe SET salaires = salaires + 500 WHERE (SELECT ID FROM tab_employe WHERE Checked='N' ORDER BY ID LIMIT 1);ORDER BY heures_s
    model->setQuery("select ID,NOM,PRENOM,CIN FROM DEPOT",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("cin"));

    return model;
}

bool depot::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM depot WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}

bool depot::modifier(QString nom,QString prenom,int cin,int id)
{
    QSqlQuery query;

     query.prepare("UPDATE depot set nom= :nom,prenom= :prenom,cin= :cin where id= :id");
    qDebug() << "depot modifier avec succee" ;


    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
     query.bindValue(":cin",cin);
     query.bindValue(":id",id);


    return query.exec();
}


QSqlQueryModel * depot::afficher_tri()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    //UPDATE tab_employe SET salaires = salaires + 500 WHERE (SELECT ID FROM tab_employe WHERE Checked='N' ORDER BY ID LIMIT 1);ORDER BY heures_s
    model->setQuery("select ID,NOM,PRENOM,CIN FROM DEPOT order by id",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
     return model;


}
