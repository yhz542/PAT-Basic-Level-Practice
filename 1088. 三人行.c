#include<stdio.h>//注意丙可以是浮点数 特俗处理就可以了
#include<stdlib.h>
#include<stdbool.h>
void Compare( int , int ) ;
int main(void)
{
        int M , X , Y ;
        int jia , yi ;
        double bing ;
        bool flag = false ;
        scanf( "%d %d %d" , &M , &X , &Y ) ;
        for( int i = 99 ; i > 9 ; i-- )
        {
                jia = i ;
                yi = jia / 10 + jia % 10 * 10 ;
                bing = abs( jia - yi ) / (double) X ;
                if( bing == yi / (double) Y )
                {
                        flag = true ;
                        break ;
                }
        }
        if( !flag )
                printf("No Solution") ;
        else
        {
                printf("%d",jia);
                Compare( M , jia ) ;
                Compare( M , yi ) ;
                if( fabs( bing - M ) < 0.00000001 )//浮点数比较 注意用小于一个很小的数
                        printf( " Ping" ) ;
                else if( M > bing )
                        printf( " Gai" ) ;
                else
                        printf( " Cong") ;
        }
        return 0 ;
}
void Compare( int M , int num )
{
        if( M == num )
                printf( " Ping" ) ;
        else if( M > num )
                printf( " Gai" ) ;
        else
                printf( " Cong") ;
}
