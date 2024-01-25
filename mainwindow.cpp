#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createworker.h"
#include "showinfo.h"
#include "setadress.h"
#include "compare.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent, const char* wybor)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Welcome to BigEbowski!");
    this->setWindowIcon(QIcon("C:\\Users\\Dawid\\Desktop\\Studia\\ROK 2\\JIPP\\C++\\complete_gui\\logo.png"));
    owner = new Management("Ala", "Kowalska", "02278394817", "woman", 1, 7300, "manager");
    owner->updateFunds(50000000.0);


    QStringList headers;
    headers << "Name" << "Surname" << "ID" << "Position";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete owner;
}

void MainWindow::on_pushButton_clicked()
{
    createworker *work = new createworker(this);


    connect(work, &createworker::workerCreated, this, &MainWindow::handleWorkerCreated);
    work->setModal(true);
    work->exec();
}

void MainWindow::handleWorkerCreated(Worker *worker)
{

    owner->addWorker(worker);


    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(worker->getName())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(worker->getSurname())));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(worker->getID())));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(worker->getPos())));
}

void MainWindow::on_pushButton_2_clicked()
{
    try {

        QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();
        if (selectedItems.isEmpty()) {
            throw MyException("No item selected.\n");
        }

        QTableWidgetItem *selectedItem = selectedItems.first();
        int row = selectedItem->row();


        owner->fireWorker(ui->tableWidget->item(row, 2)->text().toInt());


        ui->tableWidget->removeRow(row);
    } catch (const MyException &e) {

        QMessageBox::critical(this, "Exception", QString::fromStdString(e.what()));
    } catch (...) {

         QMessageBox::critical(this, "Unknown Exception", "Unknown exception occurred.");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QTableWidgetItem *selectedItem = ui->tableWidget->currentItem();
    if (selectedItem) {
        int row = selectedItem->row();
        Worker *worker = owner->workers_array.at(row);

        showinfo *info = new showinfo(this, worker, owner);
        info->setModal(true);
        info->exec();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QTableWidgetItem *selectedItem = ui->tableWidget->currentItem();
    if (selectedItem) {
        int row = selectedItem->row();
        Worker *worker = owner->workers_array.at(row);

        setAdress *add = new setAdress(this, worker, owner);
        add->setModal(true);
        add->exec();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    compare *comp = new compare(this, owner);
    comp->setModal(true);
    comp->exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Close Application", "Are you sure you want to close the application?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        qApp->quit();
    } else {

        QMessageBox::about(this, "Info","Cancelled closing the application.");
    }
}
