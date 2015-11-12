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

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // POLIGONOS_H
