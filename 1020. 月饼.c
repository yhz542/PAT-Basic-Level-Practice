#include<stdio.h>//解题陷阱。库存和销量的实例虽然是正整数，但题目只保证给正数，也就是说可能出现小数的情况，所以库存和销售价格必须全部定义为浮点型
#include<stdlib.h>
typedef struct
{
        float stock ;
        float sale ;
        float price ;
} biscuit;
int cmp( const void * , const void * ) ;
biscuit *moon = NULL ;
int main(void)
{
        int N , D ;
        scanf("%d %d", &N , &D );
        moon = malloc( sizeof( biscuit ) * N );
        int index[ N ];
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%f" , &moon[ i ].stock ) ;
                index[ i ] = i ;
        }
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%f" , &( moon + i)->sale ) ;
                moon[ i ].price = moon[ i ].sale / moon[ i ].stock ;
        }
        qsort( index , N , sizeof( int ) , cmp ) ;
        float profit = 0 ;
        for( int i = 0 , stock = 0 ; i < N ; i++ )
        {
                if( D - stock >= moon[ index[ i ] ].stock )
                {
                        profit += moon[ index[ i ] ].sale ;
                        stock += moon[ index[ i ] ].stock ;
                }
                else if( D - stock > 0 )
                {
                        profit += moon[ index[ i ] ].price * ( D-stock ) ;
                        stock = D ;
                }
                else
                        break ;
        }
        printf("%.2f",profit);
        return 0 ;
}
int cmp(const void *p1 , const void *p2 )
{
        const int *a1 = (const int *)p1 ;
        const int *a2 = (const int *)p2 ;
        if( moon[ *a1 ].price - moon[ *a2 ].price > 0 )
                return -1 ;
        else if ( moon[ *a1 ].price == moon[ *a2 ].price )
                return 0 ;
        else
                return 1;
}
