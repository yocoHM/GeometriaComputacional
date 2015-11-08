#include "dialog.h"
#include "ui_dialog.h"
#include <math.h>

bool dibuja = false;

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dibujarLinea()
{

}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (dibuja) {

        QString xStr = ui->boxXinicio->toPlainText();
        QString yStr = ui->boxYinicio->toPlainText();
        QString ladosStr = ui->boxXfin->toPlainText();

        if (!xStr.isEmpty() && !yStr.isEmpty() && !ladosStr.isEmpty()) {

            QPen pointPen(Qt::black);
            pointPen.setWidth(2);

            /*
            QPoint p1;
            p1.setX(x1.toInt());
            p1.setY(y1.toInt());
            */

            painter.setPen(pointPen);
            //painter.drawLine(p1,p2);

            int lados = ladosStr.toInt();

            double radio = 100;
            double angulo = (double)360.0/(double)lados;
            double xCentro = xStr.toInt();
            double yCentro = yStr.toInt();

            int xi,yi,xf,yf;
            double val = M_PI / 180;
            angulo *= val;
            int a = 0;

            for(a=1; a<=lados; a++) {
                xi = xCentro + (radio * cos(angulo*a));
                yi = yCentro + (radio * sin(angulo*a));

                xf = xCentro + (radio * cos(angulo*(a+1)));
                yf = yCentro + (radio * sin(angulo*(a+1)));

                painter.drawLine(xi, yi, xf, yf);

            }

            //painter.drawPoint(p1);
            //painter.drawPoint(p2);
        }

    }

    dibuja = false;

}


void Dialog::on_pushButton_clicked()
{
    dibuja = !dibuja;
    update();

}



