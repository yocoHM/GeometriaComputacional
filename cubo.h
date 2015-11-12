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

private:
    Ui::Cubo *ui;
};

#endif // CUBO_H
