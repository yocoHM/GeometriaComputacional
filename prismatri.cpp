#include "prismatri.h"
#include "ui_prismatri.h"
#include <math.h>

PrismaTri::PrismaTri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaTri)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
}

PrismaTri::~PrismaTri()
{
    delete ui;
}

void dibujarPrismaTri(QPainter & painter){
    int x1 = 0;
    int y1 = -50;
    int x2 = -25;
    int y2 = -70;
    int x3 = 25;
    int y3 = -70;
    int _x1 = 0;
    int _y1 = -50+50;
    int _x2 = -25;
    int _y2 = -70+50;
    int _x3 = 25;
    int _y3 = -70+50;

    painter.drawLine(x1,y1,x2,y2);
    painter.drawLine(x1,y1,x3,y3);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(_x1,_y1,_x2,_y2);
    painter.drawLine(_x1,_y1,_x3,_y3);
    painter.drawLine(_x2,_y2,_x3,_y3);
    painter.drawLine(x1,y1,_x1,_y1);
    painter.drawLine(x2,y2,_x2,_y2);
    painter.drawLine(_x3,_y3,x3,y3);
}

void PrismaTri::paintEvent(QPaintEvent *e)
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
            dibujarPrismaTri(painter);

        }
    }
}

void PrismaTri::on_pushButton_clicked()
{
    dibuja=!dibuja;
    transforms.clear();
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
    update();
}

void PrismaTri::on_pushButton_2_clicked()
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

void PrismaTri::on_pushButton_3_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void PrismaTri::on_pushButton_4_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);

    update();
}

void PrismaTri::on_pushButton_5_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void PrismaTri::on_pushButton_6_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    transforms.push_back(zoomIn);
    update();
}

void PrismaTri::on_pushButton_7_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    transforms.push_back(zoomIn);
    update();
}
