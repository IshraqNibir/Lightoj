#include <bits/stdc++.h>
using namespace std;
int mxm[400005];
int num[100005];

void build (int at, int L, int R) { //build array in O(log2n) ..
    if (L == R) {
        mxm[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mxm[at] = max(mxm[2*at], mxm[2*at+1]);
}

int query (int at, int L, int R, int l, int r) { ////search in range [1,5].. in O(logn)
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return mxm[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return max(x, y);
}

int main ()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        int n, c, q;
        cin >> n >> c >> q;
        int tmp[100005],num1[100005];
        for (int i=1; i<=n; i++) {
            scanf ("%d", &tmp[i]);
        }
        int cnt = 1;
        int nmbr = tmp[1];
        num[1] = 1;
        for (int i=2; i<=n; i++) {
            if(tmp[i] == nmbr) {
                cnt++;
                num[i] = cnt;
            }
            else {
                cnt = 1;
                nmbr = tmp[i];
                num[i] = cnt;
            }
        }
        cnt = 1;
        num1[n] = 1;
        nmbr = tmp[n];
        for (int i=n-1; i>=1; i--) {
            if (tmp[i] == nmbr) {
                cnt++;
                num1[i] = cnt;
                //cout<<i<<" "<<cnt<<endl;
            }
            else {
                cnt = 1;
                nmbr = tmp[i];
                num1[i] = cnt;
            }
        }
        //cout<<num1[10]<<endl;
        build (1, 1, n);
        printf ("Case %d:\n", ks++);
        int st, st1, ed, incr, ans, fin;
        for (int i=1; i<=q; i++) {
            scanf ("%d %d", &st, &ed);
            incr = num1[st];
            //cout<<incr<<endl;
            st1 = st + incr;
            if(st1<=ed) {
                ans = query (1, 1, n, st1, ed);
                fin = max (incr,ans);
            }
            else {
                fin = num1[st]-num1[ed]+1;
            }
            printf ("%d\n", fin);
        }
    }
    return 0;
}
/*1
10 5 7
1 1 2 2 2 3 4 5 5 5*/


