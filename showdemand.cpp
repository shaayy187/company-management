#include "showdemand.h"
#include "ui_showdemand.h"
#include <fstream>
#include <qDebug>
#include <QMessageBox>
showDemand::showDemand(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showDemand)
{
    ui->setupUi(this);
    this->setWindowTitle("Companys' demand");
    try {
        ifstream in("demand.bin", ios::in | ios::binary);
        if (!in.is_open()) {
            throw MyException("Error opening demand.bin for reading.");
        }
        else if (in.peek() == ifstream::traits_type::eof()) {
            throw MyException("File is empty!");
        }
        else {
            while(!in.eof()){
                QString nam;
                double quant;
                in.read(reinterpret_cast<char*>(&quant), sizeof(quant));

                int wielkosc = 0;
                in.read(reinterpret_cast<char*>(&wielkosc), sizeof(wielkosc));
                string buffer;
                buffer.resize(wielkosc);
                in.read(&buffer[0], buffer.size());
                if(buffer != "" && quant>0){
                    nam= "Our demand: "+QString::fromStdString(buffer)+"\nQuant: "+QString::number(quant);
                    ui->listWidget->addItem(nam);
                }
            }

            in.close();
        }
    }
    catch (const MyException& e) {
       QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...) {
        QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
    }
}

showDemand::~showDemand()
{

    delete ui;
}
