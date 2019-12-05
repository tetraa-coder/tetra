#ifndef MODIFIER_VENTE_H
#define MODIFIER_VENTE_H
#include "vente.h"
#include <QDialog>

namespace Ui {
class modifier_vente;
}


class modifier_vente : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_vente(QWidget *parent = nullptr);
    ~modifier_vente();



private:
    Ui::modifier_vente *ui;
    Vente iddp ;


};

#endif // MODIFIER_VENTE_H
