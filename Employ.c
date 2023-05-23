#include<stdio.h>
struct Employee{
    char name[20];
    int id;
    int salary;
};

void Increase( struct Employee E[],int n)
{
    for (size_t i = 0; i < n; i++)
    {
        E[i].salary = E[i].salary + 0.1 * E[i].salary;
    }
    
}
int main()
{
    int n;
    printf("Enter number of employees data you want to store: ");
    scanf("%d",&n);
    struct Employee E[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter name of %d employee: ",i+1);
        scanf("%s",E[i].name);
        printf("Enter id of %d Employee as (20CE45): ",i+1);
        scanf("%d",&E[i].id);
        printf("Enter salary of %d Employee: ",i+1 );
        scanf("%d",&E[i].salary);
        printf("\n");
    }
    Increase(E,n);
    int temp;
    printf("Enter id of Employee you want to search: ");
    scanf("%d",&temp);
    for (int i = 0; i < n; i++)
    {
        if(E[i].id == temp)
        {
            printf("Employee Details: \n");
            printf("Name : %s\n",E[i].name);
            printf("Id : %d\n",E[i].id);
            printf("Salary: %d\n",E[i].salary);
            break;
        }
        else
            printf("Invalid Input!!");
    }
    

    return 0;
}