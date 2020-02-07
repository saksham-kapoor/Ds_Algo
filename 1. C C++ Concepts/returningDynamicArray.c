#include <stdio.h>
#include <stdlib.h>

int *dynamicArray(int n)
{
    int *a;
    a = (int *)malloc(n * sizeof(int));
    return a;
}

int main(int argc, char *argv[])
{
    int n, i;
    int *a;
    printf("Enter size of array : ");
    scanf("%d", &n);
    a = dynamicArray(n);
    printf("Base Adress of array : %d \n", a);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &(a[i]));
    }
    for (i = 0; i < n; i++)
    {
        printf("%d \t %d \n", a[i], &a[i]);
    }
    return 0;
}