#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int n,k,kutta,minimum;
void fun()
{
    int low=minimum,mid;
    int high=100000000;
    while(low<=high) {
        mid=(low+high)/2;
        int cnt=0,sum=0;
        for(int i=1;i<v.size();i++) {
            sum+=v[i];
            if(sum>mid) {
                cnt++;
                sum=v[i];
            }
            if(i==v.size()-1 && sum<=mid)
                cnt++;
        }
        if(cnt>k+1)
            low=mid+1;
        else {
            kutta=mid;
            high=mid-1;
        }
    }
}
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--) {
        int a;
        scanf("%d %d",&n,&k);
        minimum=-1;
        v.push_back(-1);
        for(int i=1;i<=n+1;i++) {
            scanf("%d",&a);
            minimum=max(minimum,a);
            v.push_back(a);
        }
        fun();
        printf("Case %d: %d\n",ks++,kutta);
        int sum=0,cnt=1,loop=10000;
        for(int i=1;i<v.size();i++) {
            if(sum+v[i]>kutta) {
                printf("%d\n",sum);
                cnt++;
                sum=v[i];
            }
            else
                sum+=v[i];
            if(i==v.size()-1 && sum<=kutta) {
                printf("%d\n",sum);
                continue;
            }
            if(v.size()-1-i==k+1-cnt) {
                printf("%d\n",sum);
                loop=i;
                break;
            }
        }
        for(int i=loop+1;i<v.size();i++)
            printf("%d\n",v[i]);
        v.clear();
    }
    //63851
    return 0;
}
