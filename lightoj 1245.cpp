#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long ans=0;
        int last;
        for(int i=1;i<=sqrt(n);i++)
        {
            ans=ans+(n/i);
        }
        last=sqrt(n);
        last=n/last;
        int num,tot;
        for(int i=last-1;i>=1;i--)
        {

            num=(n/i)-(n/(i+1));
            tot=num*i;
            ans=ans+tot;
        }
        printf("Case %d: %lld\n",ks++,ans);
    }
    return 0;
}
