#ifndef CONO_H
#define CONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Cono;
}

class Cono : public QDialog
{
    Q_OBJECT

public:
    explicit Cono(QWidget *parent = 0);
    ~Cono();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Cono *ui;
};

#endif // CONO_H
