#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   char source_file[120];
   char temp;
   FILE *source, *even, *odd;
 
   printf("Enter name of file to copy\n");
   gets(source_file);
 
   source = fopen(source_file, "r");
 
   if( source == NULL )
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   even = fopen("text.txt","w");
   odd = fopen("test.txt","w");
 
   while( fscanf(source,"%*d %*d %d",temp) == 1 )
   {
      
      if( temp % 2 == 0)
         fputc(temp,even);
      else
         fputc(temp,odd);
   }
 
   fclose(source);
   fclose(even);
   fclose(odd);
 
   return 0;
}