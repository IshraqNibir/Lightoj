#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll ara[25];
void fun()
{
    ara[0] = 1;
    for (int i=1; i<=20; i++) {
        ara[i] = i*ara[i-1];
    }
}
int main()
{
    fun();
    int t, ks = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int cnt = 1;
        vector <int> v;
        int high = 20;
        while (cnt <= 22) {
            for (int i=high; i>=0; i--) {
                if (ara[i] <= n) {
                    n -= ara[i];
                    v.pb(i);
                    high = i-1;
                    break;
                }
            }
            cnt++;
        }
        sort(v.begin(),v.end());
        printf("Case %d: ", ks++);
        if (n == 0) {
            cout << v[0] << "!";
            for (int i=1; i<v.size(); i++) {
                cout << "+" << v[i] << "!";
            }
            cout << endl;
        }
        else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
