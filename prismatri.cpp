#include "prismatri.h"
#include "ui_prismatri.h"
#include <math.h>

bool dibujaPrismaTri = false;
double xCentroPrismaTri = 450.0;
double yCentroPrismaTri = 300.0;

PrismaTri::PrismaTri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaTri)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
}

PrismaTri::~PrismaTri()
{
    delete ui;
}

void PrismaTri::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (dibujaPrismaTri) {

        int base = 25;
        int altura = 22;

        int baseX1 = xCentroPrismaTri - base;
        int baseX2 = xCentroPrismaTri + base;
        int alturaY1 = yCentroPrismaTri - altura;
        int alturaY2 = yCentroPrismaTri + altura;

        //Puntos Base
        int x0 = baseX1;
        int y0 = alturaY1;
        int x1 = baseX2;
        int y1 = alturaY1;
        int x2 = xCentroPrismaTri;
        int y2 = alturaY2;

        int inc = 100;

        //Puntos Tapa
        int x3 = x0;
        int y3 = y0 - inc;
        int x4 = x1;
        int y4 = y1 - inc;
        int x5 = x2;
        int y5 = y2 - inc;

        QPen pointPen(Qt::black);
        pointPen.setWidth(2);
        painter.setPen(pointPen);

        painter.drawLine(x0,y0,x1,y1);
        painter.drawLine(x0,y0,x2,y2);
        painter.drawLine(x1,y1,x2,y2);

        painter.drawLine(x3,y3,x4,y4);
        painter.drawLine(x3,y3,x5,y5);
        painter.drawLine(x4,y4,x5,y5);

        painter.drawLine(x3,y3,x0,y0);
        painter.drawLine(x4,y4,x1,y1);
        painter.drawLine(x5,y5,x2,y2);

    }

    dibujaPrismaTri = false;

}

void PrismaTri::on_pushButton_clicked()
{
    dibujaPrismaTri = !dibujaPrismaTri;
    update();
}

void PrismaTri::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    xCentroPrismaTri = xStr.toDouble();
    yCentroPrismaTri = yStr.toDouble();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        dibujaPrismaTri = !dibujaPrismaTri;
        update();
    }
}
