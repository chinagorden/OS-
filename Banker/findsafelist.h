#ifndef FINDSAFELIST_H
#define FINDSAFELIST_H
#include"box.h"
#include"source.h"
#include"process.h"
#include"boxinit.h"
#include<c++/bits/algorithmfwd.h>
#include<c++/bits/stl_algo.h>
#include<QString>
class FindSafeList
{
public:
    FindSafeList();
    bool checkList(Box *db);
    bool exsitSafeList(Box *db);	//判断是否存在安全序列
    int findSafeList(Box *db, int i = 0);
    QString safelistoutput(Box *db);
};

#endif // FINDSAFELIST_H
