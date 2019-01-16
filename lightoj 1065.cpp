/*
   Name: Ishraq Ahmed
   Dept. of Computer Science and Telecommunication Eng.
   Noakhali Science and Technology University
   Problem Category: Matrix Exponentiation
   Method Used: Very basic (finding nth fibonacci)
*/

#include <bits/stdc++.h>
using namespace std;
#define N 2
#define ll long long
#define pb push_back
int dp[50][2][2];
int mod = 1;
void multiply(int mat1[][N],
			int mat2[][N],
			int res[][N])
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			res[i][j] = 0;
			for (k = 0; k < N; k++)
				res[i][j] += (mat1[i][k] * mat2[k][j]) % mod;

		}
	}
}
int main()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        memset (dp, 0, sizeof(dp));
        mod=1;
        ll n, a, b, m;
        cin >> a >> b >> n >> m;
        while (m > 0) {
            mod *= 10;
            m--;
        }
        if (n == 0) {
            printf ("Case %d: %d\n", ks++, a % mod);
            continue;
        }
        if (n == 1) {
            printf ("Case %d: %d\n", ks++, b % mod);
            continue;
        }
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;
        dp[0][1][1] = 0;
        for (int i = 1; i < 34; i++) {
            int res[N][N], temp[N][N];
            temp[0][0] = dp[i-1][0][0] % mod;
            temp[0][1] = dp[i-1][0][1] % mod;
            temp[1][0] = dp[i-1][1][0] % mod;
            temp[1][1] = dp[i-1][1][1] % mod;
            multiply (temp, temp, res);
            dp[i][0][0] = res[0][0] % mod;
            dp[i][0][1] = res[0][1] % mod;
            dp[i][1][0] = res[1][0] % mod;
            dp[i][1][1] = res[1][1] % mod;
        }
        n--;
        vector <int> v;
        while (n > 0) {
            int rem = n % 2;
            v.pb (rem);
            n /= 2;
        }
        int temp1[N][N];
        int pos;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
               temp1[0][0] = dp[i][0][0];
               temp1[0][1] = dp[i][0][1];
               temp1[1][0] = dp[i][1][0];
               temp1[1][1] = dp[i][1][1];
               pos = i;
               break;
            }
        }
        int restr[N][N];
        int skip = 0;
        for (int i = pos+1; i < v.size(); i++) {
            if (v[i] == 1) {
                skip = 1;
                int bilai[N][N];
                bilai[0][0] = dp[i][0][0];
                bilai[0][1] = dp[i][0][1];
                bilai[1][0] = dp[i][1][0];
                bilai[1][1] = dp[i][1][1];
                multiply (temp1, bilai, restr);
                temp1[0][0] = restr[0][0];
                temp1[0][1] = restr[0][1];
                temp1[1][0] = restr[1][0];
                temp1[1][1] = restr[1][1];
            }
        }
        if (skip == 0) {
            restr[0][0] = temp1[0][0];
            restr[0][1] = temp1[0][1];
            restr[1][0] = temp1[1][0];
            restr[1][1] = temp1[1][1];
        }
        ll ans = ((restr[0][0]*b) + (restr[0][1]*a)) % mod;
        printf ("Case %d: %lld\n", ks++, ans);
    }
    return 0;
}
