#include <stdio.h>
#include <string.h>
union std//union is used to take less space.
{
    char b;         //its introductory code is similar to structure
    char name[14];  //It takes space using union of space of all data types i.e greater space among all data types such as int,float,char etc
    int a;
} s1;

int main()
{
    strcpy(s1.name, "Dhanraj");//It will print only one at a time and all others will not correctly be printed.
    s1.b = 'b';
    s1.a = 5;          //it will print correctly only which is defined at lowermost of all.
    printf("%d\n", s1.a);
    printf("%c\n", s1.b);
    printf("%s", s1.name);

    return 0;
}