#ifndef BANKERDIALOG_H
#define BANKERDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include<iostream>
#include<QFile>
#include <QDebug>
#include<QString>
#include<QVector>
#include <fstream>
#include"process.h"
#include"source.h"
#include"box.h"
#include"boxinit.h"
#include"findsafelist.h"
#include"mainwindow.h"

namespace Ui {
class BankerDialog;
}

class BankerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BankerDialog(QWidget *parent = 0);
    ~BankerDialog();
    Box *db=new Box;
    BoxInit boxinit;
    FindSafeList findsafelist;
    void updateTable(Box *db);
private:
    Ui::BankerDialog *ui;
public slots:
    void showValue(int value);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_pushButton_3_clicked();
};

#endif // BANKERDIALOG_H
