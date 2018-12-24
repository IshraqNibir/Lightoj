#include <bits/stdc++.h>
using namespace std;
int ara[1000005];
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--) {
        int n,a;
        cin>>n;
        int mx=-1;
        memset(ara,0,sizeof(ara));
        for(int i=1;i<=n;i++) {
            cin>>a;
            ara[a]++;
            mx=max(mx,a);
        }
        if(mx>=n) {
            printf("Case %d: no\n",ks++);
            continue;
        }
        int skip=0;
        for(int i=0;i<n;i++) {
            if(ara[i]>0) {
                ara[i]--;
            }
            else if(ara[n-i-1]>0) {
                ara[n-i-1]--;
            }
            else {
                skip=1;
                break;
            }
        }
        if(skip==0) {
            printf("Case %d: yes\n",ks++);
        }
        else {
            printf("Case %d: no\n",ks++);
        }
    }
    return 0;
}
