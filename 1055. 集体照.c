#include<stdio.h>//排序算法换成表排序 速度还可以更快，不过这一题既然不卡顺序就没有必要使用表排序了。
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
       char name[ 9 ] ;
       int high ;
} Student ;
int cmp( const void * , const void * ) ;
void display( Student * , int ) ;
int main(void)
{
        int N , K ;
        scanf( "%d %d" , &N , &K ) ;
        int m = N / K , res = N % K ;
        Student Info[ N ] ;
        int index[ N ] ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s %d" , &Info[ i ].name , &Info[ i ].high ) ;
                index[ i ] = i ;
        }
        qsort( Info , N , sizeof( Student ) , cmp ) ;
        int start = 0 ;
        for( int i = 0 , tem ; i < K ; i++ )
        {
                if( !i )
                        tem = m + res ;
                else
                        tem = m ;
                display( &Info[ start ] , tem ) ;
                start += tem ;
        }
        return 0 ;
}
int cmp( const void *p1 , const void *p2 )
{
        const Student *a1 = ( const Student *)p1 ;
        const Student *a2 = ( const Student *)p2 ;
        if( a1 -> high != a2 -> high )
                return a2 -> high - a1 -> high ;
        else
                return strcmp( a1 ->name , a2 -> name ) ;
}
void display( Student *Info , int m )
{
        int flag = m % 2 ;
        for( int i = 0 ; i < m ; i++ )
        {
                if( i == m/2 )
                        printf( "%s" , Info[ 0 ].name ) ;
                else if( i < m/2 )
                        printf( "%s " , flag?Info[ m - 2 - i * 2 ].name : Info[ m-1 - i * 2 ].name ) ;
                else
                        printf( " %s" , flag?Info[ m - 1 - 2*( m - i - 1 )].name : Info[ m - 2 - 2 * ( m - i - 1) ].name ) ;
        }
        putchar('\n') ;
}
