#include <stdio.h>//传统方法 最后先找出最大的销量，然后根据销量查找序号。
#include <stdlib.h>//浪费时间
#include <memory.h>
int main(void)
{
        int M = 0 , N = 0 ;
        scanf( "%d%d" , &N , &M ) ;
        int *sale = (int *)malloc(sizeof( int ) * N ) ;
        memset(sale , 0 , sizeof( int )*N );
        for( int i = 0 ; i < M ; ++i )
        {
                for( int j = 0 , val ; j < N ; ++j )
                {
                        scanf("%d",&val);
                        sale[ j ] += val ;
                }
        }
        int Max = 0;
        for( int i = 0 ; i < N ; ++i )
                if(Max < sale[ i ])
                        Max = sale[ i ] ;
        printf("%d\n",Max);
        for( int i = 0 ,flag = 1; i < N ; ++i )
        {
                if( Max == sale[ i ] )
                {
                        if(flag)
                                flag = 0 ;
                        else
                                putchar(' ');
                        printf("%d",i+1);
                }
        }
        return 0 ;
}

#include <stdio.h>//直接找最大销量的序号，并记录在数组中，同时记录最大销量的个数，之后直接输出序号。浪费空间
#include <stdlib.h>
#include <memory.h>
int main(void)
{
        int M = 0 , N = 0 ;
        scanf( "%d%d" , &N , &M ) ;
        int *sale = (int *)malloc(sizeof( int ) * N ) ;
        memset(sale , 0 , sizeof( int )*N );
        for( int i = 0 ; i < M ; ++i )
        {
                for( int j = 0 , val ; j < N ; ++j )
                {
                        scanf("%d",&val);
                        sale[ j ] += val ;
                }
        }
        int maxLen = 0 ;
        int *store = (int *)malloc(sizeof(int)*N);
        memset(store , 0 ,sizeof(int)*N);
        for( int i = 0 ,Max= 0, j = 0 ; i < N ; ++i )
        {
                if( Max < sale[ i ] )
                {
                        Max = sale[ i ] ;
                        store[ 0 ] = i ;
                        j = 1 ;
                        maxLen = 1;
                }
                else if( Max == sale[ i ] )
                {
                        store[j++] = i;
                        ++maxLen ;
                }
        }
        int Max = sale[store[0]];
        printf("%d\n%d",Max,store[0]+1);
        for( int i = 1 ; i < maxLen ; ++i )
                printf(" %d",store[i]+1);
        return 0 ;
}
