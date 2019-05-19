#include<bits/stdc++.h>
using namespace std;
long long bigmod(long long a,long long p,long long m);
long long firstkdigits(long long n,long long k)
{

   long double product = k * log10(n);
   long double decimal_part = product - floor(product);
   decimal_part = pow(10, decimal_part);
   decimal_part = decimal_part * (100);
   long long y = decimal_part;
   return y;
}
int main()
{
      int t,ks=1;
      cin>>t;
      while(t--) {
          long long n,k;
          cin>>n>>k;
          long long last = bigmod(n, k, 1000);
          long long first = firstkdigits(n, k);
          printf("Case %d: ",ks++);
          int cnt=1;
          vector<int>v;
          while(cnt<=3) {
              v.push_back(last%10);
              last=last/10;
              cnt++;
          }
          cout<<first<<" ";
          for(int i=2;i>=0;i--)
              cout<<v[i];
          cout<<endl;
      }

      return 0;
}

long long bigmod(long long a,long long p,long long m)
{
      if(p==0)
      return 1;

      if(p%2==0){
      long  long c=bigmod(a,p/2,m);
      return c*c%m;
      }
      else
      return (a*bigmod(a,p-1,m)) %m;

}

