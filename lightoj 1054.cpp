#include <bits/stdc++.h>
using namespace std;
long long bigmod(long a,long long p,long long m)
{
      if(p==0)
      return 1;

      if(p%2==0){
      long long c=bigmod(a,p/2,m);
      return c*c%m;
      }
      else
      return (a*bigmod(a,p-1,m)) %m;

}
long long modInverse(long long a, long long m)
{
        return bigmod(a,m-2,m);
}

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
long long func(long long r,long long n)
{
    long long a1=modInverse(r-1,1000000007);
    long long a2=bigmod(r,n+1,1000000007);
    a2=a2-1;
    long long a3=(a2*a1)%1000000007;
    return a3;
}
long long sum;
void primeFactors(long long n,long long m) {
    // Print the number of 2s that divide n
    long long cnt=0;
    while (n%2 == 0) {
        //printf("%d ", 2);
        n = n/2;
        cnt++;
    }
    if(cnt>0)
        sum=(sum*func(2,cnt*m))%1000000007;
    long long i;
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for ( i = 3; i <= sqrt(n); i = i+2) {
        // While i divides n, print i and divide n
        cnt=0;
        while (n%i == 0) {
            //printf("%d ", i);
            n = n/i;
            cnt++;
        }
        if(cnt>0)
            sum=(sum*func(i,cnt*m))%1000000007;
    }
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {
       // printf ("%d ", n);
        sum=(sum*func(n,m))%1000000007;
    }
    //printf ("\n");
}
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        sum=1;
        long long n,m;
        cin>>n>>m;
        if(n==1000000007)
            printf("Case %d: 1\n",ks++,sum);
        else{
            primeFactors(n,m);
            printf("Case %d: %lld\n",ks++,sum);
        }
    }
    return 0;
}
