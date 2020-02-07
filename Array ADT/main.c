#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int *A;
    int size;
    int length;
} Array;

//############## ADT ###############
void Display(Array arr)
{
    int i;
    printf("Elements Are -\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d \t", arr.A[i]);
    }
    printf("\n");
}

void Append(Array *arr, int x)
{
    if (arr->length == arr->size)
        return;
    arr->A[arr->length] = x;
    arr->length++;
}

void Insert(Array *arr, int index, int x)
{
    int i;
    if (index < 0 || index > arr->size || arr->length == arr->size)
        return;

    for (i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
}

void Delete(Array *arr, int index)
{
    int x, i;
    if (index < 0 || index > arr->length)
        return;
    x = arr->A[index];
    for (int i = index; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length] = 0;
    arr->length--;
    printf("Element Deleted = %d \n", x);
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(Array arr, int x)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (x == arr.A[i])
        {
            // Swap(&arr.A[i], &arr.A[i - 1]); //Transposition
            Swap(&arr.A[i], &arr.A[0]); //Move to Front/Head
            return i;
        }
    }
    return -1;
}

int BinarySearch(Array arr, int key)
{
    int l = 0, h = (arr.length - 1), mid;
    mid = (l + h) / 2;
    while (l <= h)
    {
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
        {
            h = mid - 1;
            mid = (l + h) / 2;
        }
        else
        {
            l = mid + 1;
            mid = (l + h) / 2;
        }
    }
    return -1;
}

//########### Sorting ###########

// 1. Bubble Sort

void BubbleSort(Array *arr)
{
    int i, j, flag, temp;
    for (i = 0; i < arr->length - 1; i++)
    {
        flag = 0;
        for (j = 0; j < arr->length - 1 - i; j++)
        {
            if (arr->A[j] > arr->A[j + 1])
            {
                temp = arr->A[j];
                arr->A[j] = arr->A[j + 1];
                arr->A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

// 2. Insertion Sort

void InsertionSort(Array *arr)
{
}

int main(int argc, char const *argv[])
{
    int size, n, i, searchFlag;
    Array arr;
    printf("Enter Size Of Array : ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter Number Of Numbers : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
        arr.length++;
    }
    Display(arr);
    // Append(&arr, 5);
    // Insert(&arr, 2, 50);
    // Delete(&arr, 0);
    // searchFlag = BinarySearch(arr, 4);
    // if (searchFlag != -1)
    // {
    //     printf("Element Found at Index : %d\n", searchFlag);
    // }
    // else
    // {
    //     printf("Element Not Found");
    // }
    BubbleSort(&arr);
    Display(arr);
    return 0;
}