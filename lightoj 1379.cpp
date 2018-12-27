/*
   Name: Ishraq Ahmed
   Noakhali Science and Technology University
   Email: ishraq.nibir@gmail.com

   Problem Category: Graph theory
   Algo used: Dijkstra
*/


#include <bits/stdc++.h>
using namespace std;
#define mx 50005
#define inf 1000000000
vector <int > g[mx],g1[mx];
vector <int > cost[mx],cost1[mx];
int d[mx],d1[mx];
int cnt;
struct node {
   int city, dist;
   node (int a, int b) { city = a; dist = b;}
   bool operator < (const node& p) const {
      return p.dist < dist;
   }
};
void dijkstra (int src) {
   if(cnt==1) {
       for (int i = 0; i < mx; i++) {
           d[i] = inf;
       }
       priority_queue <node > q;
       d[src] = 0;
       q.push (node(src, 0));
       while (!q.empty()) {
          node top = q.top(); q.pop();
          int u = top.city;
          for (int i = 0; i < g[u].size(); i++) {
             int v = g[u][i];
             if (d[u] + cost[u][i] < d[v]) {
                d[v] = d[u] + cost[u][i];
                q.push (node (v, d[v]));
             }
          }
       }
    }
    else {
        for (int i = 0; i < mx; i++) {
            d1[i] = inf;
        }
        priority_queue <node > q1;
        d1[src] = 0;
        q1.push (node(src, 0));
        while (!q1.empty()) {
           node top = q1.top(); q1.pop();
           int u = top.city;
           for (int i = 0; i < g1[u].size(); i++) {
              int v = g1[u][i];
              if (d1[u] + cost1[u][i] < d1[v]) {
                 d1[v] = d1[u] + cost1[u][i];
                 q1.push (node (v, d1[v]));
              }
           }
        }
    }
}
int main ()
{
   int t, ks=1;
   cin>>t;
   while(t--) {
       int n, e, s, t, p;
       cin >> n >> e >> s >> t >> p;
       vector < pair <int, pair <int,int> > > my;
       for (int i = 0; i < e; i++) {
          int u, v, w;
          cin >> u >> v >> w;
          my.push_back (make_pair(w, make_pair(u, v)));
          g[u].push_back (v);
          g1[v].push_back (u);
          cost[u].push_back (w);
          cost1[v].push_back (w);
       }
       sort (my.begin(),my.end());
       reverse (my.begin(),my.end());
       cnt = 1;
       dijkstra (s);
       cnt = 2;
       dijkstra (t);
       int temp, ans = -1;
       for (int i = 0; i < my.size(); i++) {
           int st = my[i].second.first;
           int ds = my[i].second.second;
           if (d[st] != inf && d1[ds] != inf) {
                temp = d[st] + d1[ds] + my[i].first;
                if (temp <= p)
                    ans = max (ans,my[i].first);
           }
       }
       printf ("Case %d: %d\n", ks++, ans);
       for (int i = 0; i < mx; i++) {g[i].clear(); cost[i].clear(); g1[i].clear(); cost1[i].clear();}
   }
   return 0;
}

