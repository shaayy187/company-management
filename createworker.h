#ifndef CREATEWORKER_H
#define CREATEWORKER_H

#include <QDialog>
#include "pracownicy.h"

namespace Ui {
class createworker;
}

class createworker : public QDialog
{
    Q_OBJECT

public:
    explicit createworker(QWidget *parent = nullptr);
    ~createworker();

signals:
    void workerCreated(Worker *worker);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::createworker *ui;
};

#endif // CREATEWORKER_H
