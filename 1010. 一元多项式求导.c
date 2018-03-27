#include<stdio.h>
void calculate ( int * , int * , int );
int main(void)
{
        int exp,coef;
        scanf( "%d %d" , &coef , &exp  );
        calculate( &coef , &exp ,0 );
        while( scanf( "%d %d" , &coef , &exp ) != EOF )
        {
                calculate( &coef , &exp ,1 );
        }
        return 0;
}
void calculate ( int *coef , int *exp ,int n )
{
        int c = *coef,e = *exp ;
        if( !c || !e )
        {
                c = 0 ;
                e = 0 ;
        }
        else
        {
                c *= e ;
                e-- ;
        }
        if(!n)
                printf("%d %d",c,e);
        else if( c || e )
                printf(" %d %d",c,e);
}
