#include<stdio.h>
 struct S
 {
     char w[45];
     char wo[45];
     char wor[45];
     char word[]

 };

 void *SortSent(struct S *sentence, int n)                                 // function to sort sentence in ascending order
 {
     int c =0;
     while (c <= n)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if ( (sentence + j)->word[0] > (sentence + j +1)->word[0])
            {
                char temp[45] = (sentence + j)->word;
                (sentence + j)->word = (sentence + j + 1)->word;
                (sentence +j+1)->word = temp;
            }
        }
        c++;
    }

 }

 void *sortStruct(struct S *sentence, int n)                       // function to sort sentence in desecending order
 {
     int c =0;
     while (c <= n)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if ( (sentence + j)->word[0] < (sentence + j +1)->word[0])
            {
                char temp[45] = (sentence + j)->word;
                (sentence + j)->word = (sentence + j + 1)->word;
                (sentence +j+1)->word = temp;
            }
        }
        c++;
    }

 }

int main()
{
    struct S *sentence;                                                       // defining structure pointer to store sentence
    int n;
    printf("Enter number of words in your sentence of at most 5 words:\n");     // Asking user about no. of words
    scanf("%d",&n);
    printf("Enter a sentence of five words: ");
    if( n >5)
        printf("Invalid Input!!");
    else                                                      // If words less than 5 then
    {
        sentence = (struct S*)malloc(n * sizeof(struct S));
        for (int i = 0; i < n; ++i)
            scanf("%s", (sentence + i)->word);
    }

    return 0;
}
