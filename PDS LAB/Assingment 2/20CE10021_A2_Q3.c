/* C program to check whether the input alphabet is vowel or not using switch case
*/
#include<stdio.h>
int main()
{
    char alp;                                                                     // To store inputed alphabet
    printf("Enter an Alphabet capital or small as you wish: ");                   // Asking user to input an alphabet
    scanf("%c",&alp);
    switch (alp)                                                                  // Used to check alphabet inputed by user
    {
        case 'A':                                                                 //case function is used to check whether the inputted alphabet is equal to alphabet inside case or not
            printf(" A is vowel");
            break;                                                                // After each case function break should be used otherwise it will enter next case statement
        case 'E':
            printf(" E is vowel");
            break;
        case 'I':
            printf(" I is vowel");
            break;
        case 'O':
            printf(" O is vowel");
            break;
        case 'U':
            printf(" U is vowel");
            break;
        case 'a':
            printf(" a is vowel");
            break;
        case 'e':
            printf(" e is vowel");
            break;
        case 'i':
            printf(" i is vowel");
            break;
        case 'o':
            printf(" o is vowel");
            break;
        case 'u':
            printf(" u is vowel");
            break;
        default:                                                                   // Here default is used if entered alphabet is not vowel
            printf("%c is not a vowel",alp);                                       // To print not vowel
    }
    return 0;
}
