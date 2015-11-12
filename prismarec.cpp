#include "prismarec.h"
#include "ui_prismarec.h"
#include <math.h>

bool dibujaPrismaRec = false;
double xCentroPrismaRec = 450.0;
double yCentroPrismaRec = 300.0;

PrismaRec::PrismaRec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaRec)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
}

PrismaRec::~PrismaRec()
{
    delete ui;
}

void PrismaRec::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (dibujaPrismaRec) {

        int base = 25;
        int altura = base*3;

        int baseX1 = xCentroPrismaRec - base;
        int baseX2 = xCentroPrismaRec + base;
        int alturaY1 = yCentroPrismaRec - altura;
        int alturaY2 = yCentroPrismaRec + altura;

        int x0 = baseX1;
        int y0 = alturaY2;
        int x1 = baseX2;
        int y1 = alturaY2;

        int x2 = baseX1;
        int y2 = alturaY1;
        int x3 = baseX2;
        int y3 = alturaY1;

        int incX = base + 5;
        int incY = altura - 25;

        int x4 = x0 + incX;
        int y4 = y0 - incY;
        int x5 = x1 + incX;
        int y5 = y1 - incY;
        int x6 = x2 + incX;
        int y6 = y2 - incY;
        int x7 = x3 + incX;
        int y7 = y3 - incY;

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

    dibujaPrismaRec = false;

}

void PrismaRec::on_pushButton_clicked()
{
    dibujaPrismaRec = !dibujaPrismaRec;
    update();
}

void PrismaRec::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    xCentroPrismaRec = xStr.toDouble();
    yCentroPrismaRec = yStr.toDouble();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        dibujaPrismaRec = !dibujaPrismaRec;
        update();
    }
}
