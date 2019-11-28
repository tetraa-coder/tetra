#include "dialog.h"
#include "ui_dialog.h"
#include "categorie.h"
#include <QMessageBox>
#include "fournisseur.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tabcategorie->setModel(tmpcategorie.afficher_categorie()) ;
   ui->comboBoxfournisseur->setModel(tmpcombo.afficherNomcategorie());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    int id_categorie = ui->lineEdit_id->text().toInt();
          QString nom_categorie= ui->lineEdit_nom->text();


        categorie c(id_categorie,nom_categorie);
        bool test=c.ajouter_categorie();
        if(test)
      {ui->tabcategorie->setModel(tmpcategorie.afficher_categorie());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                        QObject::tr("categorie ajoutée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_pb_supprimer_6_clicked()
{
    QModelIndex index = ui->tabcategorie->selectionModel()->currentIndex();
       QString var = index.sibling(index.row(),0).data().toString();

       bool test=tmpcategorie.supprimer_categorie(var);
       if(test)
       {ui->tabcategorie->setModel(tmpcategorie.afficher_categorie());//refresh
           QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                       QObject::tr("categorie supprimée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_modifiercat_clicked()
{
    //int id = ui->lineEdit_id_8->text().toInt();

        int id_categorie;// = ui->lineEdit_id_5->text().toInt();
        QString nom_categorie= ui->lineEdit_id_11->text();

    QModelIndex index = ui->tabcategorie->selectionModel()->currentIndex();
    QString var = index.sibling(index.row(),0).data().toString();
     categorie m(id_categorie,nom_categorie);
      bool test=m.modifier_categorie(var);
      if(test)
    {
          ui->tabcategorie->setModel(tmpcategorie.afficher_categorie());//refresh

    QMessageBox::information(nullptr, QObject::tr("Modifier une categorie"),
                      QObject::tr("categorie modifieé.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier une categorie"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_filter_textChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery(QString("select * from categorie where nom_categorie  like '%1%' ").arg(arg1));
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_categorie"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_categorie "));
            ui->tabcategorie->setModel(model);
}

void Dialog::on_affichercategorie_clicked()
{
    QString sort= ui->comboBoxcategorie->currentText();
       // QString sort = "id_categorie";
        ui->tabcategorie->setModel(tmpcategorie.afficher_categorie2(sort));
}

void Dialog::on_ajouterfournisseur_clicked()
{
    int id_fournisseur = ui->lineEdit_id_3->text().toInt();
          QString nom_fournisseur= ui->lineEdit_nom_2->text();


        fournisseur f(id_fournisseur,nom_fournisseur);
        bool test=f.ajouter_fournisseur();
        if(test)
      {ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                        QObject::tr("fournisseur ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}





void Dialog::on_supp_fournisseur_clicked()
{
    QModelIndex index = ui->tabfournisseur->selectionModel()->currentIndex();
       QString var = index.sibling(index.row(),0).data().toString();

       bool test=tmpfournisseur.supprimer_fournisseur(var);
       if(test)
       {ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());//refresh
           QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                       QObject::tr("categorie supprimée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_modifier_fournisseur_clicked()
{
    //int id = ui->lineEdit_id_13->text().toInt();

        int id_fournisseur;// = ui->lineEdit_id_5->text().toInt();
        QString nom_fournisseur= ui->lineEdit_id_13->text();

    QModelIndex index = ui->tabfournisseur->selectionModel()->currentIndex();
    QString var = index.sibling(index.row(),0).data().toString();
     fournisseur m(id_fournisseur,nom_fournisseur);
      bool test=m.modifier_fournisseur(var);
      if(test)
    {
          ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());//refresh

    QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                      QObject::tr("fournisseur modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_afficher_fournisseur_clicked()
{
    QString sort= ui->comboBox->currentText();
       // QString sort = "id_fournisseur";
        ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur2(sort));
}

void Dialog::on_filter_2_textChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery(QString("select * from fournisseur where nom_fournisseur  like '%1%' ").arg(arg1));
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_fournisseur"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_fournisseur "));
            ui->tabfournisseur->setModel(model);
}
