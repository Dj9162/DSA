#include<stdio.h>
#include<stdlib.h>

int* Merge(int size1,int size2, int *ptr1, int* ptr2)          // Function to merge both sorted array
{
    int n = size1 + size2,c =0;
    ptr1 = (int*) realloc( ptr1, n*sizeof(int));               // Initializing first array with greater size and storing both array in this
    for(int i = 0; i < size2 ; i++)
    {
            ptr1[i +size1] = ptr2[i];
    }
    while (c <= n)                                            // Sorting the new array
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (ptr1[j] > ptr1[j + 1])                       // Checking if next element is smaller or not
            {
                int temp = ptr1[j];                          // If smaller then swap them
                ptr1[j] = ptr1[j + 1];
                ptr1[j + 1] = temp;
            }
        }
        c++;
    }
    return ptr1;                                            // returning new array

}
int main()
{
    int *ptr1,*ptr2,size1,size2;                                      // Variable to store arrays and size of array
    printf("Enter the size of first array: ");
    scanf("%d",&size1);
    ptr1 = (int*)malloc(size1 * sizeof(int));                         // Initializing first array dynamically
    printf("Enter the size of second array: ");
    scanf("%d",&size2);
    ptr2 = (int*) malloc (size2 * sizeof(int));                        // Initializing second array dynamically
    printf(" Enter elements of first array by giving space: ");
    for(int i =0 ; i < size1; i++)                                     // Storing array's elements
        scanf("%d", &ptr1[i]);
    printf("Enter elements of second array by giving space: ");
    for(int i =0 ; i< size2 ; i++)
        scanf("%d",&ptr2[i]);
    int *new_arr = Merge(size1,size2,ptr1,ptr2);                       // Storing returned array from function in new pointer array
    printf("Required whole sorted array of both inputed array is:\n")
    for(int i=0; i < (size1+size2); i++)                                // Printing whole sorted array
        printf("%d ", new_arr[i]);

    return 0;
}
