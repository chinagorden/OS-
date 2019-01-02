#ifndef BOX_H
#define BOX_H
#include<QString>
#include"process.h"
#include"source.h"

class Box
{
public:
    Box();
    Process *p;
    Source sum;
    Source available;
    Source ask;
    int pLength;
    int *ruler;
    void clearProcess();
  //  QString safelistoutput(Box *db);


};

#endif // BOX_H
