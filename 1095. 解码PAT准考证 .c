#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Info//输入时直接进行格式读取可大大节约时间，排序用的是桶排序，并不对原址进行操作
{
        int score ;
        char level ;
        int room ;
        int date ;
        int ID;
};
struct Info *student;
int NumOfTestRoom[1000]={0};
int cmp1(const void *a , const void *b)
{
        int A = *(int *)a;
        int B = *(int *)b;
        if( student[A].score != student[B].score )
                return student[B].score-student[A].score;
        else if( student[A].level!=student[B].level )
                return student[A].level-student[B].level;
        else if( student[A].room!=student[B].room)
                return student[A].room - student[B].room ;
        else if( student[A].date!=student[B].date)
                return student[A].date - student[B].date;
        else
                return student[A].ID - student[B].ID;
}
int cmp2( const void *A , const void *B)
{
        int a =*(int *)A;
        int b =*(int *)B;
        if(NumOfTestRoom[a]==NumOfTestRoom[b])
                return a-b;
        else
                return NumOfTestRoom[b]-NumOfTestRoom[a];
}
void Function1( char *order , int N )
{
        int cnt = 0 ;
        int index[N];
        for( int i = 0 ; i < N ; ++i )
        {
                if( student[ i ].level == order[ 0 ] )
                {
                        index[cnt++] = i;
                }
        }
        qsort(index,cnt,sizeof(int),cmp1);
        if( !cnt )
        {
                printf("NA\n");
                return;
        }
        for( int i = 0,Index ; i < cnt ; ++i )
        {
                Index = index[i];
                printf("%c%d%06d%03d %d\n",student[Index].level,student[Index].room,student[Index].date,student[Index].ID,student[Index].score);
        }//输出时注意补0
}
void Function2( char *order , int N )
{
        int cnt = 0 ,sum = 0 ;
        int Order = atoi(order);
        for( int i = 0 ; i < N ; ++i )
        {
                if(Order == student[i].room )
                {
                        ++cnt;
                        sum+=student[i].score;
                }
        }
        if(!cnt)
        {
                printf("NA\n");
                return ;
        }
        else
                printf("%d %d\n",cnt,sum);
}
void Function3( char *order , int N )
{
        int Date = atoi(order);
        int cnt = 0 ;
        int Index[N];
        for( int i = 0 ; i < N ; ++i )
        {
                if(Date == student[i].date)
                {
                        if(!NumOfTestRoom[student[i].room]++)
                                Index[cnt++]=student[i].room;
                }
        }
        if(!cnt)
        {
                printf("NA\n");
                return;
        }
        qsort(Index,cnt,sizeof(int),cmp2);
        for( int i = 0 ; i < cnt ; ++i )
        {
                printf("%d %d\n",Index[i],NumOfTestRoom[Index[i]]);
                NumOfTestRoom[Index[i]]=0;
        }
}
int main( void )
{
        int N , M ;
        scanf( "%d%d" , &N , &M ) ;
        student = (struct Info *)malloc(sizeof(struct Info)*N);
        for( int i = 0 , score = 0 ; i < N ; ++i )
        {
                scanf("\n%c%3d%6d%3d %d" ,&student[i].level , &student[i].room , &student[i].date , &student[i].ID,&student[i].score );
        }
        char order[50] ;
        for( int i = 1 ,type ; i <= M ; ++i )
        {
                scanf("%d %s",&type , order);
                printf("Case %d: %d %s\n", i , type , order );
                switch(type)
                {
                case 1 :
                        Function1(order,N);
                        break;
                case 2 :
                        Function2(order,N);
                        break;
                case 3 :
                        Function3(order,N);
                        break;
                }
        }
        return 0 ;
}
