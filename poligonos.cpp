#include "poligonos.h"
#include "ui_poligonos.h"
#include <QMessageBox>
#include <math.h>

Poligonos::Poligonos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligonos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);

}

Poligonos::~Poligonos()
{
    delete ui;
}

void dibujarPoligono(int lados, QPainter & painter) {

    double radio = 100;
    double angulo = (double)360.0/(double)lados;


    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;

    for(a=1; a<=lados; a++) {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
    }

}


void Poligonos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {

        QString ladosStr = ui->boxXfin->toPlainText();

        if (!ladosStr.isEmpty()) {

            int lados = ladosStr.toInt();

            for(int i=0; i<transforms.size(); ++i) {
                painter.setTransform(transforms[i],true);
                dibujarPoligono(lados, painter);

            }

        }

    }

}


void Poligonos::on_pushButton_clicked()
{
    dibuja=!dibuja;
    transforms.clear();
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
    update();

}

void Poligonos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    if(!xStr.isEmpty() && !yStr.isEmpty())
    {
        int x = xStr.toDouble();
        int y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        transforms.push_back(translate);
    }

    update();

}

void Poligonos::on_pushButton_3_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void Poligonos::on_pushButton_4_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);

    update();
}

void Poligonos::on_pushButton_5_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void Poligonos::on_pushButton_6_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    transforms.push_back(zoomIn);
    update();
}

void Poligonos::on_pushButton_7_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    transforms.push_back(zoomIn);
    update();
}
