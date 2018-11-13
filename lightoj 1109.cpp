#include <bits/stdc++.h>
using namespace std;
vector< pair <int,int> >my;
void fun()
{
    my.push_back(make_pair(0,0));
    my.push_back(make_pair(1,1));
    for(int i=2;i<=1000;i++)
    {
        int cnt=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
                cnt++;
        }
        //if(i==192)
          //  cout<<cnt<<endl;
        my.push_back(make_pair(cnt,i));
    }
     sort(my.begin()+2, my.end());
     int mnt=my[2].first;
     int st;
     st=2;
     for(int i=2;i<=1000;i++)
     {
         //if(mnt==12)
           // cout<<my[i].second<<endl;
         if(my[i].first==mnt)
            continue;
         else
         {
             reverse(my.begin()+st,my.begin()+i);
             st=i;
             mnt=my[i].first;
         }
     }
}
int main()
{
    fun();
    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        printf("Case %d: %d\n",ks++,my[n].second);
    }
    return 0;
}
