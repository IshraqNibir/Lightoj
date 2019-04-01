#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ft=sqrt(n);
        ll sc=n/2;
        sc=sqrt(sc);
        ll ans=n-(ft+sc);
        printf("Case %d: %lld\n",ks++,ans);
    }
    return 0;
}
