#include<stdio.h>

int main()
{
int days = 0, is_leap;
int m, y;
printf("Enter a month and year: ");
  scanf ("%d %d",&m,&y);
if ((m < 1 ) || (m > 12 ) || (y<1)){
    printf ("Invalid input ! \n");
    return 1 ;
}

switch (m) {
case 12 :  	days+=30;
case 11 :  	days+=31;
case 10 :  	days+=30;
case 9 :  	days+=31;
case 8 :  	days+=31;
case 7 :  	days+=30;
case 6 :  	days+=31;
case 5 :  	days+=30;
case 4 :	days+=31;
case 3 :  	days+=28;
case 2 :  	days+=31;

}

is_leap=(m>=3 && ((y%4 ==0 && y%100!=0)||y%400==0));
days = (is_leap)?(days+1):days;

printf("Number of days between 1—1—%d and 1—%d—%d = %d\n",y,m,y,days);
return 0;
}
