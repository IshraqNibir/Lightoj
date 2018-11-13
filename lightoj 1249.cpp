#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks;
    cin>>t;
    ks=1;
    while(t--)
    {
        int n,length,width,height,vol,sum,i;
        string name,bechara,choraiya;
        cin>>n;
        map<string,int>my;
        map<int,string>ms;
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>name>>length>>width>>height;
            vol=length*width*height;
            sum=sum+vol;
            my[name]=vol;
            ms[i]=name;
        }
        int pi;
        pi=sum/n;
        int cnt=0;
        for(i=1;i<=n;i++)
        {
            if(my[ms[i]]<pi){
                bechara=ms[i];
                cnt=1;
            }
            if(my[ms[i]]>pi){
                choraiya=ms[i];
                cnt=1;
            }
        }
        printf("Case %d: ",ks++);
        if(cnt==0)
            cout<<"no thief"<<endl;
        else
            cout<<choraiya<<" took chocolate from "<<bechara<<endl;
    }
    return 0;
}
