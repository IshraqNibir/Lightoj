#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i,j;
    for(i=1;i<=t;i++)
    {
        stack<string>fr,bc;
        string cur="http://www.lightoj.com/";
        string op,web;
        printf("Case %d:\n",i);
        while(1)
        {
            cin>>op;
            if(op=="VISIT")
            {
                 cin>>web;
                 cout<<web<<endl;
                 bc.push(cur);
                 cur=web;
                 while(!fr.empty())
                    fr.pop();
            }
            else if(op=="BACK")
            {
                if(bc.size()>0){
                    cout<<bc.top()<<endl;
                    fr.push(cur);
                    cur=bc.top();
                    bc.pop();
                }
                else
                {
                    cout<<"Ignored"<<endl;
                }
            }
            else if(op=="FORWARD")
            {
                if(fr.size()>0)
                {
                    cout<<fr.top()<<endl;
                    bc.push(cur);
                    cur=fr.top();
                    fr.pop();
                }
                else
                {
                    cout<<"Ignored"<<endl;
                }
            }
            else
                break;
        }
    }
    return 0;
}
