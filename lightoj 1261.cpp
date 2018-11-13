#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n,m,k,p,s,w;
        cin>>n>>m>>k;
        int ara[35];
        memset(ara,0,sizeof(ara));
        vector <int> wish[35];
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                cin>>w;
                if(w<0)
                    ara[i]=1;
                wish[i].push_back(w);
            }
        }
        vector <int> sub;
        cin>>p;
        int kutta=0;
        if(p==0) {
            for(int i=0;i<n;i++) {
                if(ara[i]==1)
                    kutta++;
            }
            if(kutta==n)
                printf("Case %d: Yes\n",ks++);
            else
                printf("Case %d: No\n",ks++);
            continue;
        }
        for(int i=0;i<p;i++) {
            cin>>s;
            sub.push_back(s);
        }
        int cnt=0,skip;
        for(int i=0;i<n;i++) {
            skip=0;
            for(int j=0;j<k;j++) {
                if(wish[i][j]>0) {
                    for(int l=0;l<sub.size();l++) {
                        if(sub[l]==wish[i][j]) {
                            cnt++;
                            skip=1;
                            break;
                        }
                    }
                }
                else {
                    for(int l=0;l<sub.size();l++) {
                        if(sub[l]==-wish[i][j])
                            break;
                        if(l==sub.size()-1) {
                            cnt++;
                            skip=1;
                        }
                    }
                }
                if(skip==1)
                    break;
            }
        }
        if(cnt==n )
            printf("Case %d: Yes\n",ks++);
        else
            printf("Case %d: No\n",ks++);
    }
    return 0;
}
