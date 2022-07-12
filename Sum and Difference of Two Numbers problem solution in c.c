//HackerRank Sum and Difference of Two Numbers problem solution in c programming.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a,b,sum=0,sub=0;
    float c,d,s=0,su=0;
    scanf("%d%d",&a,&b);
    sum= a+b;
    sub=a-b;
    printf("%d %d\n",sum,sub);
    scanf("%f%f",&c,&d);
    s=c+d;
    su=c-d;
    printf("%0.1f %0.1f",s,su);
    
    return 0;
}


//Second solution
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a, b;
    float c, d;
    scanf("%d %d", &a, &b);
    scanf("%f %f", &c, &d);
    
    printf("%d %d\n%.1f %.1f", a+b, a-b, c+d, c-d);
    
    return 0;
}