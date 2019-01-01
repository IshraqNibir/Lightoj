
/* Name: Ishraq Ahmed
   Computer Science and Telecommunication Eng.
   Noakhali Science and Technology University
   Email: ishraq.nibir@gmail.com

   Problem category: Geometry
   Method Used: Trigonometry Formula
*/


#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        double x1, y1, r1;
        cin >> x1 >> y1 >> r1;
        double x2, y2, r2;
        double ans;
        cin >> x2 >> y2 >> r2;
        double d = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
        d = sqrt(d);
        if (r1+r2 <= d) {
            printf("Case %d: 0.0\n",ks++);
            continue;
        }
        if (fabs(r1-r2) >= d) {
            ans = min(r1,r2);
            ans = pi*ans*ans;
            printf("Case %d: %0.8lf\n",ks++,ans);
            continue;
        }
        double alpha = ((d*d) + (r1*r1) - (r2*r2)) / (2*d*r1);
        alpha = acos(alpha);
        alpha = alpha * 180/pi;
        alpha = alpha*2;
        double beta = ((d*d) + (r2*r2) - (r1*r1)) / (2*d*r2);
        beta = acos(beta);
        beta = beta * 180/pi;
        beta = beta*2;
        double temp = alpha * pi/180;
        double temp1 = beta * pi/180;
        double seg = 2*(r1*r1) - (cos(temp)*2*r1*r1);
        seg = sqrt(seg);
        double spec1 = (alpha/360.0) * (pi*r1*r1);
        double spec2 = (beta/360.0) * (pi*r2*r2);
        double s = (r1+r1+seg)/2.0;
        double triangle1 = s*(s-r1)*(s-r1)*(s-seg);
        triangle1 = sqrt(triangle1);
        double s1 = (r2+r2+seg)/2.0;
        double triangle2 = s1*(s1-r2)*(s1-r2)*(s1-seg);
        triangle2 = sqrt(triangle2);
        if(alpha>180)
            triangle1 = -triangle1;
        if(beta>180)
            triangle2 = -triangle2;
        ans = (spec1 - triangle1) + (spec2 - triangle2);
        printf("Case %d: %0.8lf\n",ks++,ans);
    }
    return 0;
}
