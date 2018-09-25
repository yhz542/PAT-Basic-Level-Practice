#include<stdio.h>//先用散列表进行插入和，然后将其插入哈希表中，每插入一次将一次和计入数组中，最后将数组排序输出即为要求的朋友数。
#include<stdlib.h>//寻找和在表中的位置时，如果该位置的状态为空，说明和不在表中 ，则进行插入，否则不插入
#include<stdbool.h>
#include<math.h>
typedef int ElementType ;
typedef int Index ;
typedef Index Position ;
typedef enum { Legitimate , Empty , Deleted } EntryType ;
typedef struct HashEntry Cell ;
struct HashEntry
{
       ElementType Data ;
       EntryType Info ;
};
typedef struct TblNode *HashTable;
struct TblNode
{
        int TableSize ;
        Cell *Cells ;
};
HashTable CreateTable( int TableSize ) ;
bool IsPrime( int );
Position Find( HashTable H , ElementType Key );
bool Insert( HashTable H , ElementType Key) ;
int cmp( const void * a , const void * b ) ;
int main(void)
{
        int N ;
        scanf( "%d" , &N ) ;
        HashTable Table = CreateTable( N ) ;
        int FriendNum[ N ] ;
        int position ;
        int cnt = 0 ;
        char Data[6] ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s" , Data ) ;
                int j = 0 , sum = 0 ;
                while( Data[ j ] != '\0' )
                {
                        sum += Data[ j ] - '0' ;
                        j++ ;
                }
                position = Find( Table , sum ) ;
                if( Table->Cells[position].Info == Empty )
                {
                        Insert( Table , sum ) ;
                        FriendNum[cnt++] = sum ;
                }
        }
        qsort(FriendNum , cnt , sizeof( int ) , cmp );
        printf("%d\n",cnt);
        printf("%d" ,FriendNum[0]) ;
        for(int i = 1 ;i < cnt ; i++)
        {
                printf(" %d" , FriendNum[ i ] ) ;
        }
        return 0;
}
HashTable CreateTable( int TableSize )
{
        TableSize *= 2 ;
        TableSize++ ;
        while( 1 )
        {
                if(IsPrime( TableSize ))
                        break ;
                TableSize += 2 ;
        }
        HashTable H ;
        int i ;
        H = ( HashTable )malloc(sizeof(struct TblNode)) ;
        H->TableSize = TableSize ;
        H->Cells = ( Cell * )malloc( sizeof(Cell) * H->TableSize ) ;
        for( i = 0 ; i < H->TableSize ; i++ )
                H->Cells[i].Info = Empty ;
        return H ;
}
bool IsPrime( int Num )
{
        if( Num == 2 || Num == 5 || Num == 3 )//因子从7开始 所以 2，3，5作为因子单独测试，因为2，3，5分别被2，3，5整除
                return true ;                   //所以先观察是不是2，3，5，然后再看他们是否被2，3，5整除，如果直接整除2，3，5 ，那么2，3，5
        if( !( Num % 2 ) || ! ( Num % 5 ) || ! ( Num % 3 ) )//会被直接判定为非素数。
                return false ;
        int Max = ( int )sqrt( Num ) ;
        Max = (Max % 2) ? Max : Max - 1 ;
        for ( int i = 7 ; i <= Max ; i += 2 )
        {
                for( int j = 0 ; j < 4 ; j++ , i+=2 )
                {
                        if( !( Num % i) )
                                return false;
                }
        }
        if( Num<=1 )
                return false;
        return true;
}
Position Find( HashTable H , ElementType Key )
{
        Position CurrentPos , NewPos;
        int CNum = 0;//记录冲突次数
        NewPos = CurrentPos = Key % H->TableSize ;
        while( H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data !=Key )
        {
                if(++CNum%2 )//奇数次冲突
                {
                        NewPos = CurrentPos + (CNum+1)*(CNum+1)/4 ;//向右移平方
                        if( NewPos >= H->TableSize )
                                NewPos = NewPos % H->TableSize ;
                }
                else
                {
                        NewPos = CurrentPos - CNum*CNum/4 ;//向左移平方
                        while( NewPos < 0 )//相当于求余运算
                                NewPos += H->TableSize ;
                }
        }
        return NewPos ;
}
bool Insert( HashTable H , ElementType Key )
{
        Position Pos = Find( H , Key ) ;
        if( H->Cells[ Pos ].Info != Legitimate )//未被占用
        {
                H->Cells[ Pos ].Info = Legitimate ;
                H->Cells[ Pos ].Data = Key ;
                return true ;
        }
        else
        {
                printf("键值已存在");
                return false;
        }
}
int cmp( const void * a , const void * b )
{
        return *(int *)a -*(int *)b;
}
