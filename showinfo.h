#ifndef SHOWINFO_H
#define SHOWINFO_H

#include <QDialog>
#include "pracownicy.h"
#include "adddemand.h"
#include "addleasing.h"

namespace Ui {
class showinfo;
}

class showinfo : public QDialog
{
    Q_OBJECT

public:
    explicit showinfo(QWidget *parent = nullptr, Management *owner = nullptr);
    explicit showinfo(QWidget *parent = nullptr, Worker *worker = nullptr, Management *owner = nullptr);
    ~showinfo();

private slots:
    void on_buttonBox_2_accepted();
    void on_buttonBox_2_rejected();
    void on_button11_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button5_clicked();
    void on_butt2_clicked();
private:
    Ui::showinfo *ui;
    Management *owner;
    Worker *worker;

};

#endif // SHOWINFO_H
