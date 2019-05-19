#include "bits/stdc++.h"
using namespace std;

#define MAXN   105
int spf[MAXN];
void sieve()
{
    spf[1] = 1;

    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    sieve();
    int t,ks=1;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        int cnt[105]={0};
        for(int i=2;i<=x;i++){
            vector <int> p = getFactorization(i);
            for(int i=0; i<p.size(); i++)
                cnt[p[i]]++;
        }
        printf("Case %d: ",ks++);
        printf("%d = ",x);
        bool ace=false;
        for(int i=2;i<=x;i++){
            if(cnt[i]>0){
                if(ace)
                    printf(" * ");
                printf("%d (%d)",i,cnt[i]);
                ace=true;
            }
        }
        printf("\n");
    }
    return 0;
}
