//HackerRank printing pattern using loops problem solution in c programming.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int len = n*2 - 1;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            int min = i < j ? i : j;
            min = min < len-i ? min : len-i-1;
            min = min < len-j-1 ? min : len-j-1;
            printf("%d ", n-min);
        }
        printf("\n");
    }
    return 0;
}

//Second solution
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

int n;
scanf("%d", &n);
int len = 2*n-1;
int min1,min2,min;
  // Complete the code to print the pattern.
  // for rows
  for (int i=1; i <=len; i++) {
      // for col
      for (int j=1; j<=len; j++) {
        // min diff btn vertical sides
        min1 = i<=len-i ? i -1 : len-i;
        // min diff btn horizontal sides
        min2 = j<=len-j ? j -1: len-j;
        // min diff btn vertical & horizontal sides
        min = min1<=min2 ? min1 : min2;
        // print  
        printf("%d ",n-min);
      }
      printf("\n");
  }
return 0;
}