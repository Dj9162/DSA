#include <stdio.h>
#include <string.h>
int main()
{
    char name1[45];
    char name2[45];
    printf("Enter first name: ");
    gets(name1);
    printf("Enter second name: ");
    gets(name2);
    printf("You are both friends %s ", strcat(name1, name2));
    return 0;
}