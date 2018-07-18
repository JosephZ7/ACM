#include <cstdio>
#include <cstring>
int const MAX = 40005;

struct Edge
{
    int id, val; //��ǰ����ţ���Ȩ
    int next;  //��һ��
}e[2 * MAX];

int n, m, cnt;
//x, y��ʾѯ�ʵ������յ㣬z��x��y��LCA
int x[MAX], y[MAX], z[MAX];
//fa�����ȣ�dist�浽���ľ��룬pre�游��
int fa[MAX], dist[MAX], pre[MAX];
bool vis[MAX];

void AddEdge(int u, int v, int w)
{
    e[cnt].id = u;
    e[cnt].val = w;
    e[cnt].next = pre[v];
    pre[v] = cnt++;

    e[cnt].id = v;
    e[cnt].val = w;
    e[cnt].next = pre[u];
    pre[u] = cnt++;
}

int Find(int x)
{
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void tarjan(int k)
{
    vis[k] = true;
    fa[k] = k;
    for(int i = 1; i <= m; i++)
    {
        if(x[i] == k && vis[y[i]])
            z[i] = Find(y[i]);
        if(y[i] == k && vis[x[i]])
            z[i] = Find(x[i]);
    }
    for(int i = pre[k]; i != -1; i = e[i].next)
    {
        if(!vis[e[i].id])
        {
            dist[e[i].id] = dist[k] + e[i].val;
            tarjan(e[i].id);
            fa[e[i].id] = k;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int u, v, w;
        scanf("%d %d", &n, &m);
        cnt = 0;
        memset(pre, -1, sizeof(pre));
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            AddEdge(u, v, w);
        }
        for(int i = 1; i <= n; i++)
            x[i] = y[i] = z[i] = 0;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            x[i] = u;
            y[i] = v;
        }
        memset(vis, false, sizeof(vis));
        dist[1] = 0;
        tarjan(1);
        for(int i = 1; i <= m; i++)
            printf("%d\n",dist[x[i]] + dist[y[i]] - 2 * dist[z[i]]);
    }
}
