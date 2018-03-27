#include <stdio.h>
#include <stdlib.h>
void Print(int *,int ,int) ;
int main(void)
{
        int Length , Offset ;
        scanf( "%d %d" , &Length , &Offset) ;
        int *Data ;
        Data = malloc( sizeof( int ) * Length ) ;
        for( int i = 0 ; i < Length ; i++ )
                scanf( "%d" , Data + i ) ;
        Print ( Data , Length , Offset) ;
        return 0;
}
void Print(int *Data,int Length,int Offset)
{
        int RealOffset = Length - ( Offset % Length ) ;
        int TotalLength = Length + RealOffset ;
        printf( "%d" , Data[ RealOffset % Length ]);
        for ( int i = RealOffset + 1 , flag = 0 ; i < TotalLength ; i++ )
        {
                printf( " %d" , Data[ i % Length ]);
        }
}
