//HackerRank Small Triangles, Large Triangles problem solution in c programming.
#include <stdio.h>
#include <stdlib.h>

struct Triangle
{
   int a, b, c;
};

int square(struct Triangle t)
{
    int a = t.a, b = t.b, c = t.c;
    return (a + b + c)*(a + b - c)*(a - b + c)*(-a + b + c);
}

void sort_by_square(struct Triangle* a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (square(a[i]) > square(a[j]))
            {
                struct Triangle temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main()
{
   int n;
   scanf("%d", &n);
   struct Triangle *a = calloc(n, sizeof(struct Triangle));
   for (int i = 0; i < n; i++)
      scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
   sort_by_square(a, n);
   for (int i = 0; i < n; i++)
      printf("%d %d %d\n", a[i].a, a[i].b, a[i].c);
   return 0;
}


//Second solution
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
  int a;
  int b;
  int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
  // Sort an array a of the length n
    int *p=malloc(n*sizeof(int)); 
//create array of size n to store "volumes"
    for(int i=0;i<n;i++)
    {
    float a=(tr[i].a+tr[i].b+tr[i].c)/2.0;
//use 2.0 compulsary int/int gives int, int/float gives float
       p[i]=(a*(a-tr[i].a)*(a-tr[i].b)*(a-tr[i].c));
//formula without sqrt as areas are different guarenteed 
//because sqrt dosent work well with float values
    }
//bubble sort
    for(int i=0;i<n;i++)    
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])     
            {
                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
//swapping array of areas in ascending
//and simuntaneously the structure contents
                temp=tr[j].a;
                tr[j].a=tr[j+1].a;
                tr[j+1].a=temp;
                temp=tr[j].b;
                tr[j].b=tr[j+1].b;
                tr[j+1].b=temp;
                temp=tr[j].c;
                tr[j].c=tr[j+1].c;
                tr[j+1].c=temp;
            }
        }
    }
}

int main()
{
  int n;
  scanf("%d", &n);
  triangle *tr = malloc(n * sizeof(triangle));
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
  }
  sort_by_area(tr, n);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
  }
  return 0;
}