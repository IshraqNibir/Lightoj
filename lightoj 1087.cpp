#include <bits/stdc++.h>
using namespace std;
#define mx 150005
int mnm[4*mx];
int num[mx] ;
int vis[mx];
void build (int at, int L, int R) { //build array in O(log2n) ..
    if (L == R) {
        mnm[at] = vis[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mnm[at] = (mnm[2*at] + mnm[2*at+1]);
}
void update (int at, int L, int R, int pos) { //update by O(logn)..
    if (L == R) {
        mnm[at] = vis[L];
        return;
    }
    int mid = (L+R) /2;
    if (pos <= mid) update (2*at, L, mid, pos);
    else update (2*at+1, mid+1, R, pos);
    mnm[at] = (mnm[2*at] + mnm[2*at+1]);
}
int query (int at, int L, int R, int pos) { ////search in range [1,5].. in O(logn)
    if(L == R)
        return L;
    int mid = (L+R) /2;
    if(pos <= mnm[2*at])
        return query (2*at, L, mid, pos);
    else
        return query (2*at+1, mid+1, R, pos-mnm[2*at]);
}
int main ()
{
    //memset (mnm, 1e9, sizeof (mnm)); //all indexing to maximum value..not necessary..
    int t,ks=1;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) {
            scanf("%d",&num[i]);
            vis[i]=1;
        }
        getchar();
        int sz=n+q;
        build(1, 1, sz);
        char ch;int value;
        printf("Case %d:\n",ks++);
        for(int i=1;i<=q;i++) {
            scanf("%c",&ch);
            scanf("%d",&value);
            getchar();
            //cout<<ch<<endl;
            if(ch=='a') {
                n=n+1;
                vis[n]=1;
                num[n]=value;
                update(1, 1, sz, n);
            }
            else {
                if(value>mnm[1]) {
                    printf("none\n");
                    continue;
                }
                int ans=query(1, 1, sz, value);
                vis[ans]=0;
                update(1, 1, sz, ans);
                printf("%d\n",num[ans]);
            }
        }
    }
    return 0;
}
