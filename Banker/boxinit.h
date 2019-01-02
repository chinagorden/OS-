#ifndef BOXINIT_H
#define BOXINIT_H
#include"source.h"
#include"process.h"
#include"box.h"
#include<QDebug>
#include<iostream>

class BoxInit
{
public:
    BoxInit();
    void initLength(Box *db,int n);
    void setAsk(Box *db,int r1,int r2,int r3);
    void init_Sum_Available(Box *db, int r1, int r2, int r3);

};

#endif // BOXINIT_H
