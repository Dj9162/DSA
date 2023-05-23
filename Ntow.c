#include<stdio.h>
int main()
{
    char n;
    int m,rate=0;
    printf("Enter b for bus,t for truck,c for car,m for motor cycle,s for scooter \n");
    printf("Enter Your vehicle character: ");
    scanf("%c",&n);
    printf("Enter distance cover in km: ");
    scanf("%d",&m);
    if ( n=='t' || n=='b')
    {
        for (int i = 1; i <=m; i++)
    {
        if (i<=3)
        {
            rate+=20;
        }
        else
        {
            rate+=30;
        }
        
    }
     printf("Your total rate of distance cover is %d",rate);    
    }
   
    else if (n=='c')
    {
        for (int i = 1; i <=m; i++)
    {
        if (i<=3)
        {
            rate+=10;
        }
        else
        {
            rate+=20;
        }
        
    }   
     printf("Your total rate of distance cover is %d",rate);
    }
    
    else if (n=='m' || n=='s')
    {
        for (int i = 1; i <=m; i++)
    {
        if (i<=3)
        {
            rate+=5;
        }
        else
        {
            rate+=10;
        }
        
    }  
     printf("Your total rate of distance cover is %d",rate); 
    }
    else
    {
        printf("Wrong Input!!");
    }
    
    
    
   
    return 0;
}