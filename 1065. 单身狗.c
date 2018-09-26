#include<stdio.h>//与python版本思路结构一样
#include<stdbool.h>
#include<stdlib.h>
typedef int ElementType ;
typedef int Index ;

typedef struct LNode *PtrToLNode ;
struct LNode
{
        ElementType Data;
        PtrToLNode spouse ;
        PtrToLNode Next;
};
typedef PtrToLNode Position ;
typedef PtrToLNode List ;
typedef struct TblNode *HashTable ;
struct TblNode
{
        int TableSize ;
        List Heads ;
};
HashTable CreateTable( int TableSize ) ;
void Insert( HashTable H , ElementType Hus , ElementType Wif );
void Insert1( HashTable , ElementType ) ;
Position Find( HashTable H , ElementType Key );
bool Delete( HashTable H , ElementType Key );
int cmp( const void * , const void * ) ;
int main( void )
{
        int N , M ;
        scanf( "%d" , &N ) ;
        HashTable Info = CreateTable( N*2 ) ;
        int Husband , Wife ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%d %d" , &Husband , &Wife ) ;
                Insert( Info , Husband , Wife );
        }
        Position Head;
        scanf( "%d" , &M ) ;
        HashTable Data = CreateTable( M ) ;
        int PersonNum ;
        PtrToLNode Person , Couple ;
        int cnt = 0 ;//用于计数有多少对夫妻在派对中
        for( int i = 0 ; i < M ; i++ )
        {
                scanf( "%d" , &PersonNum ) ;
                Person = Find( Info , PersonNum );
                if( !Person )//如果该人不在夫妻名单中，确认为单身狗
                        Insert1( Data , PersonNum );
                else//如果该人在夫妻名单。
                {
                        Couple = Person->spouse ;
                        if( Find( Data , Couple->Data) )//如果他的配偶在派对中
                        {
                                Delete( Data ,  Couple->Data ) ;
                                cnt++;
                        }
                        else
                                Insert1( Data , PersonNum ) ;
                }
        }
        cnt = M-2*cnt ;
        int SingleDog[ cnt ] ;
        cnt = 0 ;
        for( int i = 0 ; i< M ; i++ )
        {
                Head = Data->Heads[i].Next ;
                while( Head )
                {
                        SingleDog[ cnt++ ] = Head->Data ;
                        Head = Head->Next ;
                }
        }
        qsort( SingleDog , cnt , sizeof( int ) , cmp ) ;
        printf("%d\n", cnt );
        if( cnt )
        {
                printf("%05d" , SingleDog[ 0 ] ) ;
                for( int i = 1 ; i < cnt ; i++ )
                        printf(" %05d" , SingleDog[ i ] ) ;
        }
        return 0;
}

HashTable CreateTable( int TableSize )
{
        HashTable H ;
        int i ;
        H = ( HashTable )malloc( sizeof( struct TblNode ) ) ;
        H->TableSize = TableSize ;
        H->Heads = ( List )malloc( sizeof( struct LNode) * TableSize ) ;
        for( i = 0 ; i < TableSize ; i++ )
        {
                H->Heads[i].Data = - 1 ;
                H->Heads[i].spouse = NULL ;
                H->Heads[i].Next = NULL ;
        }
        return H ;
}
Position Find( HashTable H , ElementType Key )
{
        Position P ;
        Index Pos ;
        Pos = Key % H->TableSize ;
        P = H->Heads[ Pos ].Next ;
        while( P &&  P->Data - Key  )
                P = P->Next ;
        return P ;
}
void Insert( HashTable H , ElementType Hus , ElementType Wif )
{
        Position P1 , P2 , NewCell1 ,NewCell2 ;
        Index Pos;
        P1 = Find( H , Hus ) ;
        P2 = Find( H , Wif ) ;
        if( (!P1) && (!P2) )
        {
                NewCell1 = ( Position )malloc( sizeof( struct LNode ) ) ;
                NewCell1->Data = Hus ;
                Pos = Hus % H->TableSize ;
                NewCell1->Next = H->Heads[Pos].Next;//插入链表的第一个
                H->Heads[Pos].Next = NewCell1 ;
                NewCell2 = ( Position )malloc( sizeof( struct LNode ) ) ;
                NewCell2->Data = Wif ;
                Pos = Wif % H->TableSize ;
                NewCell2->Next = H->Heads[Pos].Next;//插入链表的第一个
                H->Heads[Pos].Next = NewCell2 ;
                NewCell1->spouse = NewCell2 ;
                NewCell2->spouse = NewCell1 ;
        }
}
void Insert1( HashTable H , ElementType Key )
{
        Position P , NewCell ;
        Index Pos;
        P = Find( H , Key ) ;
        if( !P )
        {
                NewCell = ( Position )malloc( sizeof(struct LNode ) ) ;
                NewCell->Data = Key  ;
                Pos = Key % H->TableSize ;
                NewCell->Next = H->Heads[Pos].Next;//插入链表的第一个
                H->Heads[Pos].Next = NewCell ;
        }
}
bool Delete( HashTable H , ElementType Key )
{
        Position P ;
        Position Former , Later ;
        Index Pos ;
        Pos = Key % H->TableSize ;
        Former = &( H->Heads[ Pos ]) ;
        P = H->Heads[ Pos ].Next ;
        while( P &&  P->Data - Key  )
        {
                Former = P;
                P = P->Next ;
        }
        if(!P)
                return false ;
        else
        {
                Former->Next = P->Next ;
                free( P ) ;
                return true ;
        }
}
int cmp( const void *a , const void *b )
{
        return *( int * )a - *( int * )b ;
}
