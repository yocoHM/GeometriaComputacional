#include "cono.h"
#include "ui_cono.h"
#include "math.h"

Cono::Cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cono)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Cono::~Cono()
{
    delete ui;
}

void ellipsePoints(double & centroX, double & centroY, int & x, int & y, int & i, QPainter & painter) {

    painter.drawPoint(centroX+x,centroY+y);

    i+=2;

    painter.drawPoint(centroX-x,centroY+y);
    painter.drawPoint(centroX+x,centroY-y);
    painter.drawPoint(centroX-x,centroY-y);

}//cierre de ellipsePoints

void midPointEllipse(int & a, int & b, double & centroX, double & centroY, QPainter & painter) {

    int i = 0;
    double d2;
    int x=0;
    int y=b;

    double dl=b*b-(a*a*b)+(0.25*a*a);

    painter.drawPoint(x,y);

    while((a*a*(y-0.5))>(b*b*(x+1))) {

        if(dl<0) {
            dl+=b*b*(2*x+3);
        }
        else {
            dl+=b*b*(2*x+3)+a*a*(-2*y+2);
            y--;
        }
        x++;

        ellipsePoints(centroX, centroY, x, y, i, painter);

    }//cierre del while

    d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;

    while(y>0) {

        if(d2<0) {
            d2+=b*b*(2*x+2)+a*a*(-2*y+3);
            x++;
        }
        else{
            d2+=a*a*(-2*y+3);
        }
        y--;

        ellipsePoints(centroX, centroY, x, y, i, painter);

    }//cierre del while y>0

}//cierre de midPointEllipse

void dibujarCono(QPainter & painter) {

    double centroX = 0.0;
    double centroY = 0.0;

    int a = 50;
    int b = 20;

    midPointEllipse(a, b, centroX, centroY, painter);

    int incX = 50;
    int incY = 100;

    int x0 = centroX - incX;
    int y0 = centroY;
    int x1 = centroX + incX;
    int y1 = y0;
    int x2 = centroX;
    int y2 = y0 + incY;

    painter.drawLine(x0,y0,x2,y2);
    painter.drawLine(x2,y2,x1,y1);

}//cierre de dibujarCono

void Cono::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarCono(painter);

        }//cierre del for

    }//cierre del if que checa dibuja

}//cierre de paintEvent

void Cono::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}//cierre del boton dibujar

void Cono::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}//cierre del boton de trasladar

void Cono::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}//cierre del boton de rotar

void Cono::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}//cierre del boton de zoom out

void Cono::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}//cierre del boton de zoom in

void Cono::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}//cierre del boton de reflexion horizontal

void Cono::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}//cierre del boton de reflexion vertical
