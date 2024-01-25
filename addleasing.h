#ifndef ADDLEASING_H
#define ADDLEASING_H

#include <QDialog>
#include "pracownicy.h"

namespace Ui {
class addLeasing;
}

class addLeasing : public QDialog
{
    Q_OBJECT

public:
    explicit addLeasing(QWidget *parent = nullptr,Worker *worker=nullptr,Management* owner=nullptr);
    ~addLeasing();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::addLeasing *ui;
    Worker * worker;
    Management* owner;

};
#endif // ADDLEASING_H
