#include <bits/stdc++.h>
#define mx 50005
using namespace std;
int mxm[5*mx],mxm1[5*mx],ace[5*mx],ace1[5*mx];
int mnm[5*mx],mnm1[5*mx];
int num[mx],num1[mx];
void build (int at, int L, int R) { //build array in O(n) ..
    if (L == R) {
        mxm[at] = num[L];
        mnm[at] = num[L];
        ace[at]=1;
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mxm[at] = max(mxm[2*at], mxm[2*at+1]);
    mnm[at] = min(mnm[2*at], mnm[2*at+1]);
    ace[at] = ace[2*at] + ace[2*at+1];
}
void build1 (int at, int L, int R) {
    if(L == R) {
        mxm1[at] = num1[L];
        mnm1[at] = num1[L];
        ace1[at]=1;
        return;
    }
    int mid = (L+R) /2;
    build1 (2*at, L, mid);
    build1 (2*at+1, mid+1, R);
    mxm1[at] = max(mxm1[2*at], mxm1[2*at+1]);
    mnm1[at] = min(mnm1[2*at], mnm1[2*at+1]);
    ace1[at] = ace1[2*at] + ace1[2*at+1];
}
int query (int at, int L, int R, int nmbr) {
    if (mnm[at] > nmbr && mxm[at] >nmbr) return 0;
    if (mnm[at] <= nmbr && mxm[at] <= nmbr) return ace[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, nmbr);
    int y = query (2*at+1, mid+1, R, nmbr);
    return (x + y);
}
int query1 (int at, int L, int R, int nmbr) {
    if (mnm1[at] > nmbr && mxm1[at] >nmbr) return 0;
    if (mnm1[at] < nmbr && mxm1[at] < nmbr) return ace1[at];
    int mid = (L+R) /2;
    int x = query1 (2*at, L, mid, nmbr);
    int y = query1 (2*at+1, mid+1, R, nmbr);
    return (x + y);
}
int main ()
{
    int t,ks=1;
    cin>>t;
    while(t--) {
        int n,q;
        num[0]=-1,num1[0]=-1;
        cin>>n>>q;
        for(int i=1;i<=n;i++) {
            scanf("%d %d",&num[i],&num1[i]);
        }
        sort(num,num+n);
        sort(num1,num1+n);
        build (1, 1, n);
        build1 (1, 1, n);
        int nmbr;
        printf("Case %d:\n",ks++);
        for(int i=1;i<=q;i++) {
            scanf("%d",&nmbr);
            int bilai = query (1, 1, n, nmbr);
            int kutta = query1 (1, 1, n, nmbr);
            printf("%d\n",bilai-kutta);
        }
    }
    return 0;
}

