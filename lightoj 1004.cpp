#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int ara[210][110];
        int n,j,k;
        for(j=0;j<210;j++)
            for(k=0;k<110;k++)
                ara[j][k]=0;
        cin>>n;
        for(j=1;j<=n;j++)
            for(k=1;k<=j;k++)
                cin>>ara[j][k];
        for(j=n+1;j<=n*2-1;j++)
            for(k=1;k<=n*2-j;k++)
                cin>>ara[j][k];
        for(j=2;j<=n;j++){
            for(k=1;k<=j;k++){
                ara[j][k]=max(ara[j-1][k-1]+ara[j][k],ara[j-1][k]+ara[j][k]);
            }
        }
        for(j=n+1;j<=n*2-1;j++){
            for(k=1;k<=n*2-j;k++){
                ara[j][k]=max(ara[j-1][k]+ara[j][k],ara[j-1][k+1]+ara[j][k]);
            }
        }
        int pos=2*n-1;
        printf("Case %d: %d\n",i,ara[pos][1]);
    }
    return 0;
}
