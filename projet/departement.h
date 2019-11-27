#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>

class departementData;

class departement
{
public:
    departement();
    departement(int,int,std::string,std::string);
    ~departement();
    int get_nbr();
    int get_id();
    std::string get_nom_chef();
    std::string get_nom_dep();
    bool ajouter_dep();
    bool modifier_dep(int);
    QSqlQueryModel * afficher_dep();
    bool supprimer_dep(int);
private:

    int nbr;
    int id;
    std::string nom_chef;
    std::string nom_dep;
};

#endif // DEPARTEMENT_H
