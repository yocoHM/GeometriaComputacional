#ifndef PRISMATRI_H
#define PRISMATRI_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class PrismaTri;
}

class PrismaTri : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaTri(QWidget *parent = 0);
    ~PrismaTri();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PrismaTri *ui;
};

#endif // PRISMATRI_H
