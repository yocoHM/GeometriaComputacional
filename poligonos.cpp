#include "poligonos.h"
#include "ui_poligonos.h"
#include <QMessageBox>
#include <math.h>

bool dibuja = false;
double xCentro = 450.0;
double yCentro = 300.0;
//qreal grados = 45.0;

Poligonos::Poligonos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligonos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
}

Poligonos::~Poligonos()
{
    delete ui;
}


void Poligonos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //painter.translate(150,-60);
    //painter.rotate(grados);

    if (dibuja) {

        QString ladosStr = ui->boxXfin->toPlainText();

        if (!ladosStr.isEmpty()) {

            QPen pointPen(Qt::black);
            pointPen.setWidth(2);

            painter.setPen(pointPen);

            int lados = ladosStr.toInt();

            double radio = 100;
            double angulo = (double)360.0/(double)lados;

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

        }
        //corregir bug de dos ventanas de alerta
        //else {
            //QMessageBox::warning(this, tr("Alerta"), tr("Todos los campos de texto deben estar llenos para dibujar un polígono"));
        //}

    }

    dibuja = false;

}


void Poligonos::on_pushButton_clicked()
{
    dibuja = !dibuja;
    update();
}

void Poligonos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    xCentro = xStr.toDouble();
    yCentro = yStr.toDouble();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        dibuja = !dibuja;
        update();
    }

}
