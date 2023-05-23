/* C program to check whether the number is fascinating or not
*/
#include<stdio.h>
int fasnum(int n)
{
    int x,y,m,i=0;
    int arr[20];
    x = n * 2;
    y = n * 3;
    while (n != 0)                           //Taking all digits of number
    {
        m = n % 10;
        arr[i] = m;
        i++;
        n = n / 10;
    }
     while (x != 0)                          //Taking all digits of number
    {
        m = x % 10;
        arr[i] = m;
        i++;
        x = x / 10;
    }
     while (y != 0)                          //Taking all digits of number
    {
        m = y % 10;
        arr[i] = m;
        i++;
        y = y / 10;
    }

    int c=0;
    while (c <= i)                          //sorting the array in ascending order
    {
        for (int j = 0; j < i -1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        c++;
    }

    for (int k=0;k<i ;k++ )               //Checking whether the number is fascinating or not
    {
        if (arr[k] != k+1)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    printf("Enter an Integral number: ");
    scanf("%d",&n);
    while (n<100)                           //To check whether the number is  three digit number or not
    {
    printf("Enter an Integral number: ");
    scanf("%d",&n);
    }
    if(fasnum(n)== 0)                       //Checking the is fascinating or not
        printf("Not Fascinating number");
    else
        printf("Fascinating Number");

    return 0;
}
