#include<stdio.h>
void Print(int,int);
int main(void)
{
        char data[101];
        int sum=0;
        scanf("%s",data);
        for(int i=0;data[i]!='\0';i++)
        {
                sum+=data[i]-'0';
        }
        Print(sum,0);
        return 0;
}
void Print(int sum,int cnt)
{
        if(sum>10)
                Print(sum/10,cnt++);
        sum=sum%10;
        if(cnt)
                putchar(' ');
        switch(sum)
        {
                case 0:
                        printf("ling");
                        break;
                case 1:
                        printf("yi");
                        break;
                case 2:
                        printf("er");
                        break;
                case 3:
                        printf("san");
                        break;
                case 4:
                        printf("si");
                        break;
                case 5:
                        printf("wu");
                        break;
                case 6:
                        printf("liu");
                        break;
                case 7:
                        printf("qi");
                        break;
                case 8:
                        printf("ba");
                        break;
                case 9:
                        printf("jiu");
                        break;
        }
}
