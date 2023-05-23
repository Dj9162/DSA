#include<stdio.h>
#include<string.h>
int main()
{
    int n=0;
    // scanf("%d",&n);
    char string[45];
    gets(string);
    // scanf("%s",&string);
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i]!=string[strlen(string)-i-1])
        {
            n=1;
            break;
        }    
    }
    if (n)
        printf("not palindrome");
    else
    {
        printf("palindrome");
    }
    
    
    return 0;
}