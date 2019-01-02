#ifndef PROCESS_H
#define PROCESS_H
#include"source.h"

class Process
{
public:
   /// Process();
    Source claim;//最大需求量
    Source allocation;//进程占有量
    Source claim_allocation;//进程需求量
    Source currentAvail;//进程可获得量

};

#endif // PROCESS_H
