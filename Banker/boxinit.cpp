#include "boxinit.h"

BoxInit::BoxInit()
{

}

void BoxInit::initLength(Box *db, int n)
{
    db->pLength = n;
    db->p = new Process[n];
    if(!db->p){
        qDebug()<<"error!no enough memory space！"<<endl;
    }
    db->ruler = new int[n];
    for (int i = 0; i < db->pLength; i++)		//设置逻辑尺的刻度值
    {
        db->ruler[i] = i;
    }
    if (!db->ruler)
            {
               qDebug()<< "error!no enough memory space！"<<endl;
            }
}

void BoxInit::setAsk(Box *db,int r1,int r2,int r3)
{
    db->ask.SetSource(r1, r2, r3);

}

void BoxInit::init_Sum_Available(Box *db, int r1, int r2, int r3)
{
    db->sum.SetSource(r1, r2, r3);
    db->available.SetSource(r1,r2,r3);

}

