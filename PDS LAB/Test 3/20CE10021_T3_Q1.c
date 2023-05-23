
#include<stdio.h>
#include<stdlib.h>

struct Pateint                       // Defining structure to store information of pateints
{
    char name[45];
    char gender;
    int age;
    char country[25];
    int date[3];
    int isRecovered;

};

//void countryPateints(struct Pateint P,char C[25],int n)
//{
//    char* temp[];
//    for (int i=0;i<n ;i++ )
//    {
//        if(P[i].country == C)
//        {
//            temp[i] = P[i].name;
//        }
//    }
//    int size = sizeof(temp)/sizeof(temp[0]);
//    for (int i=0;i< size;i++ )
//    {
//        for (int j=0;j<size ;j++ )
//        {
//            if(temp[i])
//        }
//    }
//
//}

int monthRecordMale(struct Pateint P[],int M,int n)  // Function to give total number of  Male pateints in given month
{
    int count = 0;

    for (int i=0;i<n ;i++ )
    {
        if( M == P[i].date[1] && P[i].gender == 'M')  //checking if given month and gender is same or not
            count++;
    }
    return count;

}
int monthRecordFemale(struct Pateint P[],int M,int n)  // Function to give total number of Female pateints in given month
{
    int count = 0;
    for (int i=0;i<n ;i++ )
    {
        if( M == P[i].date[1] && P[i].gender == 'F')   //checking if given month and gender is same or not
            count++;
    }
    return count;
}
int main()
{

    int n;
    printf("Enter total number of pateints you want to store data: "); // Asking user to enter total number of pateints
    scanf("%d",&n);
    struct Pateint P[n];                         // Creating structure array of required number of pateints
    for (int i=0;i<n ;i++ )                       // Asking details of pateints
    {
        printf("Enter your country: ");
        scanf("%s",P[i].country);
        printf("Enter the name of Pateint: ");
        scanf(" %[^\n]s",P[i].name);
        printf("Enter your age: ");
        scanf("%d",&P[i].age);
        printf("Enter your Gender('M' for Male and 'F' for Female): ");
        scanf(" %c",&P[i].gender);
        printf("Enter your date of test(ddmmyyyy): ");
        for (int j=0;j<3 ;j++ )
        {
            scanf("%d",&P[i].date[j]);
        }
        printf("Enter 0 if pateint is recovered or 1 for not recovered: ");
        scanf("%d",&P[i].isRecovered);

    }
    char *M[] = {"january","february","march","april","may","june","july","august","september","october","november","december"};  // array of months name
    char temp[15];
    printf("Enter name of month to see list of pateint admitted: ");       // Asking user to input name of month
    scanf("%s",&temp);
    int h,i;
    for (int i=0;i<12 ;i++ )    // passing arguments to function to get total number of male and female pateints
    {
        if(temp == M[i])
        {
            h = monthRecordMale(P,i+1,n);
            i = monthRecordFemale(P,i+1,n);
        }
    }
    printf("Total number of Male pateint in %s month: %d",temp,h);  // Printing total number of male pateint
    printf("Total number of Female pateint in %s month: %d",temp,i);  // Printing total number of female pateints

    int m;
    printf("Now,Again enter total number of pateint: ");  // Again asking total number of pateints
    scanf("%%d",&m);
    if(m > n)                                             // IF entered number is greater than previous then doing all work again
    {
        struct Pateint P[m];

    for (int i=n-m;i< m ;i++ )
    {
        printf("Enter your country: ");
        scanf("%s",P[i].country);
        printf("Enter the name of Pateint: ");
        scanf(" %[^\n]s",P[i].name);
        printf("Enter your age: ");
        scanf("%d",&P[i].age);
        printf("Enter your Gender('M' for Male and 'F' for Female): ");
        scanf(" %c",&P[i].gender);
        printf("Enter your date of test(ddmmyyyy): ");
        for (int j=0;j<3 ;j++ )
        {
            scanf("%d",&P[i].date[j]);
        }
        printf("Enter 0 if pateint is recovered or 1 for not recovered: ");
        scanf("%d",&P[i].isRecovered);
    }
    }
    else                                                  // If entered number is not greater than previous then do nothing
        printf("You entered less number then before");
    char *B[] = {"january","february","march","april","may","june","july","august","september","october","november","december"};  // array of months name
    char temp1[15];
    printf("Enter name of month to see list of pateint admitted: ");       // Asking user to input name of month
    scanf("%s",&temp1);
    int d,e;
    for (int i=0;i<12 ;i++ )    // passing arguments to function to get total number of male and female pateints
    {
        if(temp1 == B[i])
        {
            d = monthRecordMale(P,i+1,n);
            e = monthRecordFemale(P,i+1,n);
        }
    }
    printf("Total number of Male pateint in %s month: %d",temp1,d);  // Printing total number of male pateint
    printf("Total number of Female pateint in %s month: %d",temp1,e);  // Printing total number of female pateints

    return 0;
}
