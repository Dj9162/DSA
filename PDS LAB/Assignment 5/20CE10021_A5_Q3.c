/* C program to check whether the number given by user is palindrome or not
*/
#include<stdio.h>
int digits(int n,int arr[10])                                 // Function to store each digits of entered number in an array and determining the size of that array
{
    int index = 0,rem;                                        // Initializing variables
    while (n != 0) {                                          // Loop to separate each digits of number and storing that in an array
        rem = n % 10;
        arr[index] = rem;
        index++;
        n = n / 10;
    }
    return index;                                             // Returning size of array
}
void IsPalindrome(int arr[],int m)                            // Function to check whether the number entered is palindrome or not and print that
{
      int temp = 1;                                           // Initializing an extra variable

    for (int i = 0; i <= m / 2 &&  m!= 0; i++) {              //condition to iterate loop till half the size of array and for positive size

        if (arr[i] != arr[m - i - 1])                         // checking digits from start and end are equal or not
        {
            temp = 0;                                         // If not equal then changing the value of extra variable
            break;
        }
    }
                                                               // Printing whether number is palindrome or not
    if (!temp)
        printf("Your Entered number is not palindrome");
    else
        printf("Your Entered number is Palindrome");
}
int main()
{
    int n,arr[10],m;                                             // Variable n is to store number entered by user, m is to store size of array, arr is to store each digit of entered number
    printf("Enter a natural number: ");
    scanf("%d",&n);
    m = digits(n,arr);                                           // Storing size of array in m as given by digits() function
    IsPalindrome(arr,m);                                         // Calling IsPalindrome() function to print whether the number is palindrome or not
    return 0;
}
