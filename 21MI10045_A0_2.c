#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int temp[n];
    int c = 0;
    for(int i = 0; i < n; i+=2){
        temp[c++] = arr[i];
    }
    for(int i = 1; i < n; i+=2){
        temp[c++] = arr[i];
    }
    printf("Array after shuffle: ");
    for(int i= 0; i < n; i++){
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("Rank of elements of array: \n");
    for(int i = 0; i < n; i++){
        printf("Rank of %d : %d\n", temp[i], i);
    }

    int k = 0, num = 1;
    for(int i = 1; i < n; i++){
        if(num == n){
            break;
        }
        num *= 2;
        k++;
    }
    printf("%d",k);
    int j = 0;
    while(j < k){
        int temp1[n];
        int x = 0;
        for(int i = 0; i < n; i+=2){
            temp1[x++] = temp[i];
        }
        for(int i = 1; i < n; i+=2){
            temp1[x++] = temp[i];
        }
        printf("Array after %d shuffle: ", j+1);
        for(int i= 0; i < n; i++){
            printf("%d ", temp1[i]);
        }
        printf("\n");
        j++;
        for(int i = 0; i < n; i++)
            temp[i] = temp1[i];
    }

    return 0;
}
