#ifndef SETADRESS_H
#define SETADRESS_H

#include <QDialog>
#include "pracownicy.h"
namespace Ui {
class setAdress;
}

class setAdress : public QDialog
{
    Q_OBJECT

public:
    explicit setAdress(QWidget *parent = nullptr, Management *owner = nullptr);
    explicit setAdress(QWidget *parent = nullptr, Worker *worker = nullptr, Management *owner = nullptr);
    ~setAdress();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::setAdress *ui;
    Management* owner;
    Worker* worker;
};

#endif // SETADRESS_H
