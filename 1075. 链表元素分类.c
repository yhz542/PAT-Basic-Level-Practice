#include<stdio.h>//方法与py版本基本一致
#include<stdlib.h>
typedef struct Element Node ;
typedef struct Element *Position ;
struct Element
{
        int Data ;
        Position next ;
};
int main(void)
{
        int FirstAddress , N , K ;
        int Address , Data , Next ;
        scanf("%d %d %d", &FirstAddress , &N , &K ) ;
        Node List[ 100000 ] ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf("%d %d %d",&Address , &Data , &Next ) ;
                List[ Address ].Data = Data ;
                if( Next != -1 )
                        List[ Address ].next = &List[ Next ] ;
                else
                        List[ Address ].next = NULL ;
        }
        Position Head = &List[ FirstAddress ];
        int length = 0;
        int negative = 0 , great = 0 , medium = 0 ;
        while( Head )
        {
                if( Head->Data < 0 )
                        negative++ ;//计算负数个数
                else if( Head->Data > K )
                        great++ ;//大于K个数
                else
                        medium++ ;//正数小于K个数
                length++ ;//总长度
                Head = Head->next ;
        }
        int address[ length ] ;
        Head = &List[ FirstAddress ];
        for( int i = 0 , x = 0 , y = negative , z = negative + medium ; i < length ; i++ )//将区域划分成三部分进行赋值
        {
                Address = Head - List ;//通过地址值计算索引address
                if( List[ Address ].Data < 0 )//判断属于哪一区域 然后进行赋值
                        address[ x++ ] =Address ;
                else if( List[ Address ].Data > K )
                        address[ z++ ] = Address ;
                else
                        address[ y++ ] = Address ;
                Head = Head->next ;
        }
        for( int i = 0 ; i < length - 1 ; i++ )
                printf("%05d %d %05d\n",address[ i ] , List[ address[i ]].Data , &List[ address[ i+1 ] ] - List ) ;
        printf("%05d %d -1",address[ length - 1 ] , List[ address[ length - 1] ].Data ) ;
        return 0 ;
}
