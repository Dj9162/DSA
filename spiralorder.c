// 123
// 894
// 765
#include <stdio.h>
int main()
{
    
    int n;
    // printf("Enter total column and row: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("Enter %d%d place of array: ",i,j);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    int row_start=0,row_end=n-1,column_start=0,column_end=n-1;
    while (row_start<=row_end)
    {
        //for first line:123
        for (int col=column_start; col <= column_end; col++)
        {
            printf("%d",arr[row_start][col]);
        }
        row_start++;
        //for last column:45
        for (int row=row_start; row <=row_end ; row++)
        {
            printf("%d",arr[row][column_end]);
        }
        column_end--;
        //for last row:67
        for (int col = column_end; col >= column_start ; col--)
        {
            printf("%d",arr[row_end][col]);
        }
        row_end--;
        //for first column:8
        for (int row = row_end; row >=row_start; row--)
        {
            printf("%d",arr[row][column_start]);
        }
        column_start++;
        
    }
    
    return 0;
}