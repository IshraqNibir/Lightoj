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
        int sz=sqrt(n);
        long long bilai,fin,ini,ans=0,thakbe,temp;
        for(int i=2;i<=sz;i++)
        {
            bilai=n/i;
            thakbe=bilai-i;
            fin=(bilai*(bilai+1))/2;
            ini=(i*(i+1))/2;
            temp=(fin-ini)+(thakbe*i);
            ans+=(temp+i);
        }
        printf("Case %d: %lld\n",ks++,ans);
    }
    return 0;
}
