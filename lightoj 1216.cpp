#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        double r1,r2,h,p;
        cin>>r1>>r2>>h>>p;
        double r=(p*(r1-r2))/h+r2;
        double x=pi*p*(r2*r2+r2*r+r*r);
        double ans=x/3.0;
        printf("Case %d: %0.9lf\n",i,ans);
    }
    return 0;
}
