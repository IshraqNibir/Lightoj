#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int t, ks=1;
    cin >> t;
    while (t--) {
        int n,a,b;
        cin >> n;
        map<int,int>st,ed;
        vector<int>v;
        for(int i=1; i<=n; i++) {
            cin >> a >> b;
            v.pb(a);
            v.pb(b);
            st[a]++;
            ed[b]++;
        }
        sort(v.begin(),v.end());
        int cnt=0;
        int ans=-1;
        for(int i=0; i<v.size(); i++) {
            if(st[v[i]]>0) {
                cnt++;
                st[v[i]]--;
                ans=max(ans,cnt);
            }
            else if(ed[v[i]]>0) {
                cnt--;
                ed[v[i]]--;
            }
        }
        printf("Case %d: %d\n",ks++,ans);
    }
    return 0;
}
