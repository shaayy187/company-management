#include "posting.h"
#include "ui_posting.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
posting::posting(QWidget *parent,Worker* worker, Management* owner)
    : QDialog(parent)
    , ui(new Ui::posting),
    worker(worker), owner(owner)
{
    ui->setupUi(this);
    this->setWindowTitle("Bookings");

    initializeTable();

    loadCSVData("dataNoQ.csv");


}

posting::~posting()
{
    delete ui;
}

void posting::loadCSVData(const QString& filePath)
{
    try {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            throw MyException("Failed to open the file: " + filePath.toStdString()+"\n");
        }


        QTextStream in(&file);
        int k=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList fields = line.split(';');

            if(k!=0){
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);

                for (int i = 0; i < fields.size(); ++i)
                {

                    QTableWidgetItem* item = new QTableWidgetItem(fields[i]);
                    ui->tableWidget->setItem(row, i, item);
                }
            }
            k++;
        }

        file.close();
    }
    catch (const MyException& e) {

       QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...) {

         QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}
void posting::initializeTable()
{

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "thing_name" << "value" << "quantity" << "info" << "entry");


    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}


void posting::saveCSVData(const QString& filePath)
{
    try {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {

            throw MyException("Failed to open the file for writing: " + filePath.toStdString()+"\n");
        }

        QTextStream out(&file);


        out << "thing_name" << ";" << "value" << ";" << "quantity" << ";" << "info" << ";" << "entry" << endl;
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        {
            QStringList fields;
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
            {
                QTableWidgetItem* item = ui->tableWidget->item(row, col);


                if (item != nullptr){
                    fields << item->text();
                }
                else
                    if(col==4)
                        fields << QString::fromStdString(worker->getName());
                    else
                        fields << "";
            }


            out << fields.join(";") << endl;
        }

        file.close();
    }
    catch (const MyException& e) {

       QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...) {

        QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}

void posting::on_buttonBox_accepted()
{

    try {
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        {
            QTableWidgetItem* item = ui->tableWidget->item(row, 1);
            if (item != nullptr)
            {
                bool conversionOK;
                double amount = item->text().toDouble(&conversionOK);
                QTableWidgetItem* name1 = ui->tableWidget->item(row, 0);
                QTableWidgetItem* quan1 = ui->tableWidget->item(row,2);
                QTableWidgetItem* inf1 = ui->tableWidget->item(row,3);
                string name = name1->text().toStdString();
                int quantity = quan1->text().toInt();
                string info = inf1->text().toStdString();
                string entry = worker->getName();
                worker->addPostedData(name,amount,quantity,info,entry);
                if (conversionOK)
                {

                    owner->updateFunds(owner->retFunds() - amount);
                }
                else
                {
                    throw MyException("Error converting amount to double.\n");
                }
            }
        }


        saveCSVData("dataNoQ.csv");

        accept();
    }
    catch (const MyException& e) {

        QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    }
    catch (...) {

        QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}
