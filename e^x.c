
#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer n: ");
    scanf("%d",&n);
    for(int i = 1; i <= 10; i++){
        int ans = 0;
        while(i >0){
            int r = i % 10;
            i = i / 10;
            ans += r;
        }
        // if(ans > n)
        //     printf("%d ",i);
        printf("%d ",ans);
    }
    
    return 0;
}