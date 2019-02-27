#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<int>v;
        v.push_back(-1);
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        int cnt=0,temp;
        for(int i=1;i<=n;i++) {
            if(v[i]==i)
                continue;
            for(int j=i+1;j<=n;j++) {
                if(v[j]==i) {
                    temp=v[i];
                    v[i]=v[j];
                    v[j]=temp;
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",ks++,cnt);
    }
    return 0;
}
