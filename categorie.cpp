#include"categorie.h"
#include <QDebug>

categorie::categorie()
{
id_categorie=0;
nom_categorie="";

}
categorie::categorie(int id_categorie,QString nom_categorie)
{
  this->id_categorie=id_categorie;
  this->nom_categorie=nom_categorie;

}
QString categorie::get_nom_categorie(){return  nom_categorie;}
int categorie::get_id_categorie(){return  id_categorie;}

bool categorie::ajouter_categorie()
{
QSqlQuery query;
QString res= QString::number(id_categorie);
query.prepare("INSERT INTO categorie (ID_categorie, NOM_categorie) "
                    "VALUES (:id_categorie, :nom_categorie)");
query.bindValue(":id_categorie", res);
query.bindValue(":nom_categorie", nom_categorie);


return    query.exec();
}

QSqlQueryModel * categorie::afficher_categorie()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from categorie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_categorie "));
    return model;
}
QSqlQueryModel * categorie::afficherNomcategorie()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select nom_categorie from categorie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_categorie "));
    return model;
}

QSqlQueryModel * categorie::trier_categorie2(QString hh)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery(QString("select * from categorie order by %1 ").arg(hh));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_categorie"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_categorie "));
    return model;
}

QSqlQueryModel *categorie::filter(QString hh)
{QSqlQueryModel * model= new QSqlQueryModel();
QString a = "%a%";
    model->setQuery("select * from categorie where nom_categorie  like ' :a ' ");
    model->query().bindValue(":a", a);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_categorie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_categorie "));
        return model;
}


bool categorie::supprimer_categorie(QString id)
{
QSqlQuery query;
query.prepare("Delete from categorie where ID_categorie = :idd ");
query.bindValue(":idd", id);
return    query.exec();
}
bool categorie::modifier_categorie(QString id)
{
    QSqlQuery query;
   // QString res= QString::number(id);
    query.prepare("Update categorie set  NOM_categorie=:nom_categorie where id_categorie = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":id_categorie",id_categorie);
    query.bindValue(":nom_categorie", nom_categorie);

    return  query.exec();

}

QSqlQueryModel * categorie::afficher_categorie2(QString hh)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery(QString("select * from categorie order by %1 ").arg(hh));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_categorie"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_categorie "));
    return model;
}


