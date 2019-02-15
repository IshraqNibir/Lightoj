#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n;
ll power (ll n)
{
    ll ans=1;
    for(ll i=1;i<=n;i++)
        ans=ans*10;
    return ans;
}
ll fun (ll cnt)
{
    for (ll j=cnt; j<=cnt+100; j++) {
            ll div = j;
            vector <ll> v;
            while (div > 0) {
                ll rem = div%10;
                v.pb(rem);
                div = div/10;
            }
            reverse (v.begin(),v.end());
            ll sz = v.size()-2;
            ll nmbr = 0;
            ll pw = sz;
            for (ll i=0; i<=sz; i++) {
                nmbr += (v[i]*power(pw));
                pw--;
            }
            ll dif = j-nmbr;
            if (dif == n)
                return j;
        }
}
int main()
{
    int t, ks=1;
    cin >> t;
    while (t--) {
        cin >> n;
        ll cnt = 0;
        ll div = n;
        while (div > 0) {
            div = div/10;
            cnt += div;
        }
        ll ans1 = 0, ans2 = 0;
        ans1 = fun(cnt+n);
        //cout << ans1 << endl;
        if ((ans1+1)%10 == 0)
            ans2 = ans1 + 1;
        if (ans1 > 0 && ans2 > 0)
            printf ("Case %d: %lld %lld\n", ks++, ans1, ans2);
        else if (ans1 > 0 && ans2 == 0)
            printf ("Case %d: %lld\n", ks++, ans1);
    }
    return 0;
}
