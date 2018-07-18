
//dijkstra
#define INF 0x3f3f3f3f
const int MAX_N = 200;
int Edge[MAX_N][MAX_N];         //邻接矩阵
int n;
int vis[MAX_N];        //标记已被加入集合的点
int d[MAX_N];              //源点到其他点的最短路径
void dijkstra(int s)
{
    fill(d,d+N,INF);
    fill(vis,vis+N,0);
    d[s] = 0;
    vis[s] = 1;
    int Mi,u = s;
    for(int i = 0;i < n-1;i++)
    {
        Mi = INF;
        for(int v = 1;v <= n;v++)
        {
            if(!vis[v]&&d[v] < Mi)
            {
                u = v;
                Mi = d[v];
            }
        }
        vis[u] = 1;
        for(int k = 1;k <= n;k++)
            d[k] = min(d[k],d[u]+Edge[u][k]);
    }
}
//dijkstra堆优化
void Dijkstra()
{
    priority_queue<int,vector<int>,cmp> Q;
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int i,u,v;
    Q.push(st);
    dis[st]=0;
    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();
        vis[u]=0;
        if(u==ed)
            break;
        for(i=0;i<edge[u].size();i++)
        {
            v=edge[u][i].v;
            if(dis[v]==-1 || dis[v]>dis[u]+edge[u][i].w)
            {
                dis[v]=dis[u]+edge[u][i].w;
                if(!vis[v])
                {
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
//Floyd

int d[1000][1000];  //表示两点之间边的权值，不存在就设置为INF
void Floyd()
{
    for(int k = 0;k < N;k++)
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}


//SPFA
int spfa_bfs(int s)
{
    queue <int> q;
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    memset(c,0,sizeof(c));
    memset(vis,0,sizeof(vis));

    q.push(s);  vis[s]=1; c[s]=1;
    //顶点入队vis要做标记，另外要统计顶点的入队次数
    int OK=1;
    while(!q.empty())
    {
        int x;
        x=q.front(); q.pop();  vis[x]=0;
        //队头元素出队，并且消除标记
        for(int k = f[x]; k!=0; k = next[k]) //遍历顶点x的邻接表
        {
            int y=v[k];
            if( d[x]+w[k] < d[y])
            {
                d[y]=d[x]+w[k];  //松弛
                if(!vis[y])  //顶点y不在队内
                {
                    vis[y]=1;    //标记
                    c[y]++;      //统计次数
                    q.push(y);   //入队
                    if(c[y] > N)  //超过入队次数上限，说明有负环
                        return OK=0;
                }
            }
        }
    }
    return OK;
}

int spfa_dfs(int u)
{
    vis[u]=1;
    for(int k=f[u]; k!=0; k=e[k].next)
    {
        int v=e[k].v,w=e[k].w;
        if( d[u]+w < d[v] )
        {
            d[v]=d[u]+w;
            if(!vis[v])
            {
                if(spfa_dfs(v))
                    return 1;
            }
            else
                return 1;
        }
    }
    vis[u]=0;
    return 0;
}
