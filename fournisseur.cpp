#include "fournisseur.h"
#include <QDebug>
fournisseur::fournisseur()
{
id_fournisseur=0;
nom_fournisseur="";

}
fournisseur::fournisseur(int id_fournisseur,QString nom_fournisseur)
{
  this->id_fournisseur=id_fournisseur;
  this->nom_fournisseur=nom_fournisseur;

}
QString fournisseur::get_nom_fournisseur(){return  nom_fournisseur;}
int fournisseur::get_id_fournisseur(){return  id_fournisseur;}

bool fournisseur::ajouter_fournisseur()
{
QSqlQuery query;
QString res= QString::number(id_fournisseur);
query.prepare("INSERT INTO fournisseur (ID_fournisseur, NOM_fournisseur) "
                    "VALUES (:id_fournisseur, :nom_fournisseur)");
query.bindValue(":id_fournisseur", res);
query.bindValue(":nom_fournisseur", nom_fournisseur);


return    query.exec();
}

QSqlQueryModel * fournisseur::afficher_fournisseur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_fournisseur"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_fournisseur "));
    return model;
}

bool fournisseur::supprimer_fournisseur(QString id)
{
QSqlQuery query;
query.prepare("Delete from fournisseur where ID_fournisseur = :idd ");
query.bindValue(":idd", id);
return    query.exec();
}
bool fournisseur::modifier_fournisseur(QString id)
{
    QSqlQuery query;
   // QString res= QString::number(id);
    query.prepare("Update fournisseur set  NOM_fournisseur=:nom_fournisseur where id_fournisseur = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":id_fournisseur",id_fournisseur);
    query.bindValue(":nom_fournisseur", nom_fournisseur);

    return  query.exec();

}


QSqlQueryModel * fournisseur::afficher_fournisseur2(QString aa){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery(QString("select * from fournisseur order by %1 ").arg(aa));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_fournisseur"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_fournisseur "));
    return model;
}

QSqlQueryModel * fournisseur::filter_fournisseur(QString hh)
{QSqlQueryModel * model= new QSqlQueryModel();
QString a = "%a%";
    model->setQuery("select * from fournisseur where nom_fournisseur  like ' :a ' ");
    model->query().bindValue(":a", a);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_fournisseur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_fournisseur "));
        return model;
}

QSqlQueryModel * fournisseur::afficherNomFournisseur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select nom_fournisseur from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_fournisseur"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_fournisseur "));
    return model;
}

