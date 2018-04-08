//基本思路：先排序，之后以每一个数为首元素，向后遍历，不满足完美数列时跳出循环。如果当前完美数列长度比之前探索的完美长度大，则更新完美长度。
//优化思路：1.切尾巴
//因为数列长度固定，所以距离数列尾端长度小于当前完美长度的元素不必遍历。举例：假如当前排序好的数列为 1 2 3 4 5 ，目前探测的完美数列长度为 3 ，那么
// 只需要依次遍历 1 和 2 ， 因为从3开始往后数，即使全部数据满足条件，长度也不可能大于 3，不可能更新完美长度，所以没有遍历的必要。
//2.记录路途。
//因为是升序数列。所以前一次结束循环的点可以作为下一次循环的开始点。 长度直接用下标相减即可。
#include<stdio.h>
#include<stdlib.h>
int cmp(const void * , const void * ) ;
int main(void)
{
        int N ;
        unsigned int p;
        scanf( "%d %u" , &N , &p ) ;
        int *Data = (int *) malloc ( sizeof( int ) * N ) ;
        for( int i = 0 ; i < N ; i++ )
        {
             scanf( "%d" , Data + i ) ;
        }
        qsort( Data , N , sizeof(int) , cmp ) ;
        int cnt = 0 ;
        int NextStart = 1 ;
        for( int i = 0 , tem ; i < N - cnt ; i++ )
        {
                tem = NextStart - i ;
                for( int j = NextStart ; j < N ; j++ )
                {
                        if( (long long)(Data[i] * p) < Data[ j ])
                        {
                                NextStart = j ;
                                break;
                        }
                        tem++ ;
                }
                if( cnt < tem )
                        cnt = tem ;
        }
        printf("%d",cnt);
        return 0;
}
int cmp( const void *p1 , const void *p2 )
{
        const int *a1 = (const int *)p1 ;
        const int *a2 = (const int *)p2 ;
        return *a1 - *a2 ;
}
