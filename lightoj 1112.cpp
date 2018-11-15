#include <bits/stdc++.h>
using namespace std;
int mnm[4*100005];
int num[100005];
void build (int at, int L, int R) { //build array in O(log2n) ..
    if (L == R) {
        mnm[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mnm[at] = mnm[2*at] + mnm[2*at+1];
}
void update (int at, int L, int R, int pos, int value) { //update by O(logn)..
    //cout<<"Yes"<<endl;
    if (L == R) {
        mnm[at] += value;
        return;
    }
    int mid = (L+R) /2;
    if (pos <= mid) update (2*at, L, mid, pos, value);
    else update (2*at+1, mid+1, R, pos, value);
    mnm[at] = mnm[2*at] + mnm[2*at+1];
}
int query (int at, int L, int R, int l, int r) { ////search in range [1,5].. in O(logn)
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return mnm[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return x + y;
}
int main ()
{
    //memset (mnm, 0, sizeof (mnm)); //all indexing to maximum value..not necessary..
    int t,ks=1;
    scanf("%d",&t);
    while(t--){
        memset (mnm, 0, sizeof (mnm));
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        build (1, 1, n);
        int op,pos,mon,st,ed;
        printf("Case %d:\n",ks++);
        for(int i=1;i<=q;i++){
            scanf("%d",&op);
            if(op==1){
                scanf("%d",&pos);
                printf("%d\n",num[pos+1]);
                update(1,1,n,pos+1,-num[pos+1]);
                num[pos+1]=0;
            }
            else if(op==2){
                scanf("%d %d",&pos,&mon);
                update(1,1,n,pos+1,mon);
                num[pos+1]+=mon;
            }
            else{
                scanf("%d %d",&st,&ed);
                printf("%d\n",query(1,1,n,st+1,ed+1));
            }
        }
    }
    return 0;
}

