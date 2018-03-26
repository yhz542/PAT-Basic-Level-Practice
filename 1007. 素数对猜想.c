#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool IsPrime(int);
int main(void)
{
        int N;
        int Count = 0;
        scanf("%d",&N);
        int former = 3,latter = 5;
        while(latter <= N)
        {
                if(IsPrime( latter ))
                {
                        Count++;
                        former = latter;
                        latter += 2;
                }
                else
                {
                        former += 4;
                        while(!IsPrime(former))
                                former += 2;
                        latter = former + 2;
                }
        }
        printf("%d",Count);
        return 0;
}
bool IsPrime(int number)
{
        bool prime=true;
        if(number % 5 ==0 && number != 5)
                return false;
        int i = (int)sqrt(number);
        for(i=(i%2)?i:i-1;i>2;i-=2)
        {
                if(number%i==0)
                {
                        prime=false;
                        break;
                }
        }
        return prime;
}
