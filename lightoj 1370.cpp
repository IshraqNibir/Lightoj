#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
#define sz 2000004
int ara[sz];
int phi[2000008]={0};
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
    int prvs=0;
    for(int i=2000000;i>=1;i--) {
        if(ara[i]==1) {
            phi[i]=prvs;
            prvs=i;
        }
        else {
            phi[i]=prvs;
        }
    }
    //cout<<phi[15]<<endl;
}

int main()
{
    int a,b,i;
    sieve();
    int t,ks=1;
    cin>>t;
    while(t--) {
        int n;
        ll sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a;
            sum+=phi[a];
        }
        printf("Case %d: %lld Xukha\n",ks++,sum);
    }
    return 0;
}

