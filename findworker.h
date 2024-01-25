#ifndef FINDWORKER_H
#define FINDWORKER_H

#include <QDialog>
#include "pracownicy.h"
namespace Ui {
class findworker;
}

class findworker : public QDialog
{
    Q_OBJECT

public:
    explicit findworker(QWidget *parent = nullptr, Worker *worker=nullptr, Management* owner = nullptr);
    ~findworker();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    vector <Worker*> vect1;
    Ui::findworker *ui;
    Worker* worker;
    Management* owner;
};

#endif // FINDWORKER_H
