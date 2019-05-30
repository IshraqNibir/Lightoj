#include<stdio.h>
long way[10005];
int n,k,coin[105];
long coinchange(int k)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(coin[i]<=j)
                way[j]=(way[j]%100000007)+(way[j-coin[i]]%100000007);
        }
    }
    return way[k];
}

    int main()
    {
        int i,t,no=0;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&n,&k);
            way[0]=1;
            for(i=1;i<=k;i++)
            way[i]=0;
        for(i=0;i<n;i++)
        scanf("%d",&coin[i]);
        printf("Case %d: %ld\n",++no,coinchange(k)%100000007);
        }
        return 0;
    }
