#ifndef DIALOGIHEB_H
#define DIALOGIHEB_H

#include <QDialog>

namespace Ui {
class Dialogiheb;
}

class Dialogiheb : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogiheb(QWidget *parent = nullptr);
    ~Dialogiheb();

private slots:
    void on_connect_clicked();

private:
    Ui::Dialogiheb *ui;
};

#endif // DIALOGIHEB_H
