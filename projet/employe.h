#ifndef EMPLOYE_H
#define EMPLOYE_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class employe
{
public:
    employe();
    employe(int,std::string,std::string,int,int,int);
    //employe(int,std::string,std::string,int,int,int,int);
    int get_id();
    std::string get_nom();
    std::string get_prenom();
    int get_heures();
    int get_heures_s();
    int get_salaire();
    int get_conge();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
   // bool affecter_conge(int id,employe e,int congex);
    QSqlQueryModel * select_e();
    QSqlQueryModel * prime(const QString &id);

private:
    int id;
    std::string nom;
    std::string prenom;
    int heures;
    int heures_s;
    int salaire;
   // int conge;
};

#endif // EMPLOYE_H
