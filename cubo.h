#ifndef CUBO_H
#define CUBO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Cubo;
}

class Cubo : public QDialog
{
    Q_OBJECT

public:
    explicit Cubo(QWidget *parent = 0);
    ~Cubo();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::Cubo *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> transforms;
};

#endif // CUBO_H
