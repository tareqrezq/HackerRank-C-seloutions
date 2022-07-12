//HackerRank 1D arrays in c programming problem solution.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int *val = malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
        sum+=val[i];
    }
    printf("%i",sum);
    free(val);
}

//Second solution
#include <stdio.h>
int main()
{
    int n,val,sum=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&val);
        sum+=val;
    }
    printf("%i",sum);
}