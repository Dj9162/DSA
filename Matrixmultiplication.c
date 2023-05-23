#include<stdio.h>
int main()
{
    int n;
    printf("Enter no. of rows of square matrix: ");
    scanf("%d",&n);
    int arr1[n][n],arr2[n][n];
    printf("Enter elements of first matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr1[i][j]);
        }
        
    }
    printf("Enter elements of second matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr2[i][j]);
        }
        
    }
    int arr3[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum =0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = sum;
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}