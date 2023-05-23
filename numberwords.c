#include<stdio.h>
#include<string.h>
char words(char *num)
{
    int k=strlen(num);
    char *one_word[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    // char *two_word[]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
    // char *one_power[]={"ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety","twenty"};
    // char *two_power[]={"hundred","thousand"};
    if (k==1)
    {
        printf("%s\n",one_word[*num -'0']);
    } 
    
}
int main()
{
    char n[5];
    printf("Enter a number: ");
    scanf("%s",&n);
    words(n);
    return 0;
}