#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int a,b;
        char ch;
        cin>>a>>ch>>b;
        double r=sqrt(a*a+b*b)/2.0;
        double theta=(r*r+r*r-b*b)/(2.0*r*r);
        theta=acos(theta);
        double s=r*theta*1.0;
        double ratio=200*1.0/(a+s);
        printf("Case %d: %.8lf %.8lf\n",ks++,ratio*a,ratio*b);
    }
    return 0;
}
