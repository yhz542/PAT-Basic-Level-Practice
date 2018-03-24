#include <stdio.h>
struct student
{
        char name[11];
        char ID[11];
        int score;
};
void Initialize(struct student *,struct student *);
int main(void)
{
        int n;
        scanf( "%d" , &n );
        struct student highest,lowest,temporary;
        Initialize(&highest,&lowest);
        for( int i = 0 ; i < n ; i++ )
        {
                scanf( "%s %s %d" , temporary.name , temporary.ID , &temporary.score );
                if( temporary.score > highest.score )
                        highest = temporary;
                if( temporary.score < lowest.score )
                        lowest = temporary;
        }
        printf("%s %s\n%s %s",highest.name,highest.ID,lowest.name,lowest.ID);
        return 0;
}
void Initialize (struct student *high,struct student *low)
{
        high->score=-1;
        low->score=101;
}
