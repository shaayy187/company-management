#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    const char* wybor = nullptr;
    if(argc){
    wybor = (argc > 1) ? argv[1] : nullptr;
    }
    wybor="dark";
    QApplication a(argc, argv);
    if (wybor && strcmp(wybor, "dark") == 0) {
        a.setStyleSheet("QMainWindow, QDialog { background-color: #333; color: white; }"
                        "QListWidget { background-color: #222; color: white; }"
                        "QPushButton { background-color: #555; color: white; }"
                        "QRadioButton { background-color: #333; color: white; }"
                        "QTableWidget { background-color: #222; color: white; alternate-background-color: #808080; }"
                        "QTableWidget QTableWidget::item { background-color: #808080; color: white; }"
                        "QTableWidget QHeaderView::section { background-color: #555; color: white; }"
                        "QTableWidget QScrollBar:vertical { background-color: #555; width: 15px; }"
                        "QTableWidget QScrollBar::handle:vertical { background-color: #333; }"
                        "QTableWidget QScrollBar:horizontal { background-color: #555; height: 15px; }"
                        "QTableWidget QScrollBar::handle:horizontal { background-color: #333; }"
                        "QTableWidget QHeaderView::section:horizontal { background-color: #555; }"
                        "QTableWidget QTableCornerButton::section { background-color: #222; }"
                        "QTableWidget QWidget { background-color: #222; color: white; }"
                        "QMenuBar { background-color: #222; color: white; }"
                        "QStatusBar { background-color: #222; color: white; }"
                        "QLabel {  color: white; }");
    }

    MainWindow w(nullptr,wybor);
    w.show();
    return a.exec();
}
