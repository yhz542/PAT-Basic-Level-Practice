#include <stdio.h>
#include <stdlib.h>
enum A { A1 , A2 , A3 , A4 , A5 } ;
void classify( int , int [] , int * ) ;
int flag = 0 ;
int F = 0 ;
int main(void)
{
        int N ;
        scanf( "%d" , &N ) ;
        int Data[ 5 ] = { 0 };
        int Count = 0 ;
        for (  int i = 0 , type , num ; i < N ; i++ )
        {
                scanf( "%d" , &num ) ;
                classify( num , Data , &Count ) ;
        }
        if( !Data[ 0 ] )
                printf( "N" ) ;
        else
                printf( "%d" , Data[ 0 ] );
        for( int i = 1 ; i < 5 ; i++ )
        {
                if( !Data[ i ] )
                {
                        if( i==1 && F )
                                printf(" 0") ;
                        else
                                printf(" N") ;
                }
                else
                {
                        if( i == 3 )
                                printf(" %.1f",(float)Data[ i ] / Count );
                        else
                                printf(" %d" , Data[ i ]);
                }
        }
        return 0;
}
void classify( int num , int Data[] , int *Count)
{
        switch( num % 5 )
        {
                case 0 :
                        if ( !(num%10))
                        {
                                Data[ A1 ] += num ;
                        };
                        return ;
                case 1 :
                        Data[ A2 ] += ( !( ++flag % 2) ? ( -1 * num ) : num ) ;
                        F = 1 ;
                        return ;
                case 2 :
                        Data[ A3 ]++ ;
                        return ;
                case 3 :
                        Data[ A4 ] += num ;
                        (*Count) ++ ;
                        return ;
                case 4 :
                        if( num > Data[ A5 ] )
                                Data[ A5 ] = num;
                                return ;
        }
}
