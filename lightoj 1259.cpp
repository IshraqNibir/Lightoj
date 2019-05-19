#include <bits/stdc++.h>
using namespace std;
#define sz 10000000
bool ara[sz];
vector<int>prime;
void sieve()
{
    int i,j,root;
    for(i=2;i<=sz;i++){
        ara[i]=true;
    }
    root=sqrt(sz);
    for(i=2;i<=root;i++){
        if(ara[i]==1){
            for(j=2;i*j<=sz;j++){
                ara[i*j]=false;
            }
        }
    }
    for(i=2;i<=sz;i++)
        if(ara[i]==true)
            prime.push_back(i);
}
int main()
{
    int t,ks=1,n,cnt=0,i;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;prime[i]<=n/2;i++)
        {
            if(prime[i]>n-prime[i])
                break;
            if(ara[n-prime[i]]==true)
                cnt++;
        }
        printf("Case %d: %d\n",ks++,cnt);
        cnt=0;
    }
    return 0;
}

