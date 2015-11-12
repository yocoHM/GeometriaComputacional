#ifndef PRISMAREC_H
#define PRISMAREC_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class PrismaRec;
}

class PrismaRec : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaRec(QWidget *parent = 0);
    ~PrismaRec();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PrismaRec *ui;
};

#endif // PRISMAREC_H
