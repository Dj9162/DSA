#include <stdio.h>
// character array occupy one extra space as null character
// below function is for printing character array one by one manually
void printname(char name[])
{
    int i = 0;
    printf("Your name is ");
    while (name[i] != '\0')
    {
        printf("%c", name[i]);
        i++;
    }
    printf("\n");
}
    int main()
    {
        // char name[] = {'D', 'H', 'A', 'N', 'R', 'A', 'J', '\0'}; 
        // one null character is used in last to terminate the strings.
        // char name[]="Dhanraj"
        // in this method null character is not written but it is written default.
        char names[45];
        // gets predefined function is used to take character array i.e, name from users
        gets(names);
        // printf("Using printname function %s\n", names);
        // printname(names);
        // printf("Your name is %s\n", names);
        printf("Your name is:");
        // puts functions is used to print character array 
        puts(names);
        return 0;
    } 
// #include<stdio.h>
// int main()
// {
//     char *str[]={"shfj","sfjkk","yee","owue","vcn"};
//     printf("%s",str['4' - '1']);
//     return 0;
// }