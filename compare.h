#ifndef COMPARE_H
#define COMPARE_H

#include <QDialog>
#include "pracownicy.h"
namespace Ui {
class compare;
}

class compare : public QDialog
{
    Q_OBJECT

public:
    explicit compare(QWidget *parent = nullptr,Management* owner=nullptr);
    ~compare();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::compare *ui;
    Management* owner;
};

#endif // COMPARE_H
