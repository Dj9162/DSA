#include <stdio.h>
#include <string.h>
// structure should be made outside int main function
// typedef is used to change name of structure
// typedef <previous name> <alias_name>;
typedef int i;// In this int is changed to i

// typedef struct student
struct student
{
    char name[14];
    // int Roll;
    i Roll;//We can use both i or int 
    int class;
    char section;
    float percentage;
// } baccho;Here struct student is changed to baccho
} s1, s2, s3;

int main()
{
    int x;
    // another way to introduce stucture
    // struct student s1,s2,s3;
    // baccho s1,s2,s3;
    s1.Roll = 1;
    s2.Roll = 2;
    s3.Roll = 3;
    s1.class = 8;
    s2.class = 8;
    s3.class = 8;
    s1.section = 'A';
    s2.section = 'B';
    s3.section = 'C';
    s1.percentage = 91.75;
    s2.percentage = 85.59;
    s3.percentage = 94.36;
    strcpy(s1.name, "Ash");
    strcpy(s2.name, "Brock");
    strcpy(s3.name, "Misty");
    printf("Hello!!\n");
    printf("Enter roll no: ");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Name: %s\n", s1.name);
        printf("Roll Number: %d\n", s1.Roll);
        printf("Class: %d\n", s1.class);
        printf("section: %c\n", s1.section);
        printf("Exam percentage: %f\n", s1.percentage);
    }
    else if (x == 2)
    {
        printf("Name: %s\n", s2.name);
        printf("Roll Number: %d\n", s2.Roll);
        printf("Class: %d\n", s2.class);
        printf("section: %c\n", s2.section);
        printf("Exam percentage: %f\n", s2.percentage);
    }
    else if (x == 3)
    {
        printf("Name: %s\n", s3.name);
        printf("Roll Number: %d\n", s3.Roll);
        printf("Class: %d\n", s3.class);
        printf("section: %c\n", s3.section);
        printf("Exam percentage: %f\n", s3.percentage);
    }
    printf("Good Bye");

    return 0;
}