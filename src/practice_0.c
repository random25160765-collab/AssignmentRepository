#include <string.h>
#include <stdio.h>

void double_num(int *num)
{
    *num = *num * 2;
}

void swap_float(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

char func(char *a, int n)
{
    return *(a + n); 
}

void print_num(int a[], int length)
{
    int *p = a;

    for (int i = 0; i < length; i++)
    {
        printf("%d\n", *p);
        p++;
    }
}

void max_min(int a[], int length, int *max, int *min)
{
    int *p = a;
    *max = *p;
    *min = *p;
    for (int i = 1; i < length; i++)
    {
        if (*(p+i) > *max)    *max = *(p+i);
        if (*(p+i) < *min)    *min = *(p+i);
    }
}

void another_max_min(int a[], int length, int *max, int *min)
{
    *max = a[0];
    *min = a[0];
    for (int i = 1; i < length; i++)
    {
        if (a[i] > *max)    *max = a[i];
        if (a[i] < *min)    *min = a[i];
    }
}

int my_strlen(char *string)
{
    int cnt = 0;
    char *ptr = string;

    if (string == NULL) return 0;

    while (*ptr != '\0')
    {
        ptr++;
        cnt++;
    }

    return cnt;
}

void inverse_array(int a[], int length)
{
    int *left = a;
    int *right = a + length - 1;
    while (left < right)
    {
        int tmp = *left;
        *left = *right;
        *right = tmp;

        left++;
        right--;
    }
}

void another_inverse_array(int a[], int length)
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        i++;
        j--;
    }
}

int second_largest(int arr[], int length) 
{
    if (arr == NULL || length < 2) { return 0; };

    int max = arr[0];
    int cnt;

    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)   
        {
            max = arr[i];
            cnt = i;
        }
    } 

    for (int i = 0, j = 0; i < length && j < length && j != cnt; i++, j++)
    {
        arr[i] = arr[j];
    }

    int second_max = arr[0];

    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)   
        {
            second_max = arr[i];
        }
    } 
    return second_max;
}

