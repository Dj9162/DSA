#include<iostream>
using namespace std;
//All thing is similar as c language.
int main()
{
    int a,b;
    cout<<"Enter a number: \n";//Instead of printf which is used in c here we use cout.
    cin>>a;                    //Insteas of scanf which is used in c here we use cin.
    cout<<"Enter another number: \n";
    cin>>b;
    cout<<"Your required sum is: \n"<<a+b;

    return 0;
}