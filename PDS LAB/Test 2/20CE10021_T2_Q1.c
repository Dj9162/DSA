#include<stdio.h>
#include<string.h>

struct Sent                     // Defining a structure which store at most ten words
{
    char word1[45];
    char word2[45];
    char word3[45];
    char word4[45];
    char word5[45];
    char word6[45];
    char word7[45];
    char word8[45];
    char word9[45];
    char word10[45];
    int decision;

};

struct Sent *charArr( struct Sent *S )
{
    char str[100];
    printf("Enter: ");
    gets(str);
    int i=0, n=0;
    while ( str[i] != '\0')                     // Loop to check how many words are in the string
    {
        if( str[i] == " " || str[i] == '\n')
        {
            n++;
        }
        i++;
    }

    char store[10][20];                      // Array to store each words of string seperately
    if( n-1 <= 10)                          // If string has at most 10 words then
    {
        int i=0,j=0,m=0;
        while(1)
	{
		if(str[i]!=' '){
			store[m][j++]=str[i];
		}
		else{
			store[m][j++]='\0';
			m++;
			j=0;
		}
		if(str[i]=='\0')
		    break;
	}
    }

    S->word1[45] = store[0];             // To store each words in seperate char arr of structure
    S->word2[45] = store[1];
    S->word3[45] = store[2];
    S->word4[45] = store[3];
    S->word5[45] = store[4];
    S->word6[45] = store[5];
    S->word7[45] = store[6];
    S->word8[45] = store[7];
    S->word9[45] = store[8];
    S->word10[45] = store[9];

    return S;


};
int main()
{
    struct Sent S;
    charArr(&S);
    printf("%s",S.word1);
    return 0;
}
