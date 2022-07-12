//HackerRank Sorting array of strings problem solution in c programming.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

#define CHARS   26
int distinct_chars(const char *a)
{
    int dist = 0;
    int chars[CHARS] = {0};

    while (*a != '\0') {
        int chr = (*a++) - 'a';
        if (chr < CHARS)
            chars[chr]++;
    }
    
    for (int i = 0; i < CHARS; i++)
        if (chars[i])
            dist++;

    return dist;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int res = distinct_chars(a) - distinct_chars(b);
    return (res) ? res : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int res = strlen(a) - strlen(b);
    return (res) ? res : lexicographic_sort(a, b);
}

/* simple bubble sort :) */
void string_sort(char** arr, const int len,int (*cmp_func)(const char* a, const char* b)) {
    int sorted = 0;
    int top = len - 1;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < top; i++) {
            if (cmp_func(arr[i], arr[i + 1]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = 0;
            }
        }
        top--;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}


//Second solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b){
    return strcmp(a, b) > 0;
}

int lexicographic_sort_reverse(const char* a, const char* b){
    return strcmp(a, b) <= 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
    int c1 = 0, c2 = 0;
    int hsh1[26] = {0}, hsh2[26] = {0};
    int n1 = strlen(a);
    int n2 = strlen(b);

    for(int i = 0; i < n1; i++){
        hsh1[a[i] - 'a'] = 1;   
    }

    for(int i = 0; i < n2; i++){
        hsh2[b[i] - 'a'] = 1;   
    }

    for(int i = 0; i < 26; i++){
        if(hsh1[i])
            c1++;
        if(hsh2[i])
            c2++;
    }
    if( c1 != c2)
        return c1 > c2;
    else
        return strcmp(a, b)  > 0;

}

int sort_by_length(const char* a, const char* b){
    if(strlen(a) != strlen(b))
        return strlen(a) > strlen(b);
    else
        return strcmp(a, b) >  0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        int j = i;
        char* p = arr[i];
        while(j > 0){
            if((*cmp_func)(arr[j-1],p) > 0 )
                arr[j] = arr[j-1];
            else
                break;
            j--;
        }
        arr[j] = p;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}