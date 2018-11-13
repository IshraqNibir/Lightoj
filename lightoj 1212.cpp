#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i,j;
    for(i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        int n,m,nmbr;
        string cmnd;
        list<int>l;
        cin>>n>>m;
        for(j=1;j<=m;j++)
        {
            cin>>cmnd;
            if(cmnd=="pushLeft"){
                cin>>nmbr;
                if(l.size()<n){
                    l.push_front(nmbr);
                    printf("Pushed in left: %d\n",nmbr);
                }
                else
                    cout<<"The queue is full"<<endl;
            }
            else if(cmnd=="pushRight"){
                cin>>nmbr;
                if(l.size()<n){
                    l.push_back(nmbr);
                    printf("Pushed in right: %d\n",nmbr);
                }
                else
                    cout<<"The queue is full"<<endl;
            }
            else if(cmnd=="popLeft"){
                if(l.size()>0){
                    printf("Popped from left: %d\n",l.front());
                    l.pop_front();
                }
                else
                    cout<<"The queue is empty"<<endl;
            }
            else{
                if(l.size()>0){
                    printf("Popped from right: %d\n",l.back());
                    l.pop_back();
                }
                else
                    cout<<"The queue is empty"<<endl;
            }
        }
    }
    return 0;
}
