vector<int> G[maxn];
int ver[maxn*2], dp[maxn*2][33], tot, R[maxn*2], vis[maxn], first[maxn];
int n;

void dfs(int x, int dep) {
    vis[x] = 1, ver[++tot] = x; R[tot] = dep; first[x] = tot;
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        if (vis[u]) continue;
        dfs(u, dep+1);
        ver[++tot] = x; R[tot] = dep;
    }
}
 
void RMQ_init(int len) {
    for (int i = 1; i <= len; i++) dp[i][0] = i;
    for (int j = 1; (1<<j) <= len; j++) {
        for (int i = 1; i + (1 << j) - 1 <= len; i++) {
            int a = dp[i][j-1], b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = R[a] < R[b] ? a : b;
        }
    }
}
 
int RMQ(int l, int r) {
    int k = 0;
    while ((1 << (k+1)) <= r-l+1) k++;
    int a = dp[l][k], b = dp[r-(1<<k)+1][k];
    return R[a] < R[b] ? a : b;
}
 
int LCA(int u, int v) {
    int x = first[u], y = first[v];
    if (x > y) swap(x, y);
    return ver[RMQ(x, y)];
}
