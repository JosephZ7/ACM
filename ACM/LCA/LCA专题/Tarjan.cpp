struct Edge{
    int v, c;
};
vector<Edge> G[maxn], qur[maxn];
int fa[maxn], dis[maxn], n, ans[205];
bool vis[maxn];

void init() {
    for (int i = 1; i <= n; i++) G[i].clear(), qur[i].clear(), fa[i] = i;
    dis[1] = 0; memset(vis, 0, sizeof(vis));
}

int Find(int x) {
    return fa[x] = fa[x] == x ? x : Find(fa[x]);
}
 
void Tanjar_LCA(int x) {
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); i++) {
        int hh = G[x][i].c, u = G[x][i].v;
        if (vis[u]) continue;
        Tanjar_LCA(u);
        fa[u] = Find(x);	//指向父节点
    }
    for (int i = 0; i < qur[x].size(); i++) {
        int u = qur[x][i].v;
        if (!vis[u]) continue;
        int lca = Find(u);
        ans[qur[x][i].c] = lca;
    }
}
