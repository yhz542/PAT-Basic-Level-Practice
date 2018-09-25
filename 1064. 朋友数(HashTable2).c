#include<stdio.h>//分离链接法
#include<stdbool.h>
#include<stdlib.h>
typedef int ElementType ;
typedef int Index ;
typedef struct LNode *PtrToLNode ;
struct LNode
{
        ElementType Data;
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
HashTable CreateTable( int ) ;
Position Find( HashTable , ElementType ) ;
bool Insert( HashTable , ElementType ) ;
int cmp(const void * , const void *) ;
int main( void )
{
        int N ;
        scanf( "%d" , &N ) ;
        HashTable H = CreateTable( N ) ;
        char Data[6] ;
        int FriendNum[ N ] ;
        int cnt = 0 ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s" , Data ) ;
                int sum = 0 , j = 0 ;
                while( Data[ j ] != '\0' )
                {
                        sum += Data[j] -'0' ;
                        j++ ;
                }
                if( !Find( H , sum ) )
                {
                        Insert( H , sum );
                        FriendNum[ cnt++ ] = sum ;
                }
        }
        qsort(FriendNum , cnt , sizeof( ElementType ) , cmp ) ;
        printf("%d\n" , cnt );
        printf("%d" , FriendNum[0] ) ;
        for( int i = 1 ; i < cnt ; i++ )
                printf( " %d" , FriendNum[ i ] ) ;
        return 0 ;
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
                H->Heads[i].Data = -1 ;
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
        while( P && P->Data - Key )
                P = P->Next ;
        return P ;
}
bool Insert( HashTable H , ElementType Key )
{
        Position P , NewCell ;
        Index Pos;
        P = Find( H , Key ) ;
        if( !P )
        {
                NewCell = ( Position )malloc( sizeof(struct LNode ) ) ;
                NewCell->Data = Key ;
                Pos = Key % H->TableSize ;
                NewCell->Next = H->Heads[Pos].Next;//插入链表的第一个
                H->Heads[Pos].Next = NewCell ;
                return true ;
        }
        else
        {
                printf("关键词已存在");
                return false ;
        }
}
int cmp(const void *a , const void *b)
{
        return *(int *)a - *(int *)b ;
}
