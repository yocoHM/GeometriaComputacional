#ifndef POLIGONOS_H
#define POLIGONOS_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Poligonos;
}

class Poligonos : public QDialog
{
    Q_OBJECT

public:
    explicit Poligonos(QWidget *parent = 0);
    ~Poligonos();

private:
    Ui::Poligonos *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> transforms;

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

#endif // POLIGONOS_H
