#include<stdio.h>

int main(){
    int a,b, count = 1;
    scanf("%d", &b);
    while(1){
        scanf("%d", &a);
        if(a == -1){
            break;
        }
        else if(a < b)
            count++;
        b = a;
    }
    printf("%d", count);
    return 0;
}
