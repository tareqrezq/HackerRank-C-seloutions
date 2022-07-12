//HackerRank sum of digits of a five-digit number problem solution in c programming.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
scanf("%d", &n);
int digit, temp, sum = 0;
temp = n;
//Complete the code to calculate the sum of the five digits on n.
while(temp > 0)
{
    digit = temp % 10;
    sum = sum + digit;
    temp = temp / 10;
}
printf("%d\n",sum);
return 0;
}

//Second solution
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
scanf("%d", &n);
int digit, temp, sum = 0;
temp = n;
//Complete the code to calculate the sum of the five digits on n.
while (n>0) {
        sum += (n%10);
        n=n/10;
    }
printf("%d\n",sum);
return 0;
}