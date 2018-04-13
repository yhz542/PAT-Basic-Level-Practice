#include <stdio.h>
int main( void )
{
        int N;
        scanf( "%d" , &N ) ;
        int Score[ 101 ] = { 0 } ;
        for( int i = 0 , tem ; i < N ; i++ )
        {
                scanf( "%d" , &tem ) ;
                Score[ tem ] ++ ;
        }
        scanf( "%d" , &N ) ;
        for( int i = 0 , tem , flag = 0 ; i < N ; i++ )
        {
                scanf( "%d" ,&tem ) ;
                if( !flag )
                {
                        printf( "%d" , Score[ tem ] ) ;
                        flag = 1 ;
                }
                else
                        printf(" %d" , Score[ tem ] ) ;
        }
        return 0 ;
}
//除去读入数据的方式不同，逻辑和运算过程与python代码一摸一样，但python的运行速度慢了接近6倍
