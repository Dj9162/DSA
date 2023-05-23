#include<stdio.h>
int main(){
    int i, j, N, count = 0;
    scanf("%d", &N);
    printf("%d\n", N);
    N += 10;
    for(i = 0; i < N; i++)
        for(j = i; j >= 0; j--)
            count++;
    printf("%d\n", count);
    return 0;
}
