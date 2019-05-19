#include <bits/stdc++.h>
using namespace std;
#define size 100000000
double ara[1000000];
void har()
{
    double prvs=1.0;
    int cnt=1;
    for(int i=2;i<=size;i++) {
        ara[cnt]=prvs+(1.0/i);
        prvs=prvs+(1.0/i);
        if(i%1000==0)
            cnt++;
    }
}
int main()
{
    har();
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int div=n/1000;
        double ans=ara[div];
        int rem=n%1000;
        int mul=(div*1000)+1;
        for(int i=mul;i<mul+rem;i++)
        {
             ans=ans+(1.0/i);
        }
        printf("Case %d: %0.10lf\n",ks++,ans);
    }
    return 0;
}
