#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#define LL long long
#define PLL pair<LL,int>
using namespace std;
const int MAX_N = 2e6+10;
const LL inf = 1e17+10;
struct node
{
    int to,next;
    int w;
}es[MAX_N];
int e,head[MAX_N];
void addedge(int u,int v,int t)
{
    es[e].to = v;
    es[e].w = t;
    es[e].next = head[u];
    head[u] = e++;
}
int n,m;
void dijkstra(int s,LL d[])
{
    priority_queue<PLL,vector<PLL>,greater<PLL> > q;
    for(int i = 0;i < MAX_N;i++)
        d[i] = 1e18;
    d[s] = 0;
    q.push(PLL{d[s],s});
    while(!q.empty())
    {
        int u = q.top().second; q.pop();
        if(d[u] > q.top().first) continue;
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            int v = es[i].to;
            int w = es[i].w;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                q.push(PLL{d[v],v});
            }
        }
    }
}
void init()
{
    e = 0; memset(head,-1,sizeof(head));
}
int a[MAX_N];
LL d1[MAX_N],d2[MAX_N];
int b[MAX_N];
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        LL t;
        int num,x;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&t,&num);
            for(int j = 0;j < num;j++)
            {
                scanf("%d",&x);
                addedge(n+i,x,t);
                addedge(x,n+i,0);
            }
        }
        dijkstra(1,d1);
        dijkstra(n,d2);
        LL Mi = 1e18;
        for(int i = 1;i <= n;i++)
            Mi = min(Mi,max(d1[i],d2[i]));
        printf("Case #%d: ",ti++);
        if(Mi == 1e18)
        {
            printf("Evil John\n");
        }
        else
        {
            int k = 0;
            printf("%I64d\n",Mi);
            for(int i = 1;i <= n;i++)
            {
                if(max(d1[i],d2[i]) == Mi)
                    b[k++] = i;
            }
            for(int i = 0;i < k;i++)
            {
                if(i == k-1)
                    printf("%d\n",b[i]);
                else
                    printf("%d ",b[i]);
            }
        }
    }
    return 0;
}
/*
*/
