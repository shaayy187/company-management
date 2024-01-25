#ifndef ADDDEMAND_H
#define ADDDEMAND_H

#include <QDialog>
#include "pracownicy.h"
#include "showdemand.h"
namespace Ui {
class addDemand;
}

class addDemand : public QDialog
{
    Q_OBJECT

public:
    explicit addDemand(QWidget *parent = nullptr, Worker *worker=nullptr);
    ~addDemand();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::addDemand *ui;
    Worker* worker;

};

#endif // ADDDEMAND_H
