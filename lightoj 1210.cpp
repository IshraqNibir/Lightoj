#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector <int> g[N];
vector <int> rg[N];
vector <int> vc;
bool vis[N];
int comp[N];
int inDegree[N];
int outDegree[N];
vector <int> compo[N];
void reset () {
    for (int i = 0; i < N; i++ ) {
        g[i].clear();
        rg[i].clear();
        compo[i].clear();
    }
    vc.clear();
    memset (vis, false, sizeof vis);
    memset (inDegree, 0, sizeof inDegree);
    memset (outDegree, 0, sizeof outDegree);
    memset (comp, 0, sizeof comp);
}
void dfs1 (int u) {
    vis[u] = true;
    for (int i = 0; i < g [u].size(); i++ ) {
        if ( !vis[g[u][i]] ) dfs1(g[u][i]);
    }
    vc.push_back(u);
}
void dfs2 (int u, int c) {
    vis[u] = 1;
    comp[u] = c;
    for (int i = 0; i < rg[u].size(); i++) {
        if (vis[rg[u][i]] == 0) dfs2(rg[u][i], c);
    }
}
int main ()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        int n, e, u, v;
        int tc, cs = 0;
        reset ();
        cin >> n >> e;
        for (int i = 0; i < e; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        for (int i = 1; i <= n; i++ ) {
            if (vis[i] == 0)
                dfs1 (i);
        }

        int componentId = 0;
        for (int i = 0; i <= n; i++)
            vis[i] = 0;

        for (int i = vc.size()-1; i >= 0; i--) {
            if (vis[vc[i]] == 0)
                dfs2(vc[i], ++componentId);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (comp[i] != comp[g[i][j]]) {
                    inDegree[comp[g[i][j]]]++;
                    outDegree[comp[i]]++;
                }
            }
        }
        int in = 0, out = 0;
        for (int i = 1; i <= componentId; i++) {
            if (inDegree[i] == 0)
                in++;
            if (outDegree[i] == 0)
                out++;
        }
        int ans = max (in, out);
        if (componentId == 1)
            ans = 0;
        printf ("Case %d: %d\n", ks++, ans);
    }
    return 0;
}
