#include "setadress.h"
#include "ui_setadress.h"

setAdress::setAdress(QWidget *parent, Management *owner) : QDialog(parent), ui(new Ui::setAdress), owner(owner)
{
    ui->setupUi(this);
    this->setWindowTitle("Set worker's adress");
}

setAdress::setAdress(QWidget *parent, Worker *worker, Management *owner) : QDialog(parent), ui(new Ui::setAdress), owner(owner), worker(worker)
{
    ui->setupUi(this);
    this->setWindowTitle("Set worker's adress");
}

setAdress::~setAdress()
{
    delete ui;
}


void setAdress::on_buttonBox_2_accepted()
{

    string code=ui->lineEdit_8->text().toStdString();
    string street=ui->lineEdit_9->text().toStdString();
    string city=ui->lineEdit_10->text().toStdString();
    string country=ui->lineEdit_11->text().toStdString();
    int id = worker->getID();
    owner->setWorkerAddress(code,street,city,country,id);

    accept();



}


void setAdress::on_buttonBox_2_rejected()
{
    reject();
}

