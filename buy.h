#ifndef BUY_H
#define BUY_H

#include <QDialog>
#include "pracownicy.h"
namespace Ui {
class buy;
}

class buy : public QDialog
{
    Q_OBJECT

public:
    explicit buy(QWidget *parent = nullptr, Worker* worker=nullptr);
    ~buy();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::buy *ui;
    Worker* worker;
};

#endif // BUY_H
