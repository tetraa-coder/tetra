#ifndef DIALOGRAWAND_H
#define DIALOGRAWAND_H
#include "vente.h"

#include <QMessageBox>
#include "achat.h"
#include <QPropertyAnimation>
#include <QSystemTrayIcon>
#include <QDialog>

namespace Ui {
class Dialograwand;
}

class Dialograwand : public QDialog
{
    Q_OBJECT

public:
    explicit Dialograwand(QWidget *parent = nullptr);
    ~Dialograwand();
    Vente dataiddp ;
       int quantitermod,quantitermoda;
       QSystemTrayIcon *notifyIcon;
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked() ;
    void on_pb_modifier_clicked() ;
    void on_tabvente_activated(const QModelIndex &index) ;

    void on_pb_ajouter_2_clicked();
    void on_pb_supprimer_2_clicked() ;
    //void on_tabvente_activated(const QModelIndex &index) ;

    void on_pb_modifiervente_clicked();

    void on_tabvente_clicked(const QModelIndex &index);

    void on_pb_modifier_pressed();

    void on_tabvente_pressed(const QModelIndex &index);

    void on_pb_modifier2_clicked();

    void on_tabachat_activated(const QModelIndex &index);

    void on_pb_modifier2_2_clicked();

    void on_tabachat_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_px_clicked() ;

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_client_activated(const QString &arg1);

    void on_comboBox_client_mod_activated(const QString &arg1);

    void on_fr_activated(const QString &arg1);

    void on_PDF_vente_clicked();

    void on_PDF_achat_clicked();

    void on_label_17_linkActivated(const QString &link);

    void on_ajouter_2_currentChanged(int index);

    void on_pb_actu_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_trierachat_clicked();
private:
    Ui::Dialograwand *ui;
    Dialograwand *tmp ;
       Vente tmpvente ;
       Vente tmpclient ;

       Achat tmpachat ;
       Achat tmpfournisseur ;
};

#endif // DIALOGRAWAND_H
