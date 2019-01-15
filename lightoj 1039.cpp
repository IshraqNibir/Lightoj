/*
   Name: Ishraq Ahmed
   Dept. of Computer Science and Telecommunication Eng.
   Noakhali Science and Technology University

   Problem Category: Graph Theory
   Method Used: Bfs(finding shortest path)
*/

#include <bits/stdc++.h>
using namespace std;
string s, s1, s2, s3, s4;
char ini1, ini2, ini3;
char des1, des2, des3;
int n;
bool visited[26][26][26];
struct node
{
    char c1;
    char c2;
    char c3;
    int cost;
    node (char a, char b, char c, int d) { c1 = a; c2 = b; c3 = c; cost = d;}
};
int bfs (char a, char b, char c, int l)
{
    queue <node> q;
    q.push (node (a, b, c, l));

    while (!q.empty ()) {
        node top = q.front ();
        q.pop ();
        char u = top.c1;
        char v = top.c2;
        char z = top.c3;
        int cs = top.cost;

        if (u == des1 && v == des2 && z == des3)
            return cs;

        if (visited[u-'a'][v-'a'][z-'a'] != 1) {
            visited[u-'a'][v-'a'][z-'a'] = 1;
            for (int i=1; i<=6; i++) {
                char x;
                if (i == 1) {
                    if (u == 'z')
                        x = 'a';
                    else
                        x = u + 1;
                    if(!visited[x-'a'][v-'a'][z-'a'])
                        q.push (node (x, v, z, cs+1));
                }
                else if (i == 2) {
                    if (v == 'z')
                        x = 'a';
                    else
                        x = v + 1;
                    if(!visited[u-'a'][x-'a'][z-'a'])
                        q.push (node (u, x, z, cs+1));
                }
                else if (i == 3) {
                    if (z == 'z')
                        x = 'a';
                    else
                        x = z + 1;
                    if(!visited[u-'a'][v-'a'][x-'a'])
                        q.push (node (u, v, x, cs+1));
                }
                else if (i == 4) {
                    if (u == 'a')
                        x = 'z';
                    else
                        x = u - 1;
                    if(!visited[x-'a'][v-'a'][z-'a'])
                        q.push (node (x, v, z, cs+1));
                }
                else if (i == 5) {
                    if (v == 'a')
                        x = 'z';
                    else
                        x = v - 1;
                    if(!visited[u-'a'][x-'a'][z-'a'])
                        q.push (node (u, x, z, cs+1));
                }
                else if (i == 6) {
                    if (z == 'a')
                        x = 'z';
                    else
                        x = z - 1;
                    if(!visited[u-'a'][v-'a'][x-'a'])
                        q.push (node (u, v, x, cs+1));
                }
            }
        }
    }
    return -1;
}
int main()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        cin >> s >> s1;
        ini1 = s[0];
        ini2 = s[1];
        ini3 = s[2];
        des1 = s1[0];
        des2 = s1[1];
        des3 = s1[2];
        cin >> n;
        memset (visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            cin >> s2 >> s3 >> s4;
            for (int j = 0; j < s2.length(); j++) {
                for (int k = 0; k < s3.length(); k++) {
                    for (int p = 0; p < s4.length(); p++) {
                        visited[s2[j]-'a'][s3[k]-'a'][s4[p]-'a'] = 1;
                    }
                }
            }
        }
        int ans;
        if (visited[ini1-'a'][ini2-'a'][ini3-'a'])
            ans = -1;
        else
            ans = bfs (ini1, ini2, ini3, 0);
        printf ("Case %d: %d\n",ks++, ans);
    }
    return 0;
}
