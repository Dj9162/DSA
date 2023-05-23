#include<stdio.h>
struct employ                                                            // Initaializing structure to store information of employee
{
    char name[10];
    int wages;
    int days;
};
void netpay ( struct employ num[],int n)                                  // Function to print net salary of emjployee and his name
{
    float BP[n];                                                           // defining BP,TA and HRA array to store BP<TA and HRA of an employee
    float TA[n], HRA[n];
    for (int i=0;i< n ;i++ )                                               // INitializing BP of employees
    {
        BP[i] = num[i].wages;
    }
    for (int i=0;i<n ;i++ )                                               // INitializing HRA of employees as given and adding in it BP
    {
        if (BP[i] > 1000)
        {
            HRA[i] = 0.12 * BP[i] + BP[i];
        }
        else
            HRA[i] = 0.2 * BP[i] + BP[i];
    }
    for (int i=0;i<n ;i++ )                                               // INitializing TA of employees as given and adding in it both HRA and BP
    {
       if ( num[i].days >19)
       {
           TA[i] = 0.1 * BP[i] + HRA[i];
       }
       else
        TA[i] = 0 + HRA[i];
    }
    for (int i=0;i<n ;i++ )                                                  // Loop to porint net salary and name of employees
    {
        printf("Name of %d Employee is %s\n",i,num[i].name);
        printf("His net salary is %f\n",TA[i]);
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter number of Employee's data you want to store: ");                  // Asking user to input how many employees's data he wants to store
    scanf("%d",&n);
    struct employ num[n];
     for (int i=0;i< n ;i++ )                                                         // Loop to ask user about information of students
    {
        printf("Enter name of %d employee: ",i);
        scanf("%s",&num[i].name);
        printf("Enter wages/per day of %d employee: ",i);
        scanf("%d",&num[i].wages);
        printf("Enter number of Days present in company of %d employee: ",i);
        scanf("%d",&num[i].days);
    }
    netpay(num,n);                                                         // Calling net pay function

    return 0;
}
