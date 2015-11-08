#include "dialog.h"
#include "ui_dialog.h"
#include "poligonos.h"

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
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();
}
