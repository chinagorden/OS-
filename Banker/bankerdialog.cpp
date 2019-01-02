#include "bankerdialog.h"
#include "ui_bankerdialog.h"
#include "mainwindow.h"


BankerDialog::BankerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankerDialog)
{
   // ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
BankerDialog::~BankerDialog()
{
    delete ui;
}

void BankerDialog::updateTable(Box *db)
{
    //ui->tableWidget->clear();
    for(int i=0;i<db->pLength;i++){

        ui->tableWidget->setItem(i,0,new QTableWidgetItem("p"+QString::number(db->ruler[i])));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].claim.R1)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].claim.R2)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].claim.R3)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].allocation.R1)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].allocation.R2)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].allocation.R3)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].claim_allocation.R1)));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].claim_allocation.R2)));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].claim_allocation.R3)));
        ui->tableWidget->setItem(i,10,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].currentAvail.R1)));
        ui->tableWidget->setItem(i,11,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].currentAvail.R2)));
        ui->tableWidget->setItem(i,12,new QTableWidgetItem(QString::number(db->p[db->ruler[i]].currentAvail.R3)));

    }
}

void BankerDialog::showValue(int value)
{

  //  ui->lineEdit->setText(tr("%1").arg(value));
    ui->tableWidget->setRowCount(value);
    ui->spinBox->setMaximum(value-1);

}

void BankerDialog::on_pushButton_clicked()
{
    ui->lineEdit_2->clear();
 //   ui->tableWidget->clear();
    int RowCounter=ui->tableWidget->rowCount();
    QFile file(":/aa.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    else{
        ui->tableWidget->clearContents();
        QTextStream  line(&file);
        int j;
        for(int i=0;i<RowCounter;i++){
           QStringList list= line.readLine().split(QRegExp("\\s+"));
            for( j=0;j<7;j++){
 //             QStringList *list=line.readLine().split(' ');
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString(list.at(j))));
            }
//            int k=1;
//            for(;j<10;j++)
//           {

//            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(ui->tableWidget->item(i,k)->text().toInt()-ui->tableWidget->item(i,k+3)->text().toInt())));
//            k++;
//            }
//            for(;j<13;j++)
//                ui->tableWidget->removeCellWidget(i,j);

        }
    }
    boxinit.initLength(db,RowCounter);
 // boxinit.init_Sum_Available(db,ui->tableWidget_2->item(0,0)->text().toInt(),ui->tableWidget_2->item(0,1)->text().toInt(),ui->tableWidget_2->item(0,2)->text().toInt());
    for (int i = 0; i<db->pLength; i++)
    {

                db->p[i].claim.SetSource(ui->tableWidget->item(i,1)->text().toInt(),
                          ui->tableWidget->item(i,2)->text().toInt(),
                          ui->tableWidget->item(i,3)->text().toInt()
                           );
                db->p[i].allocation.SetSource(ui->tableWidget->item(i,4)->text().toInt(),
                          ui->tableWidget->item(i,5)->text().toInt(),
                          ui->tableWidget->item(i,6)->text().toInt()
                           );

//                db->p[i].claim_allocation.SetSource(db->p[i].claim.R1-db->p[i].allocation.R1,
//                         db->p[i].claim.R2-db->p[i].allocation.R2,
//                         db->p[i].claim.R3-db->p[i].allocation.R3
//                           );

    }
}


void BankerDialog::on_pushButton_2_clicked()//判断原本进程序列是否存在安全序列
{
    boxinit.init_Sum_Available(db,ui->tableWidget_2->item(0,0)->text().toInt(),ui->tableWidget_2->item(0,1)->text().toInt(),ui->tableWidget_2->item(0,2)->text().toInt());
    for(int i=0;i<db->pLength;i++){
        db->p[db->ruler[i]].claim.SetSource(ui->tableWidget->item(i,1)->text().toInt(),
                  ui->tableWidget->item(i,2)->text().toInt(),
                  ui->tableWidget->item(i,3)->text().toInt()
                   );
        db->p[db->ruler[i]].allocation.SetSource(ui->tableWidget->item(i,4)->text().toInt(),
                  ui->tableWidget->item(i,5)->text().toInt(),
                  ui->tableWidget->item(i,6)->text().toInt()
                   );

        db->p[db->ruler[i]].claim_allocation.SetSource(db->p[db->ruler[i]].claim.R1-db->p[db->ruler[i]].allocation.R1,
                                                       db->p[db->ruler[i]].claim.R2-db->p[db->ruler[i]].allocation.R2,
                                                       db->p[db->ruler[i]].claim.R3-db->p[db->ruler[i]].allocation.R3
                );
    }
    int r1 = 0, r2 = 0, r3 = 0;
    int c;
    db->ask.SetSource(r1, r2, r3);	//设置请求资源为0，即无请求
    c = findsafelist.findSafeList(db, 0);	//寻找安全序列，返回结果
    if(c==2){
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setText("t0时刻没有申请资源时就不存在安全序列，请修改文件aa.txt");
    }
   if(c==3){
       QString safelist;

       safelist=findsafelist.safelistoutput(db);
        ui->lineEdit_2->clear();

        ui->lineEdit_2->setText(safelist);
      //  ui->lineEdit_2->insert(QString::number( db->p->currentAvail.R1));

    }
}

void BankerDialog::on_buttonBox_rejected()
{
    this->hide();
    MainWindow *maindialog=new MainWindow;
    maindialog->show();
}

void BankerDialog::on_buttonBox_accepted()
{

}

void BankerDialog::on_pushButton_3_clicked()
{
    int pro,r1,r2,r3,c;
    pro=ui->spinBox->value();
    r1=ui->spinBox_2->value();
    r2=ui->spinBox_3->value();
    r3=ui->spinBox_4->value();
    db->ask.SetSource(r1,r2,r3);
    c=findsafelist.findSafeList(db,pro);
    switch (c) {
    case 1: //请求值大于当前进程需求资源值
    {
        ui->lineEdit_2->setText("请求值大于当前进程需求资源值,重新设置请求资源值");
        break;
    }
    case 2:
    {
        ui->lineEdit_2->setText("分配之后不存在安全序列，系统没有分配");
        break;
    }
    case 3:{
        QString safelist;
        safelist=findsafelist.safelistoutput(db);
        ui->lineEdit_2->setText(safelist);
      //  ui->tableWidget->clear();
        this->updateTable(db);
        break;
    }
    case 0:{
        ui->lineEdit_2->setText("请求值大于系统当前可用资源值,重新设置请求资源值");
        break;
}
    default:
        break;
        }

}
