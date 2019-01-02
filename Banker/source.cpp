#include "source.h"

//Source::Source()
//{

//}

Source::Source(int r1, int r2, int r3)
{
    R1=r1;
    R2=r2;
    R3=r3;
}

Source::Source(Source &rhs)
{
    R1=rhs.R1;
    R2=rhs.R2;
    R3=rhs.R3;
}

void Source::SetSource(int r1, int r2, int r3)
{
        R1=r1;
        R2=r2;
        R3=r3;
}

void Source::add(Source s)
{
    R1+=s.R1;
    R2+=s.R2;
    R3+=s.R3;
}

void Source::sub(Source s)
{
    R1-=s.R1;
    R2-=s.R2;
    R3-=s.R3;
}

bool Source::lower(Source s)
{
    if(R1>s.R1) return false;
    if(R2>s.R2) return false;
    if(R3>s.R3) return false;
    return true;
}



