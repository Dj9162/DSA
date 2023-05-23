#include<stdio.h>
 void strFunc (char *A, int n)
   {
      char t;
      
      if (n <= 1) return;
     
      t = A[0];
      A[0] = A[n-1];
      A[n-1] = t;
     
      strFunc ( (A+1),n-1);
   }

  
int main()
{
    char s[] ="PDS";
    strFunc(s,3);
    printf("%s",s);
    return 0;
}