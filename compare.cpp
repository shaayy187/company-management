#include "compare.h"
#include "ui_compare.h"
#include <QMessageBox>

compare::compare(QWidget *parent, Management* owner)
    : QDialog(parent)
    , ui(new Ui::compare), owner(owner)
{
    ui->setupUi(this);
    this->setWindowTitle("Compare two workers");
}
compare::~compare()
{
    delete ui;
}

void compare::on_buttonBox_accepted()
{

    string name1 = ui->lineEdit->text().toStdString();
    string name2 = ui->lineEdit_2->text().toStdString();
    int id1 =  ui->lineEdit_3->text().toInt();
    int id2=  ui->lineEdit_4->text().toInt();

    Worker* worker1 = nullptr;
    Worker* worker2 = nullptr;

    if(name1==name2){
        for (Worker* worker : owner->workers_array) {
            if (worker->getID() == id1) {
                worker1 = worker;
            } else if (worker->getID() == id2) {
                worker2 = worker;
            }


            if (worker1 && worker2) {
                break;
            }
        }
    }
    else{
    for (Worker* worker : owner->workers_array) {
        if (worker->getName() == name1) {
            worker1 = worker;
        } else if (worker->getName() == name2) {
            worker2 = worker;
        }


        if (worker1 && worker2) {
            break;
        }
    }
    }

    if (worker1 && worker2) {

        if (*worker1 >= *worker2 == true) {
          //  cout<<"Pierwszy:"<<endl;
          // cout<<"Worker 1: "<<worker1->getSalary()<<endl;
           // cout<<"Worker 2: "<<worker2->getSalary()<<endl;
          //  cout<<"Worker 1 >= Worker 2 :"<<(worker1 >= worker2)<<endl;
            QMessageBox::about(this,"Result",QString::fromStdString(worker1->getName() + " earns more." ));

        } else {
           // cout<<"Drugi:"<<endl;
            //cout<<"Worker 1: "<<worker1->getSalary()<<endl;
          //  cout<<"Worker 2: "<<worker2->getSalary()<<endl;
          //  cout<<"Worker 1 >= Worker 2 :"<<(worker1>= worker2)<<endl;
            QMessageBox::about(this,"Result",QString::fromStdString(worker2->getName() +" earns more." ));

        }
    } else {
        QMessageBox::critical(this,"Result","Couldn't find workers with specific names.\n");
    }


}
