/*  gyt
       Live up to every day            */
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#include <time.h>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 300;
const ll maxm = 1e7;
const ll mod = 10000007;
const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
int n, m;
int cap[maxn][maxn], dep[maxn];

int bfs(int s, int t) {
    queue<int>que;
    while(!que.empty())  que.pop();
    memset(dep, -1, sizeof(dep));
    dep[s]=0;
    que.push(s);
    while(!que.empty()) {
        int u=que.front();  que.pop();
        for (int v=1; v<=m; v++) {
            if (cap[u][v]>0 && dep[v]==-1) {
                dep[v]=dep[u]+1;
                que.push(v);
            }
        }
    }
    return dep[t] != -1;
}
int dfs(int u, int mi, int t) {
    if (u==t)  return mi;
    int tmp;
    for (int v=1; v<=m; v++) {
        if(cap[u][v] > 0 && dep[v] == dep[u] + 1  && (tmp = dfs(v, min(mi, cap[u][v]), t))){
            cap[u][v]-=tmp;
            cap[v][u]+=tmp;
            return tmp;
        }
    }
    return 0;
}
int dnic() {
    int ans=0, tmp;
    while(bfs(1, m)) {
         tmp=dfs(1, INF, m);
        if (tmp==0)  break;
        ans += tmp;
    }
    return ans;
}
void init() {
    memset(cap, 0, sizeof(cap));
}
void solve() {
    while(scanf("%d%d", &n, &m)!=EOF) {
        init();
        for (int i=0; i<n; i++) {
            int a, b, c;  scanf("%d%d%d", &a, &b, &c);
            cap[a][b]+=c;
        }
        int ans=0;
         ans=dnic();
        printf("%d\n", ans);
    }
}
int main() {
    int t = 1;
   // freopen("in.txt", "r", stdin);
    //scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}
