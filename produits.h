#ifndef PRODUITS_H
#define PRODUITS_H
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>

class produitData;

class produits
{
public:
    produits();
    produits(int,int,std::string,std::string);
    ~produits();
    int get_nbr();
    int get_id();
    std::string get_nom_type();
    std::string get_nom_produit();
    bool ajouter_produit();
     bool modifier_produit(int id,int nbr,QString nom_produit,QString nom_type);
    QSqlQueryModel * afficher_produit();
    bool supprimer_produit(int);
    QSqlQueryModel *  recherche_produit(const QString &id);

private:

    int nbr;
    int id;
    std::string nom_type;
    std::string nom_produit;
};

#endif // PRODUITS_H
