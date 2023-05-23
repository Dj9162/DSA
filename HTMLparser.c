#include <stdio.h>
#include <string.h>
void html(char *string)
{
    int n;
    int m = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            n = 1;
            continue;
        }
        if (string[i] == '>')
        {
            n = 0;
            continue;
        }
        if (n == 0)
        {
            string[m] = string[i];
            m++;
        }
    }
    string[m] = '\0';

    while (string[0] == ' ')
    {
        for (int i = 0; i < strlen(string); i++)
        {
            string[i] = string[i + 1];
        }
    }
    while (string[strlen(string) - 1] == ' ')
    {
        string[strlen(string) - 1] = '\0';
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char string[50];
    printf("Write your html syntax\n");
    gets(string);
    html(string);
    printf("~~%s~~", string);
    return 0;
}