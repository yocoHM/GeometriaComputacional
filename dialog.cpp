#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //permite una sola ventana de poligonos
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();

    //permite multiples ventanas de poligonos
    //poligonos = new Poligonos(this);
    //poligonos->show();
}

void Dialog::on_pushButton_2_clicked()
{
    //permite una sola ventana de arcos
    Arcos arcos;
    arcos.setModal(true);
    arcos.exec();
}
