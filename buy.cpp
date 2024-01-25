#include "buy.h"
#include "ui_buy.h"
#include <fstream>
#include "pracownicy.h"
#include <string>
#include <qDebug>
#include <QMessageBox>

  vector<double> fileQuantVect;
   vector<string> names;
buy::buy(QWidget *parent, Worker* worker)
    : QDialog(parent)
    , ui(new Ui::buy),
       worker(worker)
{
    ui->setupUi(this);
    this->setWindowTitle("Shopping");
    try {
        ifstream in("demand.bin", ios::in | ios::binary);
        if (!in.is_open()) {
            throw MyException("Error opening demand.bin for reading.\n");
        }
        else if (in.peek() == ifstream::traits_type::eof()) {
            throw MyException("File is empty!\n");
        }
        else {
              ui->listWidget->clear();
            names.clear();
            fileQuantVect.clear();
            while(!in.eof()){
                QString nam;
                double quant;
                in.read(reinterpret_cast<char*>(&quant), sizeof(quant));
                fileQuantVect.push_back(quant);
                int wielkosc = 0;
                in.read(reinterpret_cast<char*>(&wielkosc), sizeof(wielkosc));
                string buffer;
                buffer.resize(wielkosc);
                in.read(&buffer[0], buffer.size());
                names.push_back(buffer);
                if(buffer != "" && quant>=0){
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
        QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}

buy::~buy()
{
    delete ui;
}

void buy::on_buttonBox_accepted()
{
    try {
        string name = ui->lineEdit->text().toStdString();
        int diff;
        if (name == "") {
            throw MyException("Thing not found!\n");
        }
        int quant_buy = ui->lineEdit_2->text().toInt();
        if (quant_buy <= 0) {
            throw MyException("Wrong quantity!\n");
        }

        int position = -1;
        int siz=names.size();
        for (int i = 0; i < siz; i++) {
            if (names[i] == name) {
                position = i;
                if (quant_buy > fileQuantVect[position]) {
                    throw MyException("You can't buy more things than in demand!\n");
                }
                diff=fileQuantVect[position]-quant_buy;
                fileQuantVect[position] =diff;
                worker->updateQuant(position,diff);
                break;
            }
        }

        if (position == -1) {
            throw MyException("Thing not found!\n");
        }

        ofstream out("demand.bin", ios::out | ios::binary);
        if (!out.is_open()) {
            throw MyException("Error opening demand.bin for writing.\n");
        }

        int size = names.size();
        for (int i = 0; i < size; i++) {
            double qu = fileQuantVect[i];
            char* dim = reinterpret_cast<char*>(&qu);
            out.write(dim, sizeof(qu));

            unsigned int wielkosc = names[i].size();
            out.write(reinterpret_cast<char*>(&wielkosc), sizeof(wielkosc));
            out.write(names[i].c_str(), wielkosc);
        }

        out.close();

        ofstream csv("dataNoQ.csv", ios::out);
        if (!csv.is_open()) {
            throw MyException("Error opening dataNoQ.csv for writing.\n");
        }

        csv << "thing_name;value;quantity;info;entry" << endl;
        csv << names[position] << ";;" <<  quant_buy << ";" << endl;
        names.clear();
        fileQuantVect.clear();
        csv.close();
        ui->listWidget->clear();
    }
    catch (const MyException& e) {
       QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...) {
       QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}
