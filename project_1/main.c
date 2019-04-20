#include <stdio.h>
#include <stdlib.h>
long no_stairs(long n);
int main()
{
    long x,result;
    printf("Please Enter The Number Of Stairs\n");
    scanf("%d",&x);
    result = no_stairs(x+1);
    printf("%d",result);
}


long no_stairs(long n)
{
    long result[n];
    long i,j;
    result[0] = 1;
    result[1] = 1;
    for (i=2; i<n; i++)
    {
       result[i] = 0;
       for (j=1;j<=2&&j<=i; j++)
        result[i] += result[i-j];
    }
    return result[n-1];

}
