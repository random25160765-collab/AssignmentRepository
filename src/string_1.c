#include <string.h>
#include <stdio.h>

char string[] = "document.backup.pdf"; 

void find_the_dot(char *string, int* first, int *last)
{
    char *start = string;

    char *dot_first = strchr(string, '.');
    if (dot_first == NULL) {
        *first = -1;
    } else {
        *first = dot_first - start;
    }
    
    char *dot_last = strrchr(string, '.');
    if (dot_last == NULL) {
        *last = -1;
    } else {
        *last = dot_last - start;
    }
}

int main()
{
    int first, last;
    find_the_dot(string, &first, &last);
    printf("%d, %d\n", first, last);
    return 0;
}