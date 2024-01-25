#include "showinfo.h"
#include "ui_showinfo.h"
#include "adddemand.h"
#include "addleasing.h"
#include "buy.h"
#include "posting.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include "findworker.h"
showinfo::showinfo(QWidget *parent, Management *owner) : QDialog(parent), ui(new Ui::showinfo), owner(owner)
{
    ui->setupUi(this);
    this->setWindowTitle("Workers' information");
}

showinfo::showinfo(QWidget *parent, Worker *worker, Management *owner) : QDialog(parent), ui(new Ui::showinfo), owner(owner),worker(worker)
{
    ui->setupUi(this);
    this->setWindowTitle("Workers' information");

    if (worker) {
        ui->lineEdit_8->setText(QString::fromStdString(worker->getName()));
        ui->lineEdit_9->setText(QString::fromStdString(worker->getSurname()));
        ui->lineEdit_10->setText(QString::fromStdString(worker->getpesel()));
        ui->lineEdit_11->setText(QString::fromStdString(worker->getsex()));
        ui->lineEdit_12->setText(QString::number(worker->getID()));
        ui->lineEdit_13->setText(QString::number(worker->getsalary()));
        ui->lineEdit_14->setText(QString::fromStdString(worker->getPos()));
        ui->lineEdit_15->setText("Street: "+QString::fromStdString(worker->address.street)+" "+ QString::fromStdString(worker->address.post_code)+" " + QString::fromStdString(worker->address.city)+ " " +QString::fromStdString(worker->address.country));
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_9->setDisabled(true);
        ui->lineEdit_10->setDisabled(true);
        ui->lineEdit_11->setDisabled(true);
        ui->lineEdit_12->setDisabled(true);
        ui->lineEdit_13->setDisabled(true);
        ui->lineEdit_14->setDisabled(true);
        ui->lineEdit_15->setDisabled(true);

    }
    if (worker->getPos() == "Financial") {

        QPushButton *button1 = new QPushButton("Add car");
        QPushButton *button2 = new QPushButton("Add demand");
        QPushButton *button3 = new QPushButton("Purchase");


        ui->horizontalLayout->addWidget(button1);
        ui->horizontalLayout_2->addWidget(button2);
        ui->horizontalLayout_3->addWidget(button3);

        connect(button2, &QPushButton::clicked, this, &showinfo::on_button2_clicked);
        connect(button1, &QPushButton::clicked, this, &showinfo::on_button11_clicked);
        connect(button3, &QPushButton::clicked, this, &showinfo::on_button3_clicked);
    }
    if(worker->getPos()=="Management"){
        QPushButton *buttonn1 = new QPushButton("Available funds");
        QPushButton *butt2 = new QPushButton("Search for worker");
        ui->horizontalLayout->addWidget(buttonn1);
        ui->horizontalLayout_2->addWidget(butt2);

        connect(buttonn1, &QPushButton::clicked, this, &showinfo::on_button1_clicked);
        connect(butt2, &QPushButton::clicked, this, &showinfo::on_butt2_clicked);
    }
    if(worker->getPos()=="Accountancy"){
        QPushButton *buttonn1 = new QPushButton("Bookmark");
        ui->horizontalLayout->addWidget(buttonn1);

        connect(buttonn1, &QPushButton::clicked, this, &showinfo::on_button5_clicked);
    }
}

showinfo::~showinfo()
{
    for (QPushButton *button : findChildren<QPushButton*>()) {
        delete button;
    }
    delete ui;
}

void showinfo::on_buttonBox_2_accepted()
{
    accept();
}


void showinfo::on_buttonBox_2_rejected()
{
    reject();
}
void showinfo::on_button2_clicked() {
    addDemand *dem = new addDemand(this,worker);
    dem->setModal(true);
    dem->exec();
}
void showinfo::on_button1_clicked() {
    try{
        double fun=owner->retFunds();
        string val=to_string(fun);
        string com="You have got "+val+" money left";
        QMessageBox::about(this,"Available funds",QString::fromStdString(com));
    }
    catch(...){
       QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
    }
}
void showinfo::on_button11_clicked(){
    addLeasing *lea = new addLeasing(this,worker,owner);
    lea->setModal(true);
    lea->exec();
}
void showinfo::on_button3_clicked(){
    buy* buyy= new buy(this,worker);
    buyy->setModal(true);
    buyy->exec();
}
void showinfo::on_button5_clicked(){
    posting* post = new posting(this,worker,owner);
    post->setModal(true);
    post->exec();
}
void showinfo::on_butt2_clicked(){
    findworker *find = new findworker(this,worker,owner);
    find->setModal(true);
    find->exec();

}
