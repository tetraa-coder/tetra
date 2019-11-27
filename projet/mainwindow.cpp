#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QDebug>
#include <QMessageBox>
#include "departement.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tab_employe->setModel(tmp_employe.afficher());
    QPixmap pic("C:\\Users\\Marwen\\Desktop\\pic.png");
    ui->label_pic->setPixmap(pic);
    ui->label_pic2->setPixmap(pic);
    ui->label_pic_3->setPixmap(pic);
    ui->label_pic_4->setPixmap(pic);

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
    int heures=ui->lineEdit_h->text().toInt();
    int heures_s=ui->lineEdit_hs->text().toInt();
    int salaire=ui->lineEdit_salaire->text().toInt();
    employe e(id,nom,prenom,heures,heures_s,salaire);
    bool test=e.ajouter();
    if (test) {qDebug()<<"employe ajoute";

    ui->tab_employe->setModel(tmp_employe.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                      QObject::tr("emlpoye ajouté.\n"
                                  "Click OK."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}}

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->lineEdit_id_supp->text().toInt();
    bool test=tmp_employe.supprimer(id);
    if (test){qDebug()<<"employe supprimer";
       ui->tab_employe->setModel(tmp_employe.afficher());
       QMessageBox::information(nullptr, QObject::tr("supprimer un employe"),
                         QObject::tr("emlpoye supprimé.\n"
                                     "Click OK."), QMessageBox::Ok);

       }
         else{
             QMessageBox::critical(nullptr, QObject::tr("supprimer un employe"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

   }
}



void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->lineEdit_id_a_modifier->text().toInt();
    std::string nom=ui->lineEdit_nom_modif->text().toStdString();
    std::string prenom=ui->lineEdit_prenom_modif->text().toStdString();
    int heures=ui->lineEdit_h_modif->text().toInt();
    int heures_s=ui->lineEdit_hs_modif->text().toInt();
    int salaire=ui->salaire_a_modif->text().toInt();
    tmp_employe = employe(id,nom,prenom,heures,heures_s,salaire);

    bool test=tmp_employe.modifier(id);
    if (test){
        ui->tab_employe->setModel(tmp_employe.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                          QObject::tr("emlpoye modifié.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }

}



void MainWindow::on_pb_ajouter_dep_clicked()
{
    int id=ui->lineEdit_id_dep->text().toInt();
    std::string nom_chef=ui->lineEdit_chef_dep->text().toStdString();
    std::string nom_dep=ui->lineEdit_nom_dep->text().toStdString();
    int nbr=ui->lineEdit_nbr_employe_dep->text().toInt();

    departement d(nbr,id,nom_chef,nom_dep);
    bool test=d.ajouter_dep();
    if (test){ qDebug()<<"departement ajoute";

    ui->tab_departement->setModel(tmp_departement.afficher_dep());
    QMessageBox::information(nullptr, QObject::tr("ajouter un departement"),
                      QObject::tr("departement ajouté.\n"
                                  "Click OK."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("ajouter un departement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
}



void MainWindow::on_pb_modif_dep_clicked()
{
    int id=ui->id_dep_a_modif->text().toInt();
    std::string nom_chef=ui->nom_chef_modif->text().toStdString();
    std::string nom_dep=ui->nom_dep_modif->text().toStdString();
    int nbr=ui->nbr_dep_modif->text().toInt();
    departement d(id,nbr,nom_chef,nom_dep);
    bool test=tmp_departement.modifier_dep(id);
    if (test) { qDebug()<<"departement modifié";

        ui->tab_departement->setModel(tmp_departement.afficher_dep());
        QMessageBox::information(nullptr, QObject::tr("modifier un departement"),
                          QObject::tr("departement modifié.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("modifier un departement"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
}



void MainWindow::on_pb_supp_dep_clicked()
{
    int id=ui->id_dep_supp->text().toInt();
    bool test=tmp_departement.supprimer_dep(id);
    if (test)
    { qDebug()<<"departement supprimré";

        ui->tab_departement->setModel(tmp_departement.afficher_dep());
        QMessageBox::information(nullptr, QObject::tr("supprimer un departement"),
                          QObject::tr("departement supprimé.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("supprimer un departement"),
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
