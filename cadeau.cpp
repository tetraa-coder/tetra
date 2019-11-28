#include "cadeau.h"
#include <QDebug>
Cadeau::Cadeau()
{
id=0;
type="";
prix=0;
}
Cadeau::Cadeau(int id,int point,QString type,float prix)
{
  this->id=id;
    this->type=type;
    this->point=point;
  this->prix=prix;
}
QString Cadeau::get_type(){return  type;}
float Cadeau::get_prix(){return prix;}
int Cadeau::get_id(){return  id;}
int Cadeau::get_points(){return  point;}

bool Cadeau::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO cadeau (ID, TYPE, PRIX, POINT) "
                    "VALUES (:id, :type, :prix, :point)");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":prix", prix);
query.bindValue(":point", point);

return    query.exec();
}

QSqlQueryModel * Cadeau::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from cadeau");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Points"));
    return model;
}
