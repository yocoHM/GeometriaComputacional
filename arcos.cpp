#include "arcos.h"
#include "ui_arcos.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

bool dibujaArco = false;
//centro de la ventana
double xCentroArco = 450.0;
double yCentroArco = 300.0;

Arcos::Arcos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arcos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
}

Arcos::~Arcos()
{
    delete ui;
}

void Arcos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (dibujaArco) {

        QString radioStr = ui->boxRadio->toPlainText();
        QString anguloStr = ui->boxAngulo->toPlainText();

        if (!radioStr.isEmpty() && !anguloStr.isEmpty()) {

            QPen pointPen(Qt::black);
            pointPen.setWidth(2);
            painter.setPen(pointPen);

            //---Dibuja por simetría en todos los octantes---
            int angulo = anguloStr.toInt();
            int x = 0;
            int y = radioStr.toInt();
            double p = 5.0/4.0-y;


            //---MidPointCircle---
            int oct = (angulo - (angulo % 45)) / 45;
            double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
            double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

            if (oct > 0 || (oct == 0 && y > limit1))
                painter.drawPoint(xCentroArco+x,yCentroArco-y);
            if (oct > 1 || (oct == 1 && y <= limit2))
                painter.drawPoint(xCentroArco+y,yCentroArco-x);
            if (oct > 2 || (oct == 2 && y > limit1))
                painter.drawPoint(xCentroArco+y,yCentroArco+x);
            if (oct > 3 || (oct == 3 && y <= limit2))
                painter.drawPoint(xCentroArco+x,yCentroArco+y);
            if (oct > 4 || (oct == 4 && y > limit1))
                painter.drawPoint(xCentroArco-x,yCentroArco+y);
            if (oct > 5 || (oct == 5 && y <= limit2))
                painter.drawPoint(xCentroArco-y,yCentroArco+x);
            if (oct > 6 || (oct == 6 && y > limit1))
                painter.drawPoint(xCentroArco-y,yCentroArco-x);
            if (oct > 7 || (oct == 7 && y <= limit2))
                painter.drawPoint(xCentroArco-x,yCentroArco-y);

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
                    painter.drawPoint(xCentroArco+x,yCentroArco-y);
                if (oct > 1 || (oct == 1 && y <= limit2))
                    painter.drawPoint(xCentroArco+y,yCentroArco-x);
                if (oct > 2 || (oct == 2 && y > limit1))
                    painter.drawPoint(xCentroArco+y,yCentroArco+x);
                if (oct > 3 || (oct == 3 && y <= limit2))
                    painter.drawPoint(xCentroArco+x,yCentroArco+y);
                if (oct > 4 || (oct == 4 && y > limit1))
                    painter.drawPoint(xCentroArco-x,yCentroArco+y);
                if (oct > 5 || (oct == 5 && y <= limit2))
                    painter.drawPoint(xCentroArco-y,yCentroArco+x);
                if (oct > 6 || (oct == 6 && y > limit1))
                    painter.drawPoint(xCentroArco-y,yCentroArco-x);
                if (oct > 7 || (oct == 7 && y <= limit2))
                    painter.drawPoint(xCentroArco-x,yCentroArco-y);

            }


        }
        //corregir bug de dos ventanas de alerta
        //else {
            //QMessageBox::warning(this, tr("Alerta"), tr("Todos los campos de texto deben estar llenos para dibujar un arco"));
        //}

    }

    dibujaArco = false;

}

void Arcos::on_pushButton_clicked()
{
    dibujaArco = !dibujaArco;
    update();
}

void Arcos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    xCentroArco = xStr.toDouble();
    yCentroArco = yStr.toDouble();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        dibujaArco = !dibujaArco;
        update();
    }
}
