#include<stdio.h>
int n;
 int revarr(int arr[])
 {
    int temp;
     for (int i = 0; i < n/2; i++)
     {
         temp=arr[i];
         arr[i]=arr[n-1-i];
         arr[n-1-i]=temp;
     }
    
     return 0;
 }
 int printarr(int arr[])
 {
      printf("Your array is: ");
      for (int j = 0; j <n; j++)
      {
         printf("%d , ",arr[j]);
      }
      printf("\n");
     return 0;
 }
int main()
{

    printf("number of places in array: \n");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Your %d place of array\n ",i);
        scanf("%d",&arr[i]);
    }
    
    printarr(arr);
    revarr(arr);
    printarr(arr);
    // printf("Your array is: ");
    // for (int j = 1; j <= n; j++)
    // {
    //     printf("%d",arr[j]);
    // }
    // printf("\n");
    // printf("Your reverse array is: ");
    // for (int k = n; k >=1; k--)
    // {
    //     printf("%d",arr[k]);
    // }
    
   
    return 0;
}