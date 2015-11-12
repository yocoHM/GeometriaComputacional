#include "arcos.h"
#include "ui_arcos.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

Arcos::Arcos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arcos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
}

Arcos::~Arcos()
{
    delete ui;
}

void dibujarArco(int angulo, int radio, QPainter & painter) {

    //---Dibuja por simetría en todos los octantes---
    int x = 0;
    int y = radio;
    double p = 5.0/4.0-y;


    //---MidPointCircle---
    int oct = (angulo - (angulo % 45)) / 45;
    double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
    double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

    if (oct > 0 || (oct == 0 && y > limit1))
        painter.drawPoint(x,-y);
    if (oct > 1 || (oct == 1 && y <= limit2))
        painter.drawPoint(y,-x);
    if (oct > 2 || (oct == 2 && y > limit1))
        painter.drawPoint(y,x);
    if (oct > 3 || (oct == 3 && y <= limit2))
        painter.drawPoint(x,y);
    if (oct > 4 || (oct == 4 && y > limit1))
        painter.drawPoint(x,y);
    if (oct > 5 || (oct == 5 && y <= limit2))
        painter.drawPoint(-y,x);
    if (oct > 6 || (oct == 6 && y > limit1))
        painter.drawPoint(-y,-x);
    if (oct > 7 || (oct == 7 && y <= limit2))
        painter.drawPoint(-x,-y);

    while(y > x)
    {
        if(p < 0)
            p += 2.0 * x + 3.0;
        else {
            p += 2.0 * (x - y) + 5.0;
            y--;
        }

        x++;


        //---MidPointCircle---
        int oct = (angulo - (angulo % 45)) / 45;
        double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
        double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

        if (oct > 0 || (oct == 0 && y > limit1))
            painter.drawPoint(x,-y);
        if (oct > 1 || (oct == 1 && y <= limit2))
            painter.drawPoint(y,-x);
        if (oct > 2 || (oct == 2 && y > limit1))
            painter.drawPoint(y,x);
        if (oct > 3 || (oct == 3 && y <= limit2))
            painter.drawPoint(x,y);
        if (oct > 4 || (oct == 4 && y > limit1))
            painter.drawPoint(-x,y);
        if (oct > 5 || (oct == 5 && y <= limit2))
            painter.drawPoint(-y,x);
        if (oct > 6 || (oct == 6 && y > limit1))
            painter.drawPoint(-y,-x);
        if (oct > 7 || (oct == 7 && y <= limit2))
            painter.drawPoint(-x,-y);

    }

}

void Arcos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {

        QString radioStr = ui->boxRadio->toPlainText();
        QString anguloStr = ui->boxAngulo->toPlainText();

        int angulo = anguloStr.toInt();
        int radio = radioStr.toInt();

        if (!radioStr.isEmpty() && !anguloStr.isEmpty()) {

            for(int i=0; i<transforms.size(); ++i) {
                painter.setTransform(transforms[i],true);
                dibujarArco(angulo, radio,  painter);

            }

        }

    }

}

void Arcos::on_pushButton_clicked()
{
    dibuja=!dibuja;
    transforms.clear();
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
    update();
}

void Arcos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        int x = xStr.toDouble();
        int y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        transforms.push_back(translate);
    }

    update();
}

void Arcos::on_pushButton_3_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void Arcos::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void Arcos::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);
    update();
}

void Arcos::on_pushButton_6_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    transforms.push_back(zoomIn);
    update();
}

void Arcos::on_pushButton_7_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    transforms.push_back(zoomIn);
    update();
}
