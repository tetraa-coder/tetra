#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "depot.h"
#include <QDebug>
#include <QMessageBox>
#include "produits.h"
#include <QString>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tab_dep->setModel(tmp_dep.afficher());
     ui->tab_produit->setModel(tmp_produit.afficher_produit());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    std::string nom=ui->lineEdit_nom->text().toStdString();
    std::string prenom=ui->lineEdit_prenom->text().toStdString();
    int cin=ui->lineEdit_h->text().toInt();

    depot e(id,nom,prenom,cin);
    bool test=e.ajouter();
    if (test) {qDebug()<<"depot ajoute";

    ui->tab_dep->setModel(tmp_dep.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un depot"),
                      QObject::tr("depot ajouté.\n"
                                  "Click OK."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un depot"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}}

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->lineEdit_id_supp->text().toInt();
    bool test=tmp_dep.supprimer(id);
    if (test){qDebug()<<"depot supprimer";
       ui->tab_dep->setModel(tmp_dep.afficher());
       QMessageBox::information(nullptr, QObject::tr("supprimer un depot"),
                         QObject::tr("depot supprimé.\n"
                                     "Click OK."), QMessageBox::Ok);

       }
         else{
             QMessageBox::critical(nullptr, QObject::tr("supprimer un depot"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

   }
}



void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->lineEdit_id_a_modifier->text().toInt();
    QString nom=ui->lineEdit_nom_modif->text();
    QString prenom=ui->lineEdit_prenom_modif->text();
    int cin=ui->lineEdit_h_modif->text().toInt();



    bool test= tmp_dep.modifier(nom,prenom,cin,id);
    if (test){
        ui->tab_dep->setModel(tmp_dep.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un depot"),
                          QObject::tr("depot modifié.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("modifier un depot"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }

}



void MainWindow::on_pb_ajouter_produit_clicked()
{
    int id=ui->lineEdit_id_youssef->text().toInt();
    std::string nom_type=ui->lineEdit_type_produit->text().toStdString();
    std::string nom_produit=ui->lineEdit_nom_produit->text().toStdString();
    int nbr=ui->lineEdit_type_nbr->text().toInt();

    produits d(nbr,id,nom_type,nom_produit);
    bool test=d.ajouter_produit();
    if (test){ qDebug()<<"produit ajoute";

    ui->tab_produit->setModel(tmp_produit.afficher_produit());
    QMessageBox::information(nullptr, QObject::tr("ajouter un produit"),
                      QObject::tr("produit ajouté.\n"
                                  "Click OK."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("ajouter un produit"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
}



void MainWindow::on_pb_modif_produit_clicked()
{
    int id=ui->id_produit_a_modif->text().toInt();
    QString nom_type=ui->nom_type_modif->text();
    QString nom_produit=ui->nom_produit_modif->text();
    int nbr=ui->nbr_produit_modif->text().toInt();

    bool test=tmp_produit.modifier_produit(id,nbr,nom_produit,nom_type);
    if (test) { qDebug()<<"produit modifié";

        ui->tab_produit->setModel(tmp_produit.afficher_produit());
        QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                          QObject::tr("produit modifié.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("modifier un produit"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
}



void MainWindow::on_pb_supp_produit_clicked()
{
    int id=ui->id_produit_supp->text().toInt();
    bool test=tmp_produit.supprimer_produit(id);
    if (test)
    { qDebug()<<"produit supprimré";

        ui->tab_produit->setModel(tmp_produit.afficher_produit());
        QMessageBox::information(nullptr, QObject::tr("supprimer un produit"),
                          QObject::tr("produit supprimé.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("supprimer un produit"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

/*void MainWindow::on_pb_affecter_conge_clicked()
{

    int id=ui->lineEdit_id_conge->text().toInt();
    int conge=set_conge(ui->lineEdit_dure_conge->text().toInt());
    employe e(id,nom,prenom,heures,heures_s,salaire,conge);
    bool test=e.affecter_conge();
}*/

/*void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

}*/

/*void MainWindow::on_pb_afficher_employe_du_mois_clicked()
{
    ui->tab_employe_du_mois->setModel(tmp_employe.select_e());
}*/




void MainWindow::on_pushButton_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * FROM DEPOT order by id DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
     ui->tab_dep->setModel(model);
}


void MainWindow::on_pushButton_rechercher_clicked()
{
    QString str=ui->idrecherche->text();
       ui->tableViewrecherche->setModel(tmp_produit.recherche_produit(str));
}
