#include "prismarec.h"
#include "ui_prismarec.h"
#include <math.h>

PrismaRec::PrismaRec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaRec)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

PrismaRec::~PrismaRec()
{
    delete ui;
}

void dibujaPrismaRec(QPainter & painter){

    int medida = 50;
    int medida2 = 100;
    int medida3 = 30;

    int x0 = 0;
    int y0 = medida;
    int x1 = medida;
    int y1 = medida;
    int x2 = 0;
    int y2 = -medida2;
    int x3 = medida;
    int y3 = -medida2;

    //Cuadrado 3
    int x4 = x0 + medida3;
    int y4 = y0 - medida;
    int x5 = x1 + medida3;
    int y5 = y1 - medida;
    int x6 = x2 + medida3;
    int y6 = y2 - medida;
    int x7 = x3 + medida3;
    int y7 = y3 - medida;

    painter.drawLine(x0,y0,x1,y1);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(x2,y2,x0,y0);
    painter.drawLine(x3,y3,x1,y1);

    painter.drawLine(x4,y4,x5,y5);
    painter.drawLine(x6,y6,x7,y7);
    painter.drawLine(x6,y6,x4,y4);
    painter.drawLine(x7,y7,x5,y5);

    painter.drawLine(x0,y0,x4,y4);
    painter.drawLine(x1,y1,x5,y5);
    painter.drawLine(x2,y2,x6,y6);
    painter.drawLine(x3,y3,x7,y7);

}//cierre de dibujarPrisma

void PrismaRec::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujaPrismaRec(painter);
        }//cierre del for

    }//cierre del if que checa  dibuja

}//cierre de paintEvent

void PrismaRec::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}//cierre del boton dibujar

void PrismaRec::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}//cierre del boton de trasladar

void PrismaRec::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}//cierre del boton de rotar

void PrismaRec::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}//cierre del boton de zoom out

void PrismaRec::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}//cierre del boton de zoom in

void PrismaRec::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}//cierre del boton de reflexion horizontal

void PrismaRec::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}//cierre del boton de reflexion vertical
