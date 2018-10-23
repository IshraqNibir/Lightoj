#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc, ks=1;
    cin >> tc;
    while (tc--) {
        int n, r, a;
        cin >> n;
        vector <int> v;
        v.push_back (0);
        int dif = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            v.push_back (a);
            dif = max (dif, v[i]-v[i-1]);
        }
        int L, R;
        L = dif;
        R = 1000000005;
        int ans = 1000000005;
        while (L <= R) {
            int mid = (L+R)/2;
            int cnt = mid;
            int skip = 0;
            for (int i = 1; i <= n; i++) {
                if (v[i] - v[i-1] == cnt)
                    cnt--;
                else if (v[i]-v[i-1] > cnt) {
                    skip = 1;
                    break;
                }
            }
            if (skip == 1)
                L = mid+1;
            else {
                ans = min(ans,mid);
                R = mid-1;
            }
        }
        printf ("Case %d: %d\n", ks++, ans);
    }
    return 0;
}
