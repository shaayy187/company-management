#include "createworker.h"
#include "ui_createworker.h"
#include <qDebug>
#include <QMessageBox>
int id=1;
createworker::createworker(QWidget *parent)
    : QDialog(parent), ui(new Ui::createworker)
{
    ui->setupUi(this);
    this->setWindowTitle("Create worker");

    int ID = id++;
    ui->lineEdit_17->setText(QString::number(ID));
    ui->lineEdit_17->setDisabled(true);
    ui->comboBox->addItem("Worker");
    ui->comboBox->addItem("Management");
    ui->comboBox->addItem("Financial");
    ui->comboBox->addItem("Accountancy");
}

createworker::~createworker()
{
    delete ui;
}

void createworker::on_buttonBox_accepted()
{
    try{

    string name = ui->lineEdit_16->text().toStdString();
    if(name==""){
         throw MyException("Error with name - wrong name\n");
    }
    string surname = ui->lineEdit_11->text().toStdString();
    if(surname==""){
        throw MyException("Error with surname - wrong surname\n");
    }
    string pesel = ui->lineEdit_15->text().toStdString();
    if(pesel.length()!=11){
         throw MyException("Error with pesel, it must have 11 digits\n");
    }
    string sex;
    if(ui->radioButton_2->isChecked()){
        sex="man";
    }
    else if(ui->radioButton->isChecked()){
         sex="woman";
    }
    else if(ui->radioButton_3->isChecked()){
         sex="didn't want to tell";
    }
    else{
         throw MyException("Error with sex, you need to choose it!");
    }
    double salary = ui->lineEdit_18->text().toDouble();
    if(salary<3500){
         throw MyException("Minimal salary in our country is 3500!");
    }

    string position = ui->comboBox->currentText().toStdString();
    int ID=ui->lineEdit_17->text().toInt();
    if(position=="Management" || position=="management"){
        Worker *newWorker = new Management(
            name,
            surname,
            pesel,
            sex,
            ID,
            salary,
            position);

        emit workerCreated(newWorker);

    }
    else if(position=="Financial" || position=="financial"){
        Worker *newWorker = new Financial(
            name,
            surname,
            pesel,
            sex,
            ID,
            salary,
            position);

        emit workerCreated(newWorker);
    }
    else if(position=="Accountancy" || position=="accountancy"){
        Worker *newWorker = new Accountancy(
            name,
            surname,
            pesel,
            sex,
            ID,
            salary,
            position);

        emit workerCreated(newWorker);
    }
    else if(position=="Worker" || position=="worker"){
        Worker *newWorker = new Worker(
            name,
            surname,
            pesel,
            sex,
            ID,
            salary,
            position);


        emit workerCreated(newWorker);
    }
    } catch (const MyException &e) {

       QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...){
       QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }



}
