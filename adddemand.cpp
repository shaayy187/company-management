#include "adddemand.h"
#include "ui_adddemand.h"
#include "showdemand.h"
#include <QFile>
#include <fstream>
#include <QMessageBox>
#include <qDebug>
int ite=0;
addDemand::addDemand(QWidget *parent, Worker *worker)
    : QDialog(parent)
    , ui(new Ui::addDemand)
, worker(worker)
{
    ui->setupUi(this);
    this->setWindowTitle("Companys' demand");
}

addDemand::~addDemand()
{

    delete ui;
}

void addDemand::on_buttonBox_accepted()
{
    try{
    string demand = ui->lineEdit->text().toStdString();
     if(demand == ""){
        throw MyException("Wrong name!\n");
    }
    int quantity = ui->lineEdit_2->text().toInt();
    if(quantity <= 0){
        throw MyException("Wrong quantity!\n");
    }
    ++ite;

    worker->addDemand(demand);
    //worker->readDemand();
    worker->addQuant(quantity);
    worker->saveFile();
   // worker->readFile();
    }
    catch(const MyException &e){
        QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch(...){
        QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}


void addDemand::on_pushButton_clicked()
{
    showDemand *dem = new showDemand(this);
    dem->setModal(true);
    dem->exec();
}

