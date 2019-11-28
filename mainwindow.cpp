#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/iheb/Documents/C++/projet c++/pic.png");
    ui->label_pic->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_clicked()
{
    QString username = ui->lineEdit_username->text() ;
      QString password = ui->lineEdit_pass->text() ;
      if(username == "iheb" && password == "fournisseur"){
          QMessageBox::information(this, "login", "username and password are correct") ;
          Dialog dialog ;
          dialog.setModal(true) ;
          dialog.exec();

      }
      else {
          QMessageBox::warning(this,"login", "username and password are not correct") ;
      }
}
