#include<stdio.h>
int main()
{
    int n;
    printf("enter number of student\n");
    scanf("%d",&n);
    int marks[n][n];//This is a way to define an array
    for (int i = 1; i <= n; i++) //Taking vlaues of array ftom users
    {
        for(int j = 1; j <=n; j++)
        {    
            printf("Enter number of %d %d student\n",i,j);
            scanf("%d", &marks[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)//This is to print all values of array
    {
        for(int j = 1; j <=n; j++)
            printf("%d ",marks[i][j]);
        printf("\n");
    }

    return 0;
}
