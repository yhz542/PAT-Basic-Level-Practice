#include<stdio.h>//解题思路：先逆序排序，之后创建新数组并全部置0 然后分4个方向往对应的数组位置放数据，第一次右移和下移需要特殊处理，之后判别只靠
#include<math.h>//观察下一次放置的位置元素是否为0来判断是否需要改变方向。
#include<stdlib.h>
enum { up , down , left , right} ;
int cmp(const void * , const void * ) ;
void Display( int [] , int [] , int , int , int ) ;
int main( void )
{
        int N ;
        scanf("%d" , &N ) ;
        int n = ( int )sqrt( N ) ;
        while( 1 )
        {
                if( ! ( N % n ) )
                        break ;
                else
                        n-- ;
        }
        int m = N / n ;
        int Data[ N ] , New[ N ] ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%d" , Data + i ) ;
                New[ i ] = 0 ;
        }
        qsort( Data , N , sizeof( int ) , cmp ) ;
        Display( Data , New , N , m , n ) ;
        return 0 ;
}
int cmp(const void *p1, const void *p2)
{
        const int *a1 = (const int *)p1 ;
        const int *a2 = (const int *)p2 ;
        return *a2 - *a1 ;
}
void Display( int Data[] , int New[] , int N , int m , int n )
{
        int aspect = right ;
        for( int i = 0 , j = 0 , cnt = 1 ; i < N ; i++ )
        {
                New[ j ] = Data[ i ] ;
                switch( aspect )
                {
                        case up :
                                if( ! New[ j - n ] )
                                        j -= n ;
                                else
                                {
                                        aspect = right ;
                                        j++ ;
                                }
                                break ;
                        case down :
                                if( ( ! New[ j + n ] ) && j + n < N )
                                        j += n ;
                                else
                                {
                                        aspect = left ;
                                        j-- ;
                                }
                                break ;
                        case left :
                                if( ! New[ j - 1 ])
                                        j-- ;
                                else
                                {
                                        aspect = up ;
                                        j -= n ;
                                }
                                break ;
                        case right :
                                if( ( ! New[ j + 1 ] ) && cnt < n )
                                {
                                        j++ ;
                                        cnt++ ;
                                }
                                else
                                {
                                        cnt = 0 ;
                                        aspect = down ;
                                        j += n ;
                                }
                }
        }
        for( int i = 0 , j = 0 ; i < N ; i++ )
        {
                if( j == n - 1 )
                {
                        printf("%d\n",New[ i ] );
                        j = 0 ;
                }
                else
                {
                        printf("%d ",New[ i ] );
                        j++ ;
                }
        }
}
