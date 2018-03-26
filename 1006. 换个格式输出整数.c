#include <stdio.h>
int main(void)
{
        int N;
        scanf( "%d" , &N );
        int B,S,G;
        B = N / 100;
        N -= B * 100;
        S = N / 10 ;
        N -= S * 10;
        G = N ;
        for(int i = 0; i < B ; i++ )
                putchar('B');
        for(int i = 0 ; i < S ; i++ )
                putchar('S');
        for(int i = 1 ; i <= G ; i++ )
                printf( "%d" , i );
        return 0;
}
