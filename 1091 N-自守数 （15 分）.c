#include <stdio.h>//思路：找出一个数等于10的n次方 ，这个数用来整除NK2 得到NK2的末尾位用于和K进行比较是否相等。
#include <stdbool.h>
bool IsNeed( int* ,int* );
int main(void)
{
        int M,num;
        scanf("%d",&M);
        for( int i = 0,N ; i < M ; ++i )
        {
                scanf("%d",&num);
                if( IsNeed(&num,&N ))
                        printf("%d %d\n",N,num);
                else
                        printf("No\n");
        }
        return 0;
}
bool IsNeed( int *num , int *N )
{
        int tenTimes = 10 ;
        while( 0 != (*num)/tenTimes )
        {
                tenTimes *= 10;
        }
        int square = (*num) * (*num) ;
        for( int i = 1 ; i < 10 ; ++i)
        {
                int tem = i*square ;
                if( tem%tenTimes == *num )
                {
                        *N = i ;
                        *num = tem;
                        return true;
                }
        }
        return false;
}
