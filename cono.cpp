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
    transforms.push_back(center);
}

Cono::~Cono()
{
    delete ui;
}

void dibujarCono(QPainter & painter){

    double centroX = 0.0;
    double centroY = 0.0;

    int a = 50;
    int b = 20;

    /*midPointEllipse */
    int i = 0;
    double d2;
    int x=0;
    int y=b;

    double dl=b*b-(a*a*b)+(0.25*a*a);

    painter.drawPoint(x,y);

    while((a*a*(y-0.5))>(b*b*(x+1))) {
        if(dl<0)
            dl+=b*b*(2*x+3);
        else {
            dl+=b*b*(2*x+3)+a*a*(-2*y+2);
            y--;
        }
        x++;

        /*ellipsePoints*/
        painter.drawPoint(centroX+x,centroY+y);

        i+=2;

        painter.drawPoint(centroX-x,centroY+y);
        painter.drawPoint(centroX+x,centroY-y);
        painter.drawPoint(centroX-x,centroY-y);
        /*ellipsePoints*/

    }

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

        /*ellipsePoints*/

        painter.drawPoint(centroX+x,centroY+y);

        i+=2;

        painter.drawPoint(centroX-x,centroY+y);
        painter.drawPoint(centroX+x,centroY-y);
        painter.drawPoint(centroX-x,centroY-y);
        /*ellipsePoints*/

    }
    /*midPointEllipse*/

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
}

void Cono::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {
        for(int i=0; i<transforms.size(); ++i) {
            painter.setTransform(transforms[i],true);
            dibujarCono(painter);

        }
    }

}

void Cono::on_pushButton_clicked()
{
    dibuja=!dibuja;
    transforms.clear();
    QTransform center;
    center.translate(xCentro,yCentro);
    transforms.push_back(center);
    update();
}

void Cono::on_pushButton_2_clicked()
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

void Cono::on_pushButton_3_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void Cono::on_pushButton_4_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);

    update();
}

void Cono::on_pushButton_5_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void Cono::on_pushButton_6_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    transforms.push_back(zoomIn);
    update();
}

void Cono::on_pushButton_7_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    transforms.push_back(zoomIn);
    update();
}
