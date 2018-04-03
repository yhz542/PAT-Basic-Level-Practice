#include<stdio.h>
enum { B , C , J};
enum { win , draw , lose };
typedef struct
{
        char fist;
        int times;
} Node ;
void Judge( char , char , int* , int * , Node * , Node * );
void Display( Node *) ;
int main(void)
{
        int N;
        char a , b ;
        int Info_A[3] = { 0 } ;
        int Info_B[3] = { 0 } ;
        Node Win_A[3] ={{'B',0},{'C',0},{'J',0}};
        Node Win_B[3] ={{'B',0},{'C',0},{'J',0}};
        scanf( "%d\n" , &N ) ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf("%c %c\n",&a,&b);
                Judge( a , b , Info_A , Info_B , Win_A , Win_B ) ;
        }
        printf( "%d %d %d\n" , Info_A[ 0 ] , Info_A[ 1 ] , Info_A[ 2 ] ) ;
        printf( "%d %d %d\n" , Info_B[ 0 ] , Info_B[ 1 ] , Info_B[ 2 ] ) ;
        Display(Win_A);
        putchar(' ');
        Display(Win_B);
        return 0 ;
}
void Judge( char a , char b , int *Info_A , int *Info_B , Node *Win_A , Node *Win_B )
{
        if( a == b )
        {
                Info_A[ draw ]++ ;
                Info_B[ draw ]++ ;
        }
        else if( a < b )
        {
                if( a == 'B' && b == 'J' )
                {
                        Info_A[ lose ]++ ;
                        Info_B[ win ]++ ;
                        Win_B[ J ].times++ ;
                }
                else
                {
                        Info_B[ lose ]++ ;
                        Info_A[ win ]++ ;
                        switch( a )
                        {
                                case 'B':
                                        Win_A[ B ].times++ ;
                                        break ;
                                case 'C':
                                        Win_A[ C ].times++ ;
                                        break ;
                                case 'J':
                                        Win_A[ J ].times++ ;
                        }
                }
        }
        else
        {
                if( a == 'J' && b == 'B' )
                {
                        Info_B[ lose ]++ ;
                        Info_A[ win ]++ ;
                        Win_A[ J ].times++ ;
                }
                else
                {
                        Info_A[ lose ]++ ;
                        Info_B[ win ]++ ;
                        switch( b )
                        {
                                case 'B':
                                        Win_B[ B ].times++ ;
                                        break ;
                                case 'C':
                                        Win_B[ C ].times++ ;
                                        break ;
                                case 'J':
                                        Win_B[ J ].times++ ;
                        }
                }
        }
}
void Display( Node *Win )
{
        int t = 0 ;
        char c = 'B';
        for( int i = 0 ; i < 3 ; i++ )
        {
                if( Win[i].times > t)
                {
                        t = Win[i].times ;
                        c = Win[i].fist ;
                }
        }
        printf("%c",c);
}
