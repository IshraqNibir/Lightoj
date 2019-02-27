#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, ks=1;
    cin >> t;
    while(t--)
    {
        int n,a;
        cin >> n;
        vector <int> jacky,rifa;

        for(int i=1;i<=n;i++) {
            cin >> a;
            jacky.push_back(a);
        }

        for(int i=1;i<=n;i++) {
            cin >> a;
            rifa.push_back(a);
        }

        sort(jacky.begin(),jacky.end());
        sort(rifa.begin(),rifa.end());

        int ans=0;
        for(int i=0;i<jacky.size();i++) {
            for(int j=rifa.size()-1;j>=0;j--) {
                if(rifa[j]>0 && jacky[i]>rifa[j]) {
                    ans+=2;
                    jacky[i]=-2;
                    rifa[j]=-1;
                    break;
                }
            }
        }

        for(int i=0;i<jacky.size();i++) {
            if(jacky[i]>0) {
                for(int j=0;j<rifa.size();j++) {
                    if(rifa[j]>0 && jacky[i] == rifa[j]) {
                        ans+=1;
                        jacky[i]=-2;
                        rifa[j]=-1;
                        break;
                    }
                }
           }
        }

        printf("Case %d: %d\n",ks++,ans);
    }
    return 0;
}
