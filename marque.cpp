#include "marque.h"

#include <QDebug>

marque::marque()
{
id_marque=0;
nom_marque="";

}
marque::marque(int id_marque,QString nom_marque)
{
  this->id_marque=id_marque;
  this->nom_marque=nom_marque;

}
QString marque::get_nom_marque(){return  nom_marque;}
int marque::get_id_marque(){return  id_marque;}

bool marque::ajouter_marque()
{
QSqlQuery query;
QString res= QString::number(id_marque);
query.prepare("INSERT INTO marque (ID_marque, NOM_marque) "
                    "VALUES (:id_marque, :nom_marque)");
query.bindValue(":id_marque", res);
query.bindValue(":nom_marque", nom_marque);


return    query.exec();
}

QSqlQueryModel * marque::afficher_marque()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from marque");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_marque"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_marque "));
    return model;
}
QSqlQueryModel * marque::afficherNomMarque()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select nom_marque from marque");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_marque"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_marque "));
    return model;
}

QSqlQueryModel * marque::afficher_marque2(QString hh)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery(QString("select * from marque order by %1 ").arg(hh));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_marque"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_marque "));
    return model;
}

QSqlQueryModel * marque::filter(QString hh)
{QSqlQueryModel * model= new QSqlQueryModel();
QString a = "%a%";
    model->setQuery("select * from marque where nom_marque  like ' :a ' ");
    model->query().bindValue(":a", a);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_marque"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_marque "));
        return model;
}


bool marque::supprimer_marque(QString id)
{
QSqlQuery query;
query.prepare("Delete from marque where ID_marque = :idd ");
query.bindValue(":idd", id);
return    query.exec();
}
bool marque::modifier_marque(QString id)
{
    QSqlQuery query;
   // QString res= QString::number(id);
    query.prepare("Update marque set  NOM_marque=:nom_marque where id_marque = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":id_marque",id_marque);
    query.bindValue(":nom_marque", nom_marque);

    return  query.exec();

}



//svn
