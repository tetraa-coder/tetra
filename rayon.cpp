#include "rayon.h"
#include <QDebug>
rayon::rayon()
{
id_rayon=0;
nom_rayon="";

}
rayon::rayon(int id_rayon,QString nom_rayon)
{
  this->id_rayon=id_rayon;
  this->nom_rayon=nom_rayon;

}
QString rayon::get_nom_rayon(){return  nom_rayon;}
int rayon::get_id_rayon(){return  id_rayon;}

bool rayon::ajouter_rayon()
{
QSqlQuery query;
QString res= QString::number(id_rayon);
query.prepare("INSERT INTO rayon (ID_rayon, NOM_rayon) "
                    "VALUES (:id_rayon, :nom_rayon)");
query.bindValue(":id_rayon", res);
query.bindValue(":nom_rayon", nom_rayon);


return    query.exec();
}

QSqlQueryModel * rayon::afficher_rayon()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rayon");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_rayon"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_rayon "));
    return model;
}

bool rayon::supprimer_rayon(QString id)
{
QSqlQuery query;
query.prepare("Delete from rayon where ID_rayon = :idd ");
query.bindValue(":idd", id);
return    query.exec();
}
bool rayon::modifier_rayon(QString id)
{
    QSqlQuery query;
   // QString res= QString::number(id);
    query.prepare("Update rayon set  NOM_rayon=:nom_rayon where id_rayon = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":id_rayon",id_rayon);
    query.bindValue(":nom_rayon", nom_rayon);

    return  query.exec();

}


QSqlQueryModel * rayon::afficher_rayon2(QString aa){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery(QString("select * from rayon order by %1 ").arg(aa));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_rayon"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_rayon "));
    return model;
}

QSqlQueryModel * rayon::filter_rayon(QString hh)
{QSqlQueryModel * model= new QSqlQueryModel();
QString a = "%a%";
    model->setQuery("select * from rayon where nom_rayon  like ' :a ' ");
    model->query().bindValue(":a", a);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_rayon"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_rayon "));
        return model;
}

QSqlQueryModel * rayon::afficherNomRayon()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select nom_rayon from rayon");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_rayon"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_rayon "));
    return model;
}


