#include<stdio.h>
#include <string.h>
struct item
{
    char name[20], unit[10];
    float price;
};

char* cap( char str[])
{
    for (int i = 0; i < strlen(str) ; i++)
    {
        if (str[i] >= 'a' && str[i]<= 'z')
        {
            str[i] -=32;
        }
    }
    return str;
}

void* search_item( struct item list[], char str[], int* x)
{
    
    printf("Items found matching with your keywords:\n");
    for (int i = 0; i < 12; i++)
    {
        char* temp;
        temp = strstr(list[i].name,str);
        if ( temp != NULL)
        {
            printf("%d: %s             --- Rs. %.2f per %s\n",i+1,list[i].name,list[i].price,list[i].unit);
            *x = 1;
        }
        
    }

    
}

void price( struct item list[], int n, int m)
{
    float net_price = 0;
    for (int i = 0; i < m; i++)
    {
        net_price += list[n-1].price;
    }
    printf("To pay (including GST) = %.2f",net_price+net_price * 0.1);
    
}

void Not_found( int x)
{
    if( x == 0)
        printf("Sorry, No such item found!!");
}

int main()
{
    int x =0;
    struct item list[12] = {
        {"BUTTER COOKIES", "PACK", 25},
        {"CASHEW COOKIES", "PACK", 30},
        {"CREAM CAKE", "SLICE", 22},
        {"LEMON JUICE", "LITRE", 35},
        {"VEG CASHEW CAKE", "SLICE", 18},
        {"MANGO JUICE", "LITRE", 78},
        {"COOKIES (PLAIN)", "PACK", 15},
        {"ORANGE JUICE", "LITRE", 72},
        {"MILK BISCUITS", "PACK", 12},
        {"PLAIN VEG CAKE", "SLICE", 20},
        {"BUTTER FRUIT CAKE", "SLICE", 25},
        {"PINEAPPLE JUICE", "LITRE", 65}
    };
    
    char key[20];
    printf("Enter a keyword: ");
    gets(key);
    cap(key);
    search_item( list, key,&x);
    if( x == 0)
        goto end;
    int n,m;
    printf("Enter your choice: ");
    scanf("%d",&n);
    printf("Enter the quantity: ");
    scanf("%d",&m);
    price( list,n,m);
    end:
    Not_found(x);
    return 0;
}