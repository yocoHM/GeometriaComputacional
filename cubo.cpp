#include "cubo.h"
#include "ui_cubo.h"
#include <math.h>

bool dibujaCubo = false;
double xCentroCubo = 450.0;
double yCentroCubo = 300.0;

Cubo::Cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cubo)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
}

Cubo::~Cubo()
{
    delete ui;
}

void Cubo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (dibujaCubo) {

        int lado = 30;

        //Cuadrado 1
        int baseX1 = xCentroCubo - lado;
        int baseX2 = xCentroCubo + lado;
        int alturaY1 = yCentroCubo - lado;
        int alturaY2 = yCentroCubo + lado;

        int x0 = baseX1;
        int y0 = alturaY2;
        int x1 = baseX2;
        int y1 = alturaY2;

        int x2 = baseX1;
        int y2 = alturaY1;
        int x3 = baseX2;
        int y3 = alturaY1;

        int inc = lado - 5;

        //Cuadrado 2
        int x4 = x0 + inc;
        int y4 = y0 - inc;
        int x5 = x1 + inc;
        int y5 = y1 - inc;
        int x6 = x2 + inc;
        int y6 = y2 - inc;
        int x7 = x3 + inc;
        int y7 = y3 - inc;

        QPen pointPen(Qt::black);
        pointPen.setWidth(2);
        painter.setPen(pointPen);

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

    dibujaCubo = false;

}

void Cubo::on_pushButton_clicked()
{
    dibujaCubo = !dibujaCubo;
    update();
}

void Cubo::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    xCentroCubo = xStr.toDouble();
    yCentroCubo = yStr.toDouble();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        dibujaCubo = !dibujaCubo;
        update();
    }
}
