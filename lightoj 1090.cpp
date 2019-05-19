#include <bits/stdc++.h>
using namespace std;
int fun (int n, int d) {
    int cnt = 0;
    for (int i = d; i <= n; i = i*d) cnt += (int) (n/i);
    return cnt;
}
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n,r,first,second,q,p;
        scanf("%d %d %d %d",&n,&r,&p,&q);
        int num1=fun(n,2)-fun(r,2)-fun(n-r,2);
        int num2=fun(n,5)-fun(r,5)-fun(n-r,5);
        int cnt5 = 0, cnt2 = 0;
        while (p %5 == 0) {
            p /= 5; cnt5++;
        }
        while (p %2 == 0) {
            p /= 2; cnt2++;
        }
        num1+=(cnt2*q);
        num2+=(cnt5*q);
        int ans=max(0,min(num1,num2));
        printf("Case %d: %d\n",ks++,ans);
    }
    return 0;
}
