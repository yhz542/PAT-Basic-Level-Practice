#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool Judge( int , int , int , int ) ;
void Swap( int * , int * ) ;
int main(void)
{
        int N ;
        scanf( "%d" , &N ) ;
        int Max1 = 0 , Max2 = 0 ;
        int Input1 , Input2 ;
        int result ,current ;
        current = Max1*Max1 + Max2*Max2 ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%d %d" , &Input1 , &Input2 ) ;
                result = Input1*Input1 + Input2 * Input2 ;
                if( result > current )
                {
                        Max1 = Input1 ;
                        Max2 = Input2 ;
                        current = result ;
                }
        }
        printf("%.2f",sqrt((float)current)) ;
        return 0;
}
