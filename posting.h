#ifndef POSTING_H
#define POSTING_H

#include <QDialog>
#include "pracownicy.h"
namespace Ui {
class posting;
}

class posting : public QDialog
{
    Q_OBJECT

public:
    explicit posting(QWidget *parent = nullptr, Worker* worker=nullptr, Management* owner = nullptr);
    void loadCSVData(const QString& filePath);
    void saveCSVData(const QString& filePath);
    void initializeTable();
    ~posting();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::posting *ui;
    Worker* worker;
    Management* owner;
};

#endif // POSTING_H
