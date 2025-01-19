/*Write a C program to hold two integer pointers as structure members. Allocate space
for the structure and its data members during runtime. Get one array as input. In the
second array copy the elements of the first array and replace the odd positioned
elements by the product of its adjacent elements. Access the array elements and
structures using pointers instead of subscript notation.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr1;
    int *arr2;
} array;

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    array *ptrarray = (array *)malloc(sizeof(array));
    ptrarray->arr1 = (int *)malloc(n * sizeof(int));
    ptrarray->arr2 = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element : \n",i+1);
        scanf("%d", ptrarray->arr1 + i);
    }

    for (int i = 0; i < n; i++)
    {
        *(ptrarray->arr2 + i) = *(ptrarray->arr1 + i);
    }

    for (int i = 1; i < n - 1; i += 2)
    {
        (ptrarray->arr2 + i) = ((ptrarray->arr1 + i - 1)) * (*(ptrarray->arr1 + i + 1));
    }

    printf("Modified second array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptrarray->arr2 + i));
    }
    printf("\n");

    free(ptrarray->arr1);
    free(ptrarray->arr2);
    free(ptrarray);
    
    return 0;
}
