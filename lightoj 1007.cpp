#include <bits/stdc++.h>
using namespace std;
#define sz 5000006
int ara[sz];
unsigned long long phi[5000006]={0};
void sieve()
{
    int i,j,root;
    for(i=2;i<=sz;i++){
        ara[i]=1;
    }
    root=sqrt(sz);
    for(i=2;i<=root;i++){
        if(ara[i]==1){
            for(j=2;i*j<=sz;j++){
                ara[i*j]=0;
            }
        }
    }
}
void sievephi(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        phi[i]=i;
    phi[1]=1;
    ara[1]=1;
    for(i=2;i<=n;i++){
        if(ara[i]==1)
        {
            for(j=i;j<=n;j=j+i){
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
void precal()
{
    for(int i=2;i<=sz;i++)
    {
        phi[i]=phi[i]*phi[i];
    }
    for(int i=2;i<=sz;i++)
    {
        phi[i]+=phi[i-1];
    }
}
int main()
{
    int a,b,i;
    sieve();
    sievephi(5000006);
    precal();
    int t,ks=1;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",ks++,phi[b]-phi[a-1]);
    }
    return 0;

}
