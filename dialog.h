#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void dibujarLinea();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
};

#endif // DIALOG_H
