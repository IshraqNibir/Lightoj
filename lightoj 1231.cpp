#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000007
ll coin[55]; //value of coins available
ll num[55];
ll make; //our target value
ll dp[55][25][1015];
ll n;
ll call(ll i,ll cn,ll amount)
{
    if(i>=n) { //All coins have been taken
        if(amount==make)
            return 1;
        else
            return 0;
    }

    if(dp[i][cn][amount]!=-1)
        return dp[i][cn][amount]; //no need to calculate same state twice

    ll ret1=0,ret2=0;
    if(amount+coin[i]<=make && cn<num[i])
        ret1=(call(i,cn+1,amount+coin[i]))%MOD; //try to take coin i

    ret2=(call(i+1,0,amount))%MOD; //dont take coin i

    dp[i][cn][amount]=(ret1+ret2)%MOD;
    return  dp[i][cn][amount]; //storing and returning.

}
int main()
{
    // freopen("in","r",stdin);
    ll t,ks=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>make;
        for(int i=0;i<n;i++) {
            cin>>coin[i];
        }
        for(int i=0;i<n;i++) {
            cin>>num[i];
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: ",ks++);
        ll ans=call(0,0,0)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}

