#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt=0;
ll precal(ll i,ll j,ll k)
{
     if(k>i)
        return 0;
     if(k==1)
        return (i*j);
    cnt = (j*precal(i-1,j-1,k-1)) + precal(i-1,j,k);
    return cnt;
}
int main()
{
    ll t,ks=1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ans=1;
        if(k!=0)
            ans=precal(n,n,k);
        printf("Case %lld: %lld\n",ks++,ans);
    }
    return 0;
}
