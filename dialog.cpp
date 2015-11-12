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

void Dialog::on_pushButton_3_clicked()
{
    //permite una sola ventana de cubo
    Cubo cubo;
    cubo.setModal(true);
    cubo.exec();
}

void Dialog::on_pushButton_4_clicked()
{
    //permite una sola ventana de prismaRectangular
    PrismaRec prismaRectangular;
    prismaRectangular.setModal(true);
    prismaRectangular.exec();
}

void Dialog::on_pushButton_5_clicked()
{
    //permite una sola ventana de prismaTriangular
    PrismaTri prismaTriangular;
    prismaTriangular.setModal(true);
    prismaTriangular.exec();
}

void Dialog::on_pushButton_6_clicked()
{
    //permite una sola ventana de cono
    Cono cono;
    cono.setModal(true);
    cono.exec();
}
