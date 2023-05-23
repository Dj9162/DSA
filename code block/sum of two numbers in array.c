/* //Method:1   Using sorting Time Complexity depends upon which sorting you used
 * #include<stdio.h>
 * void sort(int arr[],int n)// Bubble sorting  Time complexity: nlogn
 * {
 *     int c=0;
 *     while(c<=n)
 *     {
 *         for (int i=0;i<n-1 ;i++ )
 *         {
 *             if (arr[i]>arr[i+1])
 *             {
 *                 int temp=arr[i];
 *                 arr[i]=arr[i+1];
 *                 arr[i+1]=temp;
 *             }
 *         }
 *         c++;
 *     }
 * }
 * int func(int arr[],int n,int sum)
 * {
 *     sort(arr,n);//To sort the array
 *     int r=0,l=n-1;
 *     while (r<=l)
 *     {
 *         if (arr[r] + arr[l]==sum)//Taking one element from start and other from end
 *         {
 *             return 1;
 *         }
 *         else if (arr[r] + arr[l]< sum)
 *         {
 *             r++;
 *         }
 *         else
 *             l--;
 *     }
 *     return 0;
 * }
 * int main()
 * {
 *     int n,x=6;
 *     int arr[]={1,0,5,6,10,4};
 *     n=sizeof(arr)/sizeof(arr[0]);
 *     if(func(arr,n,x))
 *         printf("Sum is found!");
 *     else
 *         printf("Sum is not found!");
 *     return 0;
 * }
 */

 //*****************************************************************************************************************************


 #include<stdio.h>
 int main()
 {
     int n;
     int arr[]={1,5,0,6,10,3};
     return 0;
 }
