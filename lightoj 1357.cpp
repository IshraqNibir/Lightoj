#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int vis[100005], num[100005], level[100005];
vector <int> adj[100005];
int cnt = 0;
void dfs(int at)
{
    if (vis[at])
        return;
    vis[at] = 1;
    cnt++;
    for (int i=0; i<adj[at].size(); i++) {
        dfs (adj[at][i]);
        num[at] += num[adj[at][i]];
    }
}
void bfs(int s)
{
    vis[s] = 1;
    queue <int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            if (!vis[v]) {
                level[v] = level[u]+1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int t, ks=1;
    cin >> t;
    while (t--) {
        for (int i=0; i<100005; i++)
            adj[i].clear();
        int n, u, v;
        memset (vis, 0, sizeof(vis));
        for (int i=1; i< 100005; i++)
            num[i] = 1;
        cnt = 0;
        cin >> n;
        for (int i=1; i<n; i++) {
            cin >> u >> v;
            adj[u].pb(v);
        }
        dfs(1);
        memset (vis, 0, sizeof(vis));
        bfs(1);
        ll frnds = 0, not_frnds = 0;
        for (int i=1; i<=n; i++) {
            int lv = level[i];
            int node = num[i];
            frnds = lv+node;
            not_frnds += (n-frnds);
        }
        ll ans = not_frnds/2;
        printf ("Case %d: %d %lld\n",ks++, cnt-1, ans);
    }
    return 0;
}
