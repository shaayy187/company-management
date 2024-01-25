#ifndef SHOWDEMAND_H
#define SHOWDEMAND_H

#include <QDialog>
#include "pracownicy.h"
namespace Ui {
class showDemand;
}

class showDemand : public QDialog
{
    Q_OBJECT

public:
    explicit showDemand(QWidget *parent = nullptr);
    ~showDemand();

private:
    Ui::showDemand *ui;
};

#endif // SHOWDEMAND_H
