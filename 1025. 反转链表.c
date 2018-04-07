#include<stdio.h>
#include<stdlib.h>//两种实现方式
typedef struct Node *PtrToNode;
struct Node
{
        int Address;
        int Data;
        int Next;
};
PtrToNode CreateSource(int);
void Sort(PtrToNode,int,int);
void Reverse(PtrToNode,int,int);
int EffectiveNum(PtrToNode);
void Output(PtrToNode,int);
int main(void)
{
        PtrToNode Source;
        int EffNum;
        int BeginAddress,TotalNum,ReLength;
        scanf("%d %d %d",&BeginAddress,&TotalNum,&ReLength);
        Source=CreateSource(TotalNum);
        Sort(Source,BeginAddress,TotalNum);
        EffNum=EffectiveNum(Source);
        Reverse(Source,EffNum,ReLength);
        Output(Source,EffNum);
        return 0;
}
PtrToNode CreateSource(int TotalNum)
{
        PtrToNode Source;
        Source=(PtrToNode)malloc(sizeof(struct Node)*TotalNum);
        for(int i=0;i<TotalNum;i++)
        {
                scanf("%d %d %d",&Source[i].Address,&Source[i].Data,&Source[i].Next);
        }
        return Source;
}
void Sort(PtrToNode Source,int BeginAddress,int TotalNum)
{
        struct Node Tem;

for(int i=0;i<TotalNum;i++)
                if(Source[i].Address==BeginAddress)
                {
                        Tem=Source[i];
                        Source[i]=Source[0];
                        Source[0]=Tem;
                        break;
                }
        for(int i=1;i<TotalNum-1;i++)
        {
                for(int j=i;j<TotalNum;j++)
                {
                        if(Source[j].Address==Source[i-1].Next)
                        {
                                Tem=Source[j];
                                Source[j]=Source[i];
                                Source[i]=Tem;
                                break;
                        }
                }
        }
        return;
}
void Output(PtrToNode Result,int TotalNum)
{
        for(int i=0;i<TotalNum;i++)
        {
                printf("%05d %d",Result[i].Address,Result[i].Data);
                if(Result[i].Next!=-1)
                        printf(" %05d",Result[i].Next);
                else
                        printf(" -1");
                putchar('\n');
        }
        return;
}
void Reverse(PtrToNode Source,int TotalNum,int ReLength)
{
        int times;
        struct Node Tem;
        times=TotalNum/ReLength;
        for(int i=0;i<times;i++)
        {
                for(int j=0;j<ReLength/2;j++)
                {
                        Tem=Source[(i+1)*ReLength-j-1];
                        Source[(i+1)*ReLength-j-1]=Source[i*ReLength+j];
                        Source[i*ReLength+j]=Tem;
                }
        }
        for(int i=0;i<TotalNum-1;i++)
        {
                Source[i].Next=Source[i+1].Address;
        }
        Source[TotalNum-1].Next=-1;
        return;
}
int EffectiveNum(PtrToNode Source)
{
        int i=0;
        while(Source[i].Next!=-1)
        {
                i++;
        }
        return i+1;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node *List;
struct Node
{
        int Data;
        int Address;
        int NextAddress;
        List Next;
};
int GetTableLength(int);
int NextPrime(int);
int Hash(int,int);
void Insert(List *,List,int);
int Find(List *,int,int);
List GetInput(int,List *,int);
List Sort(List,int,int *,List *,int);
List Reverse(List,int);
void Test(List L);
int main(void)
{
        List Source,Head,Tem,TemHead;
        List *HashTable;
        int BeginAddress,TotalNum,ReLength,ReTime,TableLength;
        scanf("%d %d %d",&BeginAddress,&TotalNum,&ReLength);
        TableLength=GetTableLength(TotalNum);
        HashTable=(List *)malloc(sizeof(List)*TableLength);
        for(int i=0;i<TableLength;i++)
                HashTable[i]=NULL;
        Source=GetInput(TotalNum,HashTable,TableLength);
        Head=(List)malloc(sizeof(struct Node));
        Head->Next=Sort(Source,BeginAddress,&TotalNum,HashTable,TableLength);
        ReTime=TotalNum/ReLength;
        Tem=Head;
        for(int i=0;i<ReTime;i++)
        {
                TemHead=Tem->Next;
                Tem->Next=Reverse(Tem,ReLength);
                Tem->NextAddress=Tem->Next->Address;
                Tem=TemHead;
        }
        if(Tem->Next)
                Tem->NextAddress=Tem->Next->Address;
        else
                Tem->NextAddress=-1;
        Test(Head);
        free(HashTable);
        free(Source);
        return 0;
}
int GetTableLength(int N)
{
        int Prime;
        N*=2;
        N++;
        while((N%4)!=3)
                N+=2;
        Prime=NextPrime(N);
        if(Prime<3)
                Prime=3;
        return Prime;
}
int NextPrime(int N)
{
        int i,p=N;
        while(1)
        {
                for(i=(int)sqrt(p);i>2;i--)
                        if(!(p%i))
                                break;
                if(i==2)
                                break;
                else
                                p+=4;
        }
        return p;
}
int Hash(int Key,int P)
{
        return Key%P;
}
void Insert(List *HashTable,List L,int TableLength)
{
        int Index;
        Index=Find(HashTable,L->Address,TableLength);
        if(HashTable[Index]==NULL)
        {
                HashTable[Index]=L;
        }
}
int Find(List *HashTable,int Address,int TableLength)
{
        int NewPosition,CurPosition;
        int CNum=0;
        NewPosition=CurPosition=Hash(Address,TableLength);
        while(HashTable[NewPosition]!=NULL&&HashTable[NewPosition]->Address!=Address)
        {
                if(++CNum%2)
                {
                        NewPosition=CurPosition+(CNum+1)*(CNum+1)/4;
                        if(NewPosition>=TableLength)
                                NewPosition=NewPosition%TableLength;
                }
                else
                {
                        NewPosition=CurPosition-CNum*CNum/4;
                        while(NewPosition<0)
                                NewPosition+=TableLength;
                }
        }
        return NewPosition;
}
List GetInput(int TotalNum,List *HashTable,int TableLength)
{
        List Source;
        Source=(List)malloc(sizeof(struct Node)*TotalNum);
        for(int i=0;i<TotalNum;i++)
        {
                scanf("%d %d %d",&Source[i].Address,&Source[i].Data,&Source[i].NextAddress);
                Source[i].Next=NULL;
                Insert(HashTable,Source+i,TableLength);
        }
        return Source;
}
List Sort(List Source,int BeginAddress,int *TotalNum,List *HashTable,int TableLength)
{
        if(*TotalNum<1)
                return NULL;
        List Head,Tem;
        int cnt=1;
        int Position;
        int i;
        Position=Find(HashTable,BeginAddress,TableLength);
        Head=HashTable[Position];
        Tem=Head;
        for(i=1;i<*TotalNum;i++)
        {
                Position=Find(HashTable,Tem->NextAddress,TableLength);
                cnt++;
                Tem->Next=HashTable[Position];
                Tem=Tem->Next;
                if(-1==Tem->NextAddress)
                        break;
        }
        *TotalNum=cnt;
        return Head;
}
void Test(List L)
{
        L=L->Next;
        while(L->Next)
        {
                printf("%05d %d %05d\n",L->Address,L->Data,L->NextAddress);
                L=L->Next;
        }
        printf("%05d %d %d\n",L->Address,L->Data,L->NextAddress);
}
List Reverse(List Source,int ReLength)
{
        List New=Source->Next,Old,Tmp;
        Old=New->Next;
        for(int j=1;j<ReLength;j++)
        {
                Tmp=Old->Next;
                Old->Next=New;
                Old->NextAddress=New->Address;
                New=Old;
                Old=Tmp;
        }
        Source->Next->Next=Old;
        return New;
}
