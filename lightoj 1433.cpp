#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int ox,oy,ax,ay,bx,by;
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        double x;
        x=pow((ax-ox),2)+pow((ay-oy),2);
        double OA=sqrt(x);
        x=pow((bx-ox),2)+pow((by-oy),2);
        double OB=sqrt(x);
        x=pow((ax-bx),2)+pow((ay-by),2);
        double AB=sqrt(x);
        double angle=((OA*OA)+(OB*OB)-(AB*AB))/(2*OA*OB*1.0);
        angle=acos(angle);
        //angle=(angle*pi)/180;
        printf("Case %d: %0.6lf\n",ks++,angle*OA);
    }
    return 0;
}
