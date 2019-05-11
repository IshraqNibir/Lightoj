#include <bits/stdc++.h>
#define sz 30005
#define pb push_back
using namespace std;
vector<int>adj[sz],cost[sz];
int vis[sz],level[sz],level1[sz];
void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    vis[s]=1;
    level[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++) {
            int v=adj[u][i];
            if(!vis[v]) {
                level[v]=level[u]+cost[u][i];
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
void we_bfs(int s)
{
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    vis[s]=1;
    level[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++) {
            int v=adj[u][i];
            if(!vis[v]) {
                level[v]=level[u]+cost[u][i];
                //cout<<v<<" "<<level[v]<<endl;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
void we_bfs1(int s)
{
    memset(vis,0,sizeof(vis));
    memset(level1,0,sizeof(level1));
    vis[s]=1;
    level1[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++) {
            int v=adj[u][i];
            if(!vis[v]) {
                level1[v]=level1[u]+cost[u][i];
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int t,ks=1;
    scanf("%d",&t);
    while(t--) {
        int n,u,v,w;
        scanf("%d",&n);
        for(int i=1;i<n;i++) {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        bfs(0);
        int far=-1,tmp,node1,node2;
        for(int i=0;i<n;i++) {
            tmp=level[i];
            if(tmp>far) {
                far=tmp;
                node1=i;
            }
        }
        bfs(node1);
        far=-1;
        for(int i=0;i<n;i++) {
            tmp=level[i];
            if(tmp>far) {
                far=tmp;
                node2=i;
            }
        }
        //cout<<node1<<" "<<node2<<endl;
        we_bfs(node1);
        we_bfs1(node2);
        int ans;
        printf("Case %d:\n",ks++);
        for(int i=0;i<n;i++) {
            ans=max(level[i],level1[i]);
            printf("%d\n",ans);
        }
        for(int i=0;i<sz;i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }
}
