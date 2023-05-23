#include<stdio.h>
#include<string.h>
#define N 20
struct student
{
    char roll_num[N];
    char name[N];
    char facad_code[N];
};
struct faculty
{
    char emp_code[N],name[N];
};
struct student std[10];
struct faculty fac[10];
int nfac,nstd;
void find_facad(char *s)
{
   for (int i=0;i<nstd;i++)
   {
       if(strcmp(std[i].roll_num, s)==0){
         for(int j=0;j<nfac;j++)
       {
           if(strcmp(std[i].facad_code, fac[j].emp_code)==0)
            printf("%s\n",fac[j].name);
       }
       }
   }
}
void find_std(char *s)
{
    for(int i=0;i<nfac;i++)
    {
        if (strcmp(fac[i].name,s)==0){
            for(int j=0;j<nstd;j++)
        {
            if(strcmp(fac[i].emp_code,std[j].facad_code)==0){
                printf("Roll no = %s\n",std[i].roll_num);
                printf("Name of student  = %s\n",std[i].name);}
        }
        }
    }
}
int main()
{

    printf("Enter number of students ");
    scanf("%d",&nstd);
    printf("Enter number of facads ");
    scanf("%d",&nfac);

    for(int i=0;i<nstd;i++)
    {
        printf("Roll number of student ");
        scanf("%s",std[i].roll_num);
        printf("Name of student ");
        scanf("%s",std[i].name);
        printf("Facad code of student ");
        scanf("%s",std[i].facad_code);

    }
    for(int i=0;i<nfac;i++)
    {
        printf("Employee code");
        scanf("%s",fac[i].emp_code);
        printf("Name of faculty ");
        scanf("%s",fac[i].name);

    }
    char *s;
    char p[10];
    printf("Enter roll num of student to find his/her facad\n");
    scanf("%s",s);
    find_facad(s);

    printf("Enter name of the faculty member \n");
    scanf("%s",&p);
    find_std(p);
    return 0;

}
