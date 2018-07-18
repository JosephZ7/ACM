int matching[__maxNodes]; /* �洢����� */
int check[__maxNodes];

bool dfs(int u)
{
    for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) { // �� u ��ÿ���ڽӵ�
        int v = edges[*i].to;
        if (!check[v]) {     // Ҫ���ڽ���·��
            check[v] = true; // ���뽻��·
            if (matching[v] == -1 || dfs(matching[v])) {
                // �����δ�ǵ㣬˵������·Ϊ����·���򽻻�·���������سɹ�
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; // ����������·������ʧ��
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}
