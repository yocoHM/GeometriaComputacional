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
    transforms.push_back(center);
}

PrismaRec::~PrismaRec()
{
    delete ui;
}

void dibujaPrismaRec(QPainter & painter){
       int x0 = 0;
       int y0 = 50;
       int x1 = 50;
       int y1 = 50;
       int x2 = 0;
       int y2 = -100;
       int x3 = 50;
       int y3 = -100;

       //Cuadrado 3
       int x4 = x0+30;
       int y4 = y0-50;
       int x5 = x1+30;
       int y5 = y1-50;
       int x6 = x2+30;
       int y6 = y2-50;
       int x7 = x3+30;
       int y7 = y3-50;

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
}

void PrismaRec::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if(dibuja)
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            dibujaPrismaRec(painter);

        }
    }
}

void PrismaRec::on_pushButton_clicked()
{
    dibuja=!dibuja;
    transforms.clear();
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
    update();
}

void PrismaRec::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        double x = xStr.toDouble();
        double y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        transforms.push_back(translate);
    }

    update();
}

void PrismaRec::on_pushButton_3_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void PrismaRec::on_pushButton_4_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);

    update();
}

void PrismaRec::on_pushButton_5_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void PrismaRec::on_pushButton_6_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    transforms.push_back(zoomIn);
    update();
}

void PrismaRec::on_pushButton_7_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    transforms.push_back(zoomIn);
    update();
}
