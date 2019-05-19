#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        long long num1=abs(c-a);
        long long num2=abs(d-b);
        if(num1 == 0 && num2 == 0) {
			printf("Case %d: 1\n",ks++ );
			continue;
		}

		if(num1 == 0) {
			printf("Case %d: %lld\n",ks++, num2+1 );
			continue;
		}

		if(num2 == 0) {
			printf("Case %d: %lld\n",ks++, num1+1 );
			continue;
        }
        long long ans=gcd(num1,num2)+1;
        printf("Case %d: %lld\n",ks++,ans);
    }
    return 0;
}
