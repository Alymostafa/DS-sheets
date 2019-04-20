#include <stdio.h>
#include <stdlib.h>
int solve(int n);
int main()
{
    int x,y;
    printf("Enter your number stairs\n");
    scanf("%d",&x);
    y=solve(x);
    printf("%d",y);
    return 0;
}



int solve(int n)
{
    if(n==0)
        return 1;

    return (solve(n-1)+(n>=2 ? solve(n-2):0));




}

