#include "cono.h"
#include "ui_cono.h"
#include "math.h"

bool dibujaCono = false;
double xCentroCono = 450.0;
double yCentroCono = 300.0;

Cono::Cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cono)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
}

Cono::~Cono()
{
    delete ui;
}

void Cono::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibujaCono) {

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
            painter.drawPoint(xCentroCono+x,yCentroCono+y);

            i+=2;

            painter.drawPoint(xCentroCono-x,yCentroCono+y);
            painter.drawPoint(xCentroCono+x,yCentroCono-y);
            painter.drawPoint(xCentroCono-x,yCentroCono-y);
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

            painter.drawPoint(xCentroCono+x,yCentroCono+y);

            i+=2;

            painter.drawPoint(xCentroCono-x,yCentroCono+y);
            painter.drawPoint(xCentroCono+x,yCentroCono-y);
            painter.drawPoint(xCentroCono-x,yCentroCono-y);
            /*ellipsePoints*/

        }
        /*midPointEllipse*/

        int incX = 50;
        int incY = 100;

        int x0 = xCentroCono - incX;
        int y0 = yCentroCono;
        int x1 = xCentroCono + incX;
        int y1 = y0;
        int x2 = xCentroCono;
        int y2 = y0 + incY;

        painter.drawLine(x0,y0,x2,y2);
        painter.drawLine(x2,y2,x1,y1);

    }

    dibujaCono = false;

}

void Cono::on_pushButton_clicked()
{
    dibujaCono = !dibujaCono;
    update();
}

void Cono::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    xCentroCono = xStr.toDouble();
    yCentroCono = yStr.toDouble();

    if (!xStr.isEmpty() && !yStr.isEmpty()) {
        dibujaCono = !dibujaCono;
        update();
    }
}
