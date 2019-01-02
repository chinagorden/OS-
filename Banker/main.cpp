#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("银行家算法");
    w.setWindowIcon(QIcon(":/pic/banker.ico"));
    return a.exec();
}
