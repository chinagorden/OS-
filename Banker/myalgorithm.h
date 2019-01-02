#ifndef MYALGORITHM_H
#define MYALGORITHM_H
template<calss BidrectionalIterator>
bool next_permutation(BidrectionalIterator first,BidrectionalIterator last)
{
    if(first == lase) return false; /* 空区间 */
    BidrectionalIterator i = first;
    ++i;
    if(i == last) return false;  /* 只有一个元素 */
    i = last;                    /* i指向尾端 */
    --i;
    for(;;)
    {
        BidrectionalIterator ii = i;
        --i;
        /* 以上锁定一组(两个)相邻元素 */
        if(*i < *ii)           /* 如果前一个元素小于后一个元素 */
        {
            BidrectionalIterator j = last; /* 令j指向尾端 */
            while(!(*i < *--j));     /* 由尾端往前找，直到遇到比*i大的元素 */
            iter_swap(i,j);          /* 交换i,j */
            reverse(ii,last);        /* 将ii之后的元素全部逆序重排 */
            return true;
        }
        if(i == first)       /* 进行至最前面了 */
        {
            reverse(first,last);    /* 全部逆序重排 */
            return false;
        }
    }
}


#endif // MYALGORITHM_H
