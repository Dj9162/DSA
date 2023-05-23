/* C program to store information of students*/
#include<stdio.h>
struct students                                                            // Defining structure to store information of students
{
    char names[10];
    char roll[10];
    float cg;
};

void printStudent( struct students num[],int n,int m)                          // Function to print information of students
{

    printf("Name of student with Highest cgpa is %s\n",num[n].names);
    printf("Roll number of that student is %s\n",num[n].roll);
    printf("CGPA of that student is %f\n",num[n].cg);
    printf("\n");
    printf("Name of student with Lowest cgpa is %s\n",num[m].names);
    printf("Roll number of that student is %s\n",num[m].roll);
    printf("CGPA of that student is %f\n",num[m].cg);

}
int main()
{
    int n;                                                                           // Variable to store how many student's data user want to store
    printf("Enter number of students whose data you want to store: ");
    scanf("%d",&n);
    struct students num[n];                                                          // Defining structure of array of name num
    for (int i=0;i< n ;i++ )                                                         // Loop to ask user about information of students
    {
        printf("Enter name of %d student: ",i);
        scanf("%s",&num[i].names);
        printf("Enter roll number of %d student: ",i);
        scanf("%s",&num[i].roll);
        printf("Enter CGPA of %d student: ",i);
        scanf("%f",&num[i].cg);
    }
    int H_cg =0, L_cg = 0,H_index=0,L_index=0;
    for (int i=1;i< n ;i++ )                                                        // Loop to find index of highest cgpa
    {
        if ( H_cg < num[i].cg)                                                      // Checking if first element of highest or not
        {
            H_cg = num[i].cg;                                                       // changing highest data of cgpa as obtain
            H_index = i;                                                            // Obtaining index of highest cgpa
        }

    }
    for (int i= 0;i <n ;i++ )                                                      // Loop to find index of lowest cgpa
    {
        if (num[i].cg < L_cg)
        {
            L_cg = num[i].cg;
            L_index = i;
        }
    }
    printStudent( num,H_index,L_index);                                           // Printing information of students of highest cgpa and lowest cgpa

    return 0;
}
