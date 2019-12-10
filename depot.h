#ifndef DEPOT_H
#define DEPOT_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class depot
{
public:
   depot();
    depot(int,std::string,std::string,int);
    //employe(int,std::string,std::string,int,int,int,int);
    int get_id();
    std::string get_nom();
    std::string get_prenom();
    int get_cin();
    bool ajouter();
    bool modifier(QString nom,QString prenom,int cin,int id);

    QSqlQueryModel * afficher();
    bool supprimer(int);
   // bool affecter_conge(int id,depot e,int congex);
    QSqlQueryModel * select_e();
      QSqlQueryModel * afficher_tri();

private:
    int id;
    std::string nom;
    std::string prenom;
    int cin;
    //int heures_s;
    //int salaire;
   // int conge;
};

#endif // DEPOT_H
