#include <stdio.h>
#include <stdlib.h>
typedef struct Node *Ptr;
typedef struct Node node;
struct Node
{
        int Data;
        Ptr Next;
};
Ptr Inititalize( int );
void CreateList( Ptr );
void Check( Ptr , int );
int cmp(const void *p1,const void *p2);
int main(void)
{
        int n;
        scanf( "%d" , &n );
        Ptr Space = Inititalize( n );//初始化
        for(int i = 0 ; i < n ; i++ )
        {
                scanf( "%d" , &Space[i].Data );//初始化数组链表的表头
                CreateList(Space+i);
        }
        Check(Space,n);
        qsort(Space,n,sizeof(node),cmp);
        int flag = 0;
        for(int i=n-1;i>0;i--)
        {
                if(Space[i].Data==-1)
                        break;
                if(flag==0)
                {
                        printf("%d",Space[i].Data);
                        flag=1;
                }
                else
                        printf(" %d",Space[i].Data);
        }
        return 0;
}
Ptr Inititalize(int n)
{
        Ptr Space = malloc( sizeof (node) * n );
        for( int i = 0 ; i < n ; i++ )
        {
                Space[i].Next = NULL;
                Space[i].Data = -1;
        }
        return Space;
}
void CreateList(Ptr Head)
{
        int Num = Head->Data;
        Ptr Tem,former;
        while ( Num != 1 )
        {
                former = Head;
                Tem = Head->Next ;
                Ptr New = malloc( sizeof (node) );
                New->Data = Num;
                while( Tem && Num > Tem->Data)
                {
                        former=Tem;
                        Tem=Tem->Next;
                }
                New->Next = Tem;
                former->Next=New;
                if( Num % 2 )//奇数
                        Num = (3 * Num + 1) / 2;
                else
                        Num /= 2;
        }
};
void Check( Ptr Space, int n )
{
        int Num;
        Ptr Tem;
        for(int i = 0 ; i < n ; i++ )
        {
                Num = Space[i].Data;
                for(int j = 0 ; j < n ; j++)
                {
                        Tem = Space[j].Next;
                        if( i == j || Space[j].Data==-1)
                                continue;
                        while( Tem && Num > Tem->Data )
                                Tem=Tem->Next;
                        if(!Tem)
                                continue;
                        else if( Num == Tem->Data )
                        {
                                Space[i].Data = -1;
                                break;
                        }
                }
        }
}
int cmp(const void *p1,const void *p2)
{
        const Ptr a1 = (const Ptr)p1;
        const Ptr a2 = (const Ptr)p2;
        if(a1->Data<a2->Data)
                return -1;
        else if(a1->Data==a2->Data)
                return 0;
        else
                return 1;
}
解题思路：先读入所有数，然后将所有数的3n+1数列计算出来并以从小到大的顺序读入数列中。
依次对每一个数进行检查，如果在其他数列中出现，直接将其记为-1（非关键数）
用qsort对其排序
倒序输出
