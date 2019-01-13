/*
   Name: Ishraq Ahmed
   Email: ishraq.nibir@gmail.com
   Dept. of Computer Science and Telecommunication Engineering
   Noakhali Science and Technology University

   Problem Category: Segment tree
   Method used: offline technique
*/

#include <bits//stdc++.h>
using namespace std;
#define LL long long
#define inf INT_MAX
#define pb push_back
const int sz = 100005;
int n;
int seg[400010] = {0};
int lazy[400010] = {0};
int ara[100010] = {0};

void update (int at, int L, int R, int l, int r, int value) {
    if (lazy[at] != 0) {
        seg[at] += (lazy[at] * (R-L+1) );
        if(L != R) {
            lazy[2*at] += lazy[at];
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0;
    }
    if (L > r || R < l) return;
    if (L >= l && R <= r) {
        seg[at] += (value * (R-L+1));
        if (L != R) {
            lazy[2*at] += value;
            lazy[2*at+1] += value;
        }
        return;
    }
    int mid = (L+R) /2;
    update (2*at, L, mid, l, r, value);
    update (2*at+1, mid+1, R, l, r, value);
    seg[at] = seg[2*at] + seg[2*at+1];
}

int query (int at, int L, int R, int l, int r) {
    if (lazy[at] != 0) {
        seg[at] += (lazy[at] * (R-L+1));
        if(L != R) {
            lazy[2*at] += lazy[at];
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0;
    }
    if (L > r || R < l) return 0;

    if (L >= l && R <= r) return seg[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return (x + y);
}

int main ()
{
    int tc, cs = 0, q, t, a;
    int res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        memset (seg, 0, sizeof (seg));
        memset (lazy, 0, sizeof (lazy));
        memset (ara, 0, sizeof (ara));
        for (int i= 1; i <= n; i++) {
            cin >> a;
            ara[i] = a;
        }
        int l,r;
        vector < pair<int,int> > v,v1;
        while (q--) {
            scanf ("%d %d", &l, &r);
            v.pb (make_pair(r,l));
            v1.pb (make_pair(r,l));
        }
        sort (v.begin(),v.end());
        int last[100010] = {-1};
        int current = 0;
        map <int, map<int,int> >my;
        int i = 1;
        while (i <= n) {
            if (last[ara[i]] == -1) {
                last[ara[i]] = i;
                update (1, 1, n, i, i, 1);
            }
            else {
                int pos = last[ara[i]];
                update (1, 1, n, pos, pos, -1);
                last[ara[i]] = i;
                update (1, 1, n, i, i, 1);
            }
            if (v[current].first == i) {
                int st1 = v[current].second;
                int ed1 = v[current].first;
                int ans = query (1, 1, n, st1, ed1);
                my[st1][ed1] = ans;
                current++;
            }
            else
                i++;
        }
        printf ("Case %d:\n", ++cs);
        for (int i = 0; i < v1.size(); i++) {
            int st = v1[i].second;
            int ed = v1[i].first;
            printf("%d\n",my[st][ed]);
        }
    }
    return 0;
}

