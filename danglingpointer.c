#include<stdio.h>
#include<stdlib.h>
int* functionDangling()
{
    int a, b, sum;
    a=34;
    b=345;
    sum =a+b;
    return &sum;
}
int main()
{
    //case 1: De allocation of a memory block
    int *ptr=(int*) malloc(7* sizeof(int));
    ptr[0]= 34;
    ptr[1]= 44;
    ptr[2]= 54;
    ptr[3]= 64;
    free(ptr);// ptr is now a dangling pointer

    // case 2: Function returning local variable address
    int * dangPtr = functionDangling();// ptr is now dangling pointer

    // Case 3: If a variable goes out of scope
    int * danglingPtr3;
    {
        int a=12;
        danglingPtr3 = &a;
    }
    //Here variable a goes out of scope which danglingPtr3 is pointing to a 
    //location which is freed and hence danglingPtr3 is now a dangling pointer
    return 0;
}
// To avoid dangling pointer which takes extra space or useless space you can use NULL pointer
// int *ptr=NULL//This is method to use null pointer 

//  Wild pointer : Unintialized pointer are known as wild pointers
// int a=334;
// int *ptr; //This is a wild pointer 
// *ptr = 34;// This not not a good thing to do
// ptr = &a;// ptr is no longer a wild pointer
// printf("The value of a is %d\n", *ptr);