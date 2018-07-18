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
const int maxn = 300+10;
const ll maxm = 1e7;
const int modd = 10000007;
const int INF = 1<<30;
const db eps = 1e-9;
int cap[maxn][maxn], f[maxn], pre[maxn];
    int n, m;

void init() {
    memset(cap, 0, sizeof(cap));
    memset(f, INF, sizeof(f));
}
int BFS(int st, int ed) {
    queue<int>que;
    while(!que.empty())  que.pop();
    for (int i=0; i<maxn; i++)  pre[i]=-1;
    pre[st]=0;
    f[st]=INF;
    que.push(st);
    while(!que.empty()) {
        int shang=que.front();
        que.pop();
        if (shang==ed)  break;
        for (int i=1; i<=m; i++) {
            if (i!=st && cap[shang][i]>0 && pre[i]==-1) {
                pre[i]=shang;
                f[i]=min(cap[shang][i],f[shang]);
                que.push(i);
            }
        }
    }
    if (pre[ed]==-1)  return -1;
    else
        return f[ed];
}
int max_flow(int st, int ed) {
    int increas=0;
    int sum=0;
    while((increas=BFS(st,ed))!=-1) {
        int k=ed;
        while(k!=st) {
            int shang=pre[k];
            cap[shang][k]-=increas;
            cap[k][shang]+=increas;
            k=shang;
        }
        sum+=increas;
    }
    return sum;
}
void solve() {
    while(scanf("%d%d", &n, &m)!=EOF) {
        init();
        for (int i=0; i<n; i++) {
            int a, b, c;  scanf("%d%d%d", &a, &b, &c);
            if (a==b)  continue;
            cap[a][b]+=c;
        }
        printf("%d\n", max_flow(1, m));
    }
}
int main() {
    int t = 1;
    //freopen("in.txt", "r", stdin);
    //scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
