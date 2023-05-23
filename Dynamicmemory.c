#include <stdio.h>
#include <stdlib.h> // This is used to use dynamic memory function
// Dynamic memory allocation is a way in which the size of a data structure can be changed during the runtime.
int main()
{
    int *ptr;
    // ptr = (int *)malloc(3 * sizeof(int)); // use sizeof function because in different system there are different size of data types.
    ptr = (int *)calloc(3, sizeof(int));//malloc and calloc is used to book size of your pointer array
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("The vlaue at %d of this array is %d\n", i, ptr[i]);
    }

    ptr = (int *)realloc(ptr, 4 * sizeof(int));//This is used to change your booked space of array 
    for (int i = 0; i < 4; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("The vlaue at %d of this array is %d\n", i, ptr[i]);
    }
    free(ptr);//Used to free all the spaces taken by pointer array during your programme

    return 0;
}