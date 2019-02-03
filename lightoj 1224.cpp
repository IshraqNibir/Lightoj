/*
   Name: Ishraq Ahmed
   Computer Science and Telecommunication Eng.
   Noakhali Science and Technology University
   Email: ishraq.nibir@gmail.com

   Problem Category: Trie
   Method Used: Basic trie tree implementation
*/
#include <bits/stdc++.h>
using namespace std;
#define max_node 2500109
#define ll long long
int node[max_node][4];
int root,nnode;
int fre[max_node],level[max_node];
string s;

void initialize() {
    root=0;
    nnode=0;
    for(int i=0;i<4;i++)
        node[root][i]=-1;
    memset(fre,0,sizeof(fre));
    memset(level,0,sizeof(level));
}

void insert() {
    cin>>s;
    int now=root;
    int l=1,x;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='A')
            x=0;
        else if(s[i]=='C')
            x=1;
        else if(s[i]=='G')
            x=2;
        else if(s[i]=='T')
            x=3;

        if(node[now][x]==-1) {
            node[now][x]=++nnode;
            for(int j=0;j<4;j++)
                node[nnode][j]=-1;
        }

        now=node[now][x];
        fre[now]++;
        level[now]=l++;
    }
}

int main()
{
    int t,ks=1;
    cin >> t;
    while (t--) {
        int n;
        initialize();
        cin>>n;
        for(int i=1;i<=n;i++)
            insert();
        int ans=-1;
        for(int i=0;i<2500109;i++) {
            int temp=level[i]*fre[i];
            ans=max(ans,temp);
        }
        printf("Case %d: %d\n",ks++,ans);
    }
    return 0;
}

