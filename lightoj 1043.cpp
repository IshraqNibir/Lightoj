#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        double a,b,c,r;
        cin>>a>>b>>c>>r;
        double ratio=sqrt(r/(r+1));
        double ans=ratio*a;
        printf("Case %d: %.10lf\n",ks++,ans);
    }
    return 0;
}
