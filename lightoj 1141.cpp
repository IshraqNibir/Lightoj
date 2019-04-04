#include "bits/stdc++.h"
using namespace std;

#define MAXN   1005

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
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y) {
            printf("Case %d: 0\n",ks++);
            continue;
        }
        queue<int>q;
        q.push(x);
        int vis[1100];
        memset(vis,0,sizeof(vis));
        while(!q.empty()) {
            int u=q.front();
            vector <int> p = getFactorization(u);
            q.pop();
            for(int i=0;i<p.size();i++) {
                if(p[i]==1 || p[i]==u)
                    continue;
                int v=u+p[i];
                if(vis[v]==0 && v<=1000) {
                    vis[v]=vis[u]+1;
                    q.push(v);
                }
            }
        }
        if(vis[y]==0)
            vis[y]=-1;
        printf("Case %d: %d\n",ks++,vis[y]);
    }
    return 0;
}

