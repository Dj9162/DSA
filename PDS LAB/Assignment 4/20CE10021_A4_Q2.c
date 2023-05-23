/* C program to print armstrong number betweeen a range
*/
#include<stdio.h>
void isArmstrong(int n,int m,int armnum[])   //function to check the number is armstrong or not
{
    int digit,c=0;
    for(int i=n;i<m+1;i++)
    {
         int temp=i,sum=0;
         while(temp!=0){
             digit=temp % 10;                  //seperating digits of number
             temp=temp/10;
             sum=sum+(digit * digit * digit);  //checking conditions of armstrong number
         }
         if(sum == i)
         {
            printArmstrong(i);                 //calling another function to print number
         }


    }
}
void printArmstrong(int i)                  //function to print armstrong number
{
    printf("%d",i);
}

int main()
{
    int n,m;
    int size;
    printf("Enter first natural number: ");
    scanf("%d",&n);
    printf("Enter second natural number: ");
    scanf("%d",&m);
    int armnum[100];
    isArmstrong(n,m,armnum[100]); //calling a function to check whether the number is armstrong or not
    return 0;
}
