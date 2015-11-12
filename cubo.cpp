#include "cubo.h"
#include "ui_cubo.h"
#include <math.h>

Cubo::Cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cubo)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
}

Cubo::~Cubo()
{
    delete ui;
}

void dibujaCubo(QPainter &painter){
    int medida = 25;

    int x1 = -medida;
    int y1 = medida;
    int x2 = medida;
    int y2 = medida;
    int x3 = -medida;
    int y3 = -medida;
    int x4 = medida;
    int y4 = -medida;

    int distProp = (x2-x1)/2;

    int _x1 = x1+distProp;
    int _y1 = y1-distProp;
    int _x2 = x2+distProp;
    int _y2 = y2-distProp;
    int _x3 = x3+distProp;
    int _y3 = y3-distProp;
    int _x4 = x4+distProp;
    int _y4 = y4-distProp;

    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1, y1, x3, y3);
    painter.drawLine(x2, y2, x4, y4);
    painter.drawLine(x3, y3, x4, y4);
    painter.drawLine(_x1, _y1, _x2, _y2);
    painter.drawLine(_x1, _y1, _x3, _y3);
    painter.drawLine(_x2, _y2, _x4, _y4);
    painter.drawLine(_x3, _y3, _x4, _y4);
    painter.drawLine(x1, y1, _x1, _y1);
    painter.drawLine(x2, y2, _x2, _y2);
    painter.drawLine(x3, y3, _x3, _y3);
    painter.drawLine(x4, y4, _x4, _y4);
}

void Cubo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja)
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            dibujaCubo(painter);

        }
    }

}

void Cubo::on_pushButton_clicked()
{
    dibuja=!dibuja;
    transforms.clear();
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
    update();
}

void Cubo::on_pushButton_2_clicked()
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

void Cubo::on_pushButton_3_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void Cubo::on_pushButton_5_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void Cubo::on_pushButton_4_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);
    update();
}

void Cubo::on_pushButton_6_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    transforms.push_back(zoomIn);
    update();
}

void Cubo::on_pushButton_7_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    transforms.push_back(zoomIn);
    update();
}
