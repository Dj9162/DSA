#include<stdio.h>

void make_palindrome(char s[]){
    //printf("%d", 1);
    static int i = 0;
    int temp;
    if(s[i] == '\0')    return;

    temp = s[i];i++;
    make_palindrome(s);
    s[i] = temp;
    i++;
    s[i] = '\0';
    printf("%d ", i);
}

int main(){

    char a[100];
    scanf("%s", a);
    make_palindrome(a);
    printf("%s\n", a);
}
