#include <stdio.h>
void print_array(int *arr, int size)
{
    for (int k = 0; k < size; k++)
    {
        printf("%d", arr[k]);
    }
    printf(" ");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void permutation(int *arr, int start, int end)
{
    if (start == end)
    {
        print_array(arr, end);
    }
    for (int i = start; i < end; i++)
    {
        swap(arr + i, arr + start);
        permutation(arr, start + 1, end);
        swap(arr + i, arr + start);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    permutation(arr, 0, n);

    return 0;
}