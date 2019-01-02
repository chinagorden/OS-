#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BankerDialog *dlg=new BankerDialog;
    connect(this,SIGNAL(dlgReturn(int)),dlg,SLOT(showValue(int)));
    dlg->setWindowTitle("银行家算法");
    dlg->setWindowIcon(QIcon(":/pic/banker.ico"));
    dlg->show();
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_buttonBox_accepted()
{
    int value=ui->spinBoxProcess->value();
    emit dlgReturn(value);
    close();
//    BankerDialog *dlg=new BankerDialog();
//    connect(this,SIGNAL(dlgReturn(int)),dlg,SLOT(showValue(int)));
//  dl->show();


}

void MainWindow::on_buttonBox_rejected()
{
    this->hide();

}
