//HackerRank playing with characters problem solution in c programming.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch,s[100],sen[122];
    scanf("%c\n%s\n%[^\n]",&ch,&s,&sen);
    printf("%c\n%s\n%s",ch,s,sen);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}


//Here in the above code, we use the \n character sequence to print the output of the new line.

//Second solution
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch,s[100],sen[122];
    scanf("%c", &ch);
    scanf("%s", &s);
    scanf(" %[^\n]%*c", &sen);
    printf("%c\n%s\n%s",ch,s,sen);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}