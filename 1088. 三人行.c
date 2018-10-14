#include<stdio.h>
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
                if( fabs( bing - M ) < 0.00000001 )
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
