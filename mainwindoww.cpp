#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadeau.h"
#include "clients.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tab_cadeaux_3->setModel(tmpcadeau.afficher());
ui->tab_clients_2->setModel(tmpclient.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int identifiant = ui->lineEdit_identifiant->text().toInt();
    int pt = ui->lineEdit_pt->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Client c(identifiant,pt,nom,prenom);
  bool test=c.ajouter();
  if(test)
{ui->tab_clients_2->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_ajouter_clicked_cadeaux()
{
    int id = ui->lineEdit_id->text().toInt();
    int points = ui->lineEdit_points->text().toInt();
    QString type= ui->lineEdit_type->text();
    float prix= ui->lineEdit_prix->text().toFloat();
  Cadeau k(id,points,type,prix);
  bool test=k.ajouter();
  if(test)
{ui->tab_cadeaux_3->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
                  QObject::tr("Cadeau ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int identifiant = ui->lineEdit_identifiant_3->text().toInt();
bool test=tmpclient.supprimer(identifiant);
if(test)
{ui->tab_clients_2->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Client supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_supprimer_clicked_cadeaux()
{
int id = ui->lineEdit_id_3->text().toInt();
bool test=tmpcadeau.supprimer(id);
if(test)
{ui->tab_cadeaux_3->setModel(tmpcadeau.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                QObject::tr("Cadeau supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_modif_cadeaux_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    int points = ui->lineEdit_points_2->text().toInt();
    QString type= ui->lineEdit_type_2->text();
    float prix= ui->lineEdit_prix_2->text().toFloat();
  Cadeau k(id,points,type,prix);
  bool test=k.modifier(id);
  if(test)
{ui->tab_cadeaux_3->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifer un cadeau"),
                  QObject::tr("Cadeau modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un cadeau"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_modifclient_clicked()
{

    int identifiant = ui->lineEdit_identifiant_2->text().toInt();
    int pt = ui->lineEdit_pt_2->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
  Client c(identifiant,pt,nom,prenom);
  bool test=c.modifier(identifiant);
  if(test)
{ui->tab_clients_2->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("Client modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
