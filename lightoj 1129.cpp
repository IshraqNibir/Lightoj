#include <bits/stdc++.h>
using namespace std;
#define max_node 100005
#define max_len 10
int node[max_node][10];
int root,nnode;
int isword[max_node];
bool ans;
string s,s1;
void initialize() {
    root=0;
    nnode=0;
    for(int i=0;i<26;i++)
        node[root][i]=-1;
    memset(isword,0,sizeof(isword));
}
void insert() {
    cin>>s;
    int now=root;
    int cnt=0;
    for(int i=0;i<s.length();i++) {
        if(node[now][s[i]-'0']==-1) {
            node[now][s[i]-'0']=++nnode;
            for(int j=0;j<26;j++)
                node[nnode][j]=-1;
            cnt=1;
        }
        now=node[now][s[i]-'0'];
        if(isword[now]==1)
            ans=false;
    }
    if(cnt==0)
        ans=false;
    isword[now]=1;
}
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--) {
        ans=true;
        initialize();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            insert();
        if(ans==false)
            printf("Case %d: NO\n",ks++);
        else
            printf("Case %d: YES\n",ks++);
    }
    return 0;
}
