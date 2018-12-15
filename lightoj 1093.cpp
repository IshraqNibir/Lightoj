#include <bits/stdc++.h>
using namespace std;
int mnm[4*100005];
int maxi[4*100005];
int num[100005];
void buildmin (int at, int L, int R) { //build array in O(log2n) ..
    if (L == R) {
        mnm[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    buildmin (2*at, L, mid);
    buildmin (2*at+1, mid+1, R);
    mnm[at] = min(mnm[2*at], mnm[2*at+1]);
}
void buildmax(int at, int L, int R)
{
    if (L == R) {
        maxi[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    buildmax (2*at, L, mid);
    buildmax (2*at+1, mid+1, R);
    maxi[at] = max(maxi[2*at], maxi[2*at+1]);
}
int querymin (int at, int L, int R, int l, int r) { ////search in range [1,5].. in O(logn)
    if (L > r || R < l) return 1e9;
    if (L >= l && R <= r) return mnm[at];
    int mid = (L+R) /2;
    int x = querymin (2*at, L, mid, l, r);
    int y = querymin (2*at+1, mid+1, R, l, r);
    return min(x, y);
}
int querymax (int at, int L, int R, int l, int r) { ////search in range [1,5].. in O(logn)
    if (L > r || R < l) return -1;
    if (L >= l && R <= r) return maxi[at];
    int mid = (L+R) /2;
    int x = querymax (2*at, L, mid, l, r);
    int y = querymax (2*at+1, mid+1, R, l, r);
    return max(x, y);
}
int main ()
{
    int t,ks=1;
    scanf("%d",&t);
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        buildmin (1, 1, n);
        buildmax (1, 1, n);
        int minimum,maximum,ans;
        ans=0;
        for(int i=1;i<=n-d+1;i++)
        {
            minimum=querymin(1, 1, n, i, i+d-1);
            maximum=querymax(1, 1, n, i, i+d-1);
            ans=max(ans,maximum-minimum);
        }
        printf("Case %d: %d\n",ks++,ans);
    }
    return 0;
}
