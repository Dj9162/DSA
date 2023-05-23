#include<stdio.h>
int main()
{
    printf("File name is %s\n",__FILE__);
    printf("Today's date is %s\n",__DATE__);
    printf("Line number is %d\n",__LINE__);
    printf("ANSI: %d\n",__STDC__);
    printf("Time: %s",__TIME__);
    return 0;
}