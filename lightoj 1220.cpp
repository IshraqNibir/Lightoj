#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        long long num,cnt=0;
        cin>>num;
        long long n=abs(num);
        for(int i=2;i<=100000;i++) {
            for(int j=1;j<=32;j++) {
                long long ans=pow(i,j);
                if(ans>n)
                    break;
                if(ans==n) {
                    if(num<0 && j%2==0)
                        continue;
                    cnt=j;
                    break;
                }
            }
            if(cnt>0)
                break;
        }
        if(cnt==0)
            cnt=1;
        printf("Case %d: %lld\n",ks++,cnt);
    }
    return 0;
}
