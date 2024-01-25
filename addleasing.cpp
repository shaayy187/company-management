    #include "addleasing.h"
    #include "ui_addleasing.h"
    #include <QMessageBox>
    #include <qDebug>
    #include "pracownicy.h"


    addLeasing::addLeasing(QWidget *parent,Worker *worker, Management* owner)
        : QDialog(parent)
        , ui(new Ui::addLeasing),
       worker(worker), owner(owner)
    {
        ui->setupUi(this);
        this->setWindowTitle("Leasings");

    }

    addLeasing::~addLeasing()
    {
        delete ui;

    }

    void addLeasing::on_buttonBox_accepted()
    {
        try{
        string demand = ui->lineEdit->text().toStdString();
            if(demand==""){
            throw MyException("Wrong name!\n");
        }
        string brand = ui->lineEdit_2->text().toStdString();
        if(brand==""){
            throw MyException("Wrong brand!\n");
        }
        double value = ui->lineEdit_3->text().toDouble();
        if(value<=0){
            throw MyException("Wrong value!\n");
        }
        QString val = QString::fromStdString("Added leasing: " + demand + ", " + brand + ", ") + QString::number(value);

        worker->addLeasing(demand,brand, value);
        owner->updateFunds(owner->retFunds() - value);

        QMessageBox::about(this, "slayary", val);
        accept();
        }
        catch(const MyException &e){
             QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
        }
        catch(...){
             QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
        }
    }


    void addLeasing::on_pushButton_clicked()
    {

        for(int i=0;i<worker->leasing_size();i++){
            QString val=QString::fromStdString("Car: "+worker->getLeasing(i)->name+"\nBrand: "+worker->getLeasing(i)->brand+"\nCost: ")+QString::number(worker->getLeasing(i)->value);
            QMessageBox::about(this,"Leasings",val);
        }

    }

