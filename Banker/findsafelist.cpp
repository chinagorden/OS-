#include "findsafelist.h"

FindSafeList::FindSafeList()
{

}

bool FindSafeList::checkList(Box *db)
{

    int i = 0;		//i用于循环
    db->p[db->ruler[i]].currentAvail.SetSource(db->available.R1,db->available.R2,db->available.R3);		//将当前系统可用资源量赋给该序列的第一个进程
    if (!db->p[db->ruler[i]].claim_allocation.lower(db->p[db->ruler[i]].currentAvail))		//若当前进程currentAvail小于该进程需求量(claim-allocation)，返回false
    {
        return false;
    }

    for (i = 1; i< db->pLength; i++)
    {
        //当前进程的可获得资源量currentAvail获得前一个进程的未释放资源前可获得资源量currentAvail
        db->p[db->ruler[i]].currentAvail.SetSource(db->p[db->ruler[i - 1]].currentAvail.R1,db->p[db->ruler[i - 1]].currentAvail.R2,db->p[db->ruler[i - 1]].currentAvail.R3);
        //当前进程的可获得资源量currentAvail获得前一个进程的释放的资源量
        db->p[db->ruler[i]].currentAvail.add(db->p[db->ruler[i - 1]].allocation);
        //若当前进程currentAvail小于该进程需求量(claim-allocation)，返回false
        if (!db->p[db->ruler[i]].claim_allocation.lower(db->p[db->ruler[i]].currentAvail))
        {
            return false;
        }


    }
    return true;	//该序列进程安全。返回true

}

bool FindSafeList::exsitSafeList(Box *db)
{
    int i = 0;
            for (i = 0; i < db->pLength; i++)		//设置逻辑尺的刻度值
            {
                db->ruler[i] = i;
            }
            while (1) 		//该循环将检测逻辑尺刻度值的全排列
            {
                if (checkList(db))			//找到一个安全序列，返回true
                {
                    return true;
                }
                db->clearProcess();			//将所有进程的currentAvail清零

                if (!std::next_permutation(db->ruler, db->ruler + db->pLength))			//所有排列完毕后退出生成排列库函数的调用
                {
                    return false;
                }
            }
            return false;

}

int FindSafeList::findSafeList(Box *db, int i)
{
        //请求值大于系统当前可用资源值，返回0
        if (!db->ask.lower(db->available))
        {
            return 0;
        }
        //请求值大于当前进程需求资源值，返回1
        if (!db->ask.lower(db->p[i].claim_allocation))
        {
            return 1;
        }
     //   Source s(db->p[i].allocation);		//根据请求，分配资源值
        db->available.sub(db->ask);
        db->p[i].allocation.add(db->ask);
        db->p[i].claim_allocation.sub(db->ask);
        if(db->p[i].claim_allocation.R1==0&&db->p[i].claim_allocation.R2==0&&db->p[i].claim_allocation.R3==0){

           //  db->p[i].currentAvail.add(db->p[i].allocation);
             db->available.add(db->p[i].allocation);
             db->p[i].allocation.SetSource(0,0,0);

        }
        if (!exsitSafeList(db))		//判断是否存在安全序列
        {
            db->available.add(db->ask);			//不存在安全序列，回滚，恢复分配前状态，并返回2
            db->p[i].allocation.sub(db->ask);
            db->p[i].claim_allocation.add(db->ask);
            return 2;
        }
        db->ask.SetSource(0, 0, 0);		//找到安全序列，将请求资源置零，返回3
        return 3;
}

QString FindSafeList::safelistoutput(Box *db)
{
    QString safelist;
    safelist.append("安全序列为：");
    for(int i=0;i<db->pLength;i++){
        if(i>0)safelist.append("->");
        safelist.append("p");
        safelist.append(QString::number(db->ruler[i]));
    }
    return safelist;
}



