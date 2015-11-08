#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "poligonos.h"
#include "arcos.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    //permite multiples ventanas de poligonos
    //Poligonos *poligonos;

};

#endif // DIALOG_H
