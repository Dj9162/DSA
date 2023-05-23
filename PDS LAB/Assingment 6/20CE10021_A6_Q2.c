#include<stdio.h>
#include<math.h>
float* readPOLY( int n,int m,float arr1[],float arr2[])                          // Function to read polynomial
{
    for (int i=0;i<=n ;i++ )                                                     // Loop to read polynomial POLYA
    {
        printf("Enter coefficient of %dth power of x in POLYA: ",i);
        scanf("%f",&arr1[i]);
    }

     for (int i=0;i<=m ;i++ )                                                    // Loop to read polynomial POLYB
    {
        printf("Enter coefficient of %dth power of x in POLYB: ",i);
        scanf("%f",&arr2[i]);
    }
    return (arr1,arr2);
}
float *addPOLY( float arr1[], float arr2[],int n,int m)                          // Function to add polynomial
{
    int s;
    if (n>m)
    {
        s=m;
        float *sum[n];
        for (int i=0;i<=n ;i++ )
        {
            sum[i] = arr1[i];
        }
    }
    else
    {
        s=n;
        float *sum[m];
        for (int i=0;i<=m ;i++ )
        {
            sum[i] = arr2[i];
        }
    }
    for (int i=0;i<=s ;i++ )
    {
        sum[i] = arr1[i] + arr2[i];
    }
    return (sum,s);
}
void printPOLY(int arr[],int size)                               // Function to print polynomial
{

    float x;
    for (int i=size;i>=0 ;i-- )
    {
        if (i>0)
        {
            printf("%.3f x^%d + ",arr[i],i);
        }
        else
            printf("%.3f");
    }

}
float *multPOLY(int arr1[], int arr2[], int n, int m)        // Function to multiply polynomial
{
   int *mul[n+m-1] ={0};                                     // defining new array which store multiplied value of array
   if( n> m)
   {
   for (int i=0; i<n; i++)
   {

     for (int j=0; j<m; j++)
         mul[i+j] += arr1[i]*arr2[j];
   }
   }
   else
   {
       for (int i=0; i<m; i++)
   {

     for (int j=0; j<n; j++)
         mul[i+j] += arr2[i]*arr1[j];
   }
   }

   return mul;
}
int main()
{
    int n,m;
    printf("Enter degree of polynomial up-to 10 you want to store in POLYA: ");          // Asking user to input degree of POLYA
    scanf("%d",&n);
    printf("Enter degree of polynomial up-to 10 you want to store in POLYB: ");          // Asking user to input degree of POLYB
    scanf("%d",&m);
    float arr1[n],arr2[n];
    if (n < 11 && m< 11)                                                            // Checking inputed degree is less than 11 or not
    {
        addPOLY(arr1,arr2,n,m);                                                      // Calling all the functions
        multPOLY(arr1,arr2,n.m);
        printPOLY(sum,s);
        printPOLY(mul,n+m-1);
        printPOLY(arr1,n);

    }
    else
        printf("INVSLID DEGREE!!!");

    return 0;
}
