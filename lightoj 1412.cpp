#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int vis[100005],vis1[100005];
int level[100005],level1[100005];
vector<int>g[100005];
int prvs,prvs1;
int node,cnt,bilai;
void bfs(int s)
{
    bilai=1;
    queue<int>q;
    if(cnt==0)
        vis[s]=1;
    else
        vis1[s]=1;
    q.push(s);
    if(cnt==0)
        level[s]=1;
    else
        level1[s]=1;
    node=s;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++) {
            int v=g[u][i];
            if(cnt==0) {
                if(!vis[v]) {
                    bilai++;
                    level[v]=level[u]+1;
                    if(level[v]>prvs) {
                        prvs=level[v];
                        node=v;
                    }
                    vis[v]=1;
                    q.push(v);
                }
            }
            else if(cnt==1) {
                if(!vis1[v]) {
                    bilai++;
                    level1[v]=level1[u]+1;
                    if(level1[v]>prvs1) {
                        prvs1=level1[v];
                    }
                    vis1[v]=1;
                    q.push(v);
                }
            }
       }
    }
}
int main()
{
    int t,ks=1;
    scanf("%d",&t);
    while(t--) {
        int n,m,u,v;
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        memset(level,0,sizeof(level));
        memset(level1,0,sizeof(level1));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++) {
            scanf("%d %d",&u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }
        int ara[100005];
        memset(ara,0,sizeof(ara));
        for(int i=1;i<=n;i++) {
            cnt=0;
            if(!vis[i]) {
                prvs=1;
                prvs1=1;
                bilai=0;
                bfs(i);
                cnt=1;
                bilai=0;
                //cout<<node<<endl;
                bfs(node);
                //cout<<bilai<<" "<<prvs1<<endl;
                ara[bilai]=prvs1;
            }
        }
        for(int i=n-1;i>=1;i--) {
            if(ara[i]<ara[i+1])
                ara[i]=ara[i+1];
            if(ara[i]>i)
                ara[i]=i;
        }
        int q,k;
        scanf("%d",&q);
        printf("Case %d:\n",ks++);
        for(int i=1;i<=q;i++) {
            scanf("%d",&k);
            int x=ara[k];
            if(x==0) {
                printf("impossible\n");
                continue;
            }
            x=x+(k-x)*2;
            printf("%d\n",x-1);
        }
        for(int i=0;i<100005;i++) {
            g[i].clear();
        }
    }
    return 0;
}
