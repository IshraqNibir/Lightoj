#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100000001
ll col[sz/64+10];
int prm[5761509];
int cnt=0;
unsigned  jacky[5761509];
void sieve()//1 indexed
{
    long long i,j,k;
    for(i=3;i<sz;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<sz;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));

    prm[cnt++]=2;
    for (int i = 3; i<sz; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
            prm[cnt++] = i;
}
unsigned find_sqrt_ans(int x)
{
    int k = sqrt(x), now;
    unsigned ret=1, cnts;
    for (int i = 0; prm[i]<=k; i++)
    {
        now = x/prm[i];
        cnts=1;
        while(now>=prm[i])
        {
            now/=prm[i];
            cnts*=prm[i];
        }
        ret*=cnts;
    }
    return ret;
}
int main()
{
    sieve();
    jacky[0]=2;
    for(int i=1;i<5761509;i++)
        jacky[i]=prm[i]*jacky[i-1];
    int t,ks=1;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        unsigned int ans=find_sqrt_ans(n);
        int up=upper_bound(prm,prm+cnt,n)-prm-1;
        ans=ans*jacky[up];
        printf("Case %d: %u\n",ks++,ans);
    }
    return 0;
}
