#include <bits/stdc++.h>
using namespace std;
string ara;
int seg[400000];
int sega[400000];
int lazy[400000];
int position;
void build (int at, int L, int R) {
    if (L == R) {
        seg[at] = ara[L-1]-48;
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    seg[at] = 0;
}
void update (int at, int L, int R, int l, int r, int value) {
    if (lazy[at] != 0) {
        sega[at] += lazy[at];
        if(L != R) {
            lazy[2*at] += lazy[at];
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0;
    }
    if (L > r || R < l) return;
    if (L >= l && R <= r) {
        sega[at] += value;
        if (L != R) {
            lazy[2*at] += value;
            lazy[2*at+1] += value;
        }
        return;
    }
    int mid = (L+R) /2;
    update (2*at, L, mid, l, r, value);
    update (2*at+1, mid+1, R, l, r, value);
}
void query (int at, int L, int R, int l, int r) {
    if (lazy[at] != 0) {
        sega[at] += lazy[at];
        if(L != R) {
            lazy[2*at] += lazy[at];
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0;
    }
    if (L > r || R < l) return ;

    if (L >= l && R <= r) {
        position=at;
        return ;
    }
    int mid = (L+R) /2;
    query (2*at, L, mid, l, r);
    query (2*at+1, mid+1, R, l, r);
}
int main ()
{
    int t,ks=1;
    cin>>t;
    while(t--) {
        cin>>ara;
        int n;
        n=ara.length();
        memset (lazy, 0, sizeof (lazy));
        memset (sega, 0, sizeof (sega));
        build (1, 1, n);
        int q;
        scanf("%d",&q);
        getchar();
        printf("Case %d:\n",ks++);
        int st,ed,qu,nmbr;
        char inves;
        for (int i = 1; i <= q; i++){
            scanf("%c",&inves);
            getchar();
            if(inves=='I'){
                scanf("%d %d",&st,&ed);
                getchar();
                update (1, 1, n, st, ed, 1);
            }
            else if(inves=='Q'){
                scanf("%d",&qu);
                getchar();
                query (1, 1, n, qu, qu) ;
                nmbr=sega[position];
                if(nmbr%2==0)
                    printf("%d\n",seg[position]);
                else {
                    if(seg[position]==1)
                        printf("0\n");
                    else
                        printf("1\n");
                }
            }

        }
    }
    return 0;
}

