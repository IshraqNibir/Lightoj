#include <bits/stdc++.h>
using namespace std;
int pos;
int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
    pos=m;
    if (arr[m] == x)
        return m;

    if (arr[m] < x)
        l = m + 1;

    else
         r = m - 1;
  }
  return -1;
}

int main()
{
   int t,ks=1;
   scanf("%d",&t);
   while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
       int arr[n];
       for(int i=0;i<n;i++)
           scanf("%d",&arr[i]);
       int low,high;
       printf("Case %d:\n",ks++);
       for(int i=1;i<=q;i++){
           scanf("%d %d",&low,&high);
           if(low>arr[n-1]){
               printf("0\n");
               continue;
           }
           if(high<arr[0]){
               printf("0\n");
               continue;
           }
           int left,right,result;
           result=binarySearch(arr,0,n-1,low);
           left=pos;
           if(arr[left]<low)
               left++;
           result=binarySearch(arr,0,n-1,high);
           right=pos;
           if(arr[right]>high)
               right--;
           if(left==right){
               if(arr[left]>=low && arr[left]<=high)
                   printf("1\n");
               else
                   printf("0\n");
               continue;
           }
           if(right<left){
               printf("0\n");
               continue;
           }
           printf("%d\n",right-left+1);
       }
   }
   return 0;
}

