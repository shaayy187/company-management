    #ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    #include "pracownicy.h"
    #include <QMainWindow>
    #include <vector>
    #include "deleteworker.h"
    #include "createworker.h"
    #include "showinfo.h"
    #include "compare.h"


    QT_BEGIN_NAMESPACE
    namespace Ui {
    class MainWindow;
    }
    QT_END_NAMESPACE

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr, const char* wybor = nullptr);
        ~MainWindow();

    private slots:
        void on_pushButton_clicked();
        void handleWorkerCreated(Worker *worker);
        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_5_clicked();

    private:
        Ui::MainWindow *ui;
        Management* owner;

    };
    #endif // MAINWINDOW_H
