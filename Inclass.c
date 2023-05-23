#include<stdio.h>
#include "sumofsquaresoffirstnnumbers.c"//write name of saved file with .c in ""
extern int k;// Used to extract value of k from another function
int main()
{
    printf("%d",k);
    return 0;
}