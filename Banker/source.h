#ifndef SOURCE_H
#define SOURCE_H


class Source
{
public:
   // Source();
    Source(int r1=0,int r2=0,int r3=0);
    Source(Source &rhs);
    int R1;
    int R2;
    int R3;
    void SetSource(int r1,int r2,int r3);
    void add(Source s);
    void sub(Source s);
    bool lower(Source s);

};

#endif // SOURCE_H
