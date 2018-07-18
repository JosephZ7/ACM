void dfs(int u, int fa, int dep) {
    deep[u] = dep;
    for (int i = 1; i < 20; i++) { 
        up[u][i] = up[up[u][i-1]][i-1];
    }   //up[u][i]表示u的第2^i个祖先
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        up[v][0] = u;
        dfs(v, u, dep + 1);
    }
}

int kth(int u, int k) { //求节点u的第k个祖先
    for (int i = 0; i < 20; i++) {
        if ((1<<i) & k)
            u = up[u][i];
    }
    return u;
}
