#include <stdio.h>
int main()
{
    FILE *ptr = NULL;
    // char string[94];
    char string[74] = "\nHello how are you ?";
    //Reading a file
    // ptr = fopen("myfile.txt", "r");
    // fscanf(ptr, "%s", string);
    // printf("the content is %s\n", string);
    // Writing a file
    ptr = fopen("myfile.txt", "a");
    fprintf(ptr, "%s", string);
    return 0;
}