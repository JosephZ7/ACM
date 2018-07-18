int LCA(int u, int v) {
    if (deep[u] < deep[v]) swap(u, v);
    int k = deep[u] - deep[v];
    u = kth(u, k);
    if (u != v) {
        for (int i = 19; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        u = up[u][0];
    }
    return u;
}
