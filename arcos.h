#ifndef ARCOS_H
#define ARCOS_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Arcos;
}

class Arcos : public QDialog
{
    Q_OBJECT

public:
    explicit Arcos(QWidget *parent = 0);
    ~Arcos();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Arcos *ui;
};

#endif // ARCOS_H
