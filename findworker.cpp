#include "findworker.h"
#include "ui_findworker.h"
#include <QDebug>
#include <QMessageBox>
findworker::findworker(QWidget *parent, Worker *worker, Management* owner)
    : QDialog(parent)
    , ui(new Ui::findworker), worker(worker),owner(owner)
{
    ui->setupUi(this);
    this->setWindowTitle("Find worker");
    ui->comboBox->addItem("Name");
    ui->comboBox->addItem("ID");
    ui->comboBox->addItem("Position");
}
findworker::~findworker()
{
    vect1.clear();
    delete ui;
}

void findworker::on_pushButton_clicked()
{
    try{
    QString field = ui->comboBox->currentText();
        if(field==""){
        throw MyException("Error with combobox");
    }
    QString value = ui->lineEdit->text();
    if(value ==""){
        throw MyException("Wrong text bro");
    }
    ui->listWidget->clear();

    if(field=="Name"){
        string value1 = value.toStdString();
        vect1 = owner->findWorker(value1);
    }
    else if(field=="ID"){
        int id1 = value.toInt();
        vect1 = owner->findWorker(id1);
    }
    else if(field=="Position"){
        vect1 = owner->findWorker(value);
    }
    if(vect1.size()==0){
        throw MyException("Nothing has been found, sorry");
    }
    for (int i=0;i<vect1.size();++i) {

            QString info = QString::fromStdString(vect1[i]->getName())
                           + " " + QString::fromStdString(vect1[i]->getSurname())
                           + " " + QString::fromStdString(vect1[i]->getPos())
                           + " " + QString::number(vect1[i]->getID());

            ui->listWidget->addItem(info);
        }

    }
    catch(const MyException& e){
       QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...) {
          QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}

void findworker::on_buttonBox_accepted()
{

    accept();
}


void findworker::on_buttonBox_rejected()
{

    reject();


}

