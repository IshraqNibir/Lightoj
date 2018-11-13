#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        double r1,r2,r3,a,b,c,s,angleA,angleB,angleC,areaA,areaB,areaC;
        cin>>r1>>r2>>r3;
        a=r2+r3;
        b=r1+r2;
        c=r1+r3;
        s=(a+b+c)/2;
        s=s*(s-a)*(s-b)*(s-c);
        double atri=sqrt(s);
        angleA=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
        angleB=acos(((c*c)+(a*a)-(b*b))/(2*c*a));
        angleC=acos(((b*b)+(a*a)-(c*c))/(2*a*b));
        angleA=(angleA*180)/pi;
        angleB=(angleB*180)/pi;
        angleC=(angleC*180)/pi;
        areaA=((pi*r1*r1)/360)*angleA;
        areaB=((pi*r3*r3)/360)*angleB;
        areaC=((pi*r2*r2)/360)*angleC;
        double ans=atri-(areaA+areaB+areaC);
        printf("Case %d: %.10lf\n",ks++,ans);
    }
    return 0;
}
