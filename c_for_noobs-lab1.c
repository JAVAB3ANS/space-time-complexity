#include <stdio.h>
int main(void)
{
    srand ((int) time (NULL));
    int d;
    int q;
    int a;
    int c = 0;
    int n = 0;
    while (n <= 9){
        d = rand () % 12 + 1;
        q = rand () % 13;
        printf("What's %d\n", d*q);
        printf("Divided by %d\n",d);
        scanf("%d",&a);
        if (a == q){
            printf("Bravo! You're a mathematician\n");
            c++;
            printf("Correct Answers %d\n", c);
        }else{
            printf("The answer is wrong\n");
            printf("The correct answer is %d\n",q);
        }
        n++;
    }
    printf("Total Correct Answers:%d\n", c);
    printf("out of 10");
}