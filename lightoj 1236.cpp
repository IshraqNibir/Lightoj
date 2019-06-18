#include <bits/stdc++.h>
using namespace std;
#define sz 10000005
#define pb push_back
#define ll long long
bool ara[sz];
vector<int>v;
int ans=1,cnt,tmp;
void sieve()
{
    int i,j,root;
    for(i=2;i<=sz;i++){
        ara[i]=1;
    }
    root=sqrt(sz);
    for(i=2;i<=root;i++){
        if(ara[i]==1){
            for(j=2;i*j<=sz;j++){
                ara[i*j]=0;
            }
        }
    }
    for(int i=2;i<sz;i++) {
        if(ara[i]==1)
            v.pb(i);
    }
}

void get(ll n)
{
    cnt=0;
    while (n%2==0) {
        n=n/2;
        cnt++;
    }
    tmp=((cnt+1)*(cnt+1))-(cnt*cnt);
    ans*=tmp;
    for (int i=1;i<v.size();i++) {
        cnt=0;
        while (n%v[i] == 0) {
            n=n/v[i];
            cnt++;
        }
        tmp=((cnt+1)*(cnt+1))-(cnt*cnt);
        ans*=tmp;
    }
    if(n>2) {
        ans*=3;
    }
}

int main()
{
    sieve();
    int t,ks=1;
    ll n;
    cin>>t;
    while(t--) {
        ans=1;
        cin>>n;
        get(n);
        ans/=2;
        ans++;
        printf("Case %d: %d\n",ks++,ans);
    }
    return 0;
}

