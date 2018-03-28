#include<stdio.h>
#include <stdbool.h>
#include <math.h>
bool IsPrime(int number);
int main(void)
{
        int Count = 2 ;
        int Num = 3 ;
        int M , N ;
        scanf( "%d %d" , &M , &N ) ;
        while( Count < M )
        {
                Num += 2 ;
                if( IsPrime( Num ) )
                        Count++ ;
        }
        int c = 0;
        if( M == 1 )
        {
                printf("2");
                c++ ;
        }
        while( Count <= N )
        {
                if( IsPrime( Num ) )
                {
                        if(!c)
                                printf( "%d" , Num ) ;
                        else
                                printf( " %d" , Num ) ;
                        c++ ;
                        Count++ ;
                }
                if( c == 10 )
                {
                        printf("\n");
                        c = 0 ;
                }
                Num += 2 ;
        }
        return 0 ;
}
bool IsPrime(int number)
{
        bool prime = true ;
        if(number % 5 ==0 && number != 5)
                return false;
        int i = (int)sqrt( number ) ;
        for(i = (i%2) ? i : i-1 ; i > 2 ; i -= 2 )
        {
                if(number % i == 0)
                {
                        prime = false ;
                        break ;
                }
        }
        return prime ;
}
