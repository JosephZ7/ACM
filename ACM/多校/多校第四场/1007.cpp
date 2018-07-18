#include <stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#define LL long long
const int mod = 998244353;
const int MAX_N = 3e5+10;
using namespace std;
struct node
{
    int to,next,w;
}es[MAX_N<<2];
int e,head[MAX_N<<2],deg[MAX_N<<1],q[MAX_N<<1],vis[MAX_N<<1];
void addedge(int u,int v,int w)
{
    deg[u]++; deg[v]++;
    es[e].to = v; es[e].w = w; es[e].next = head[u]; head[u] = e++;
    es[e].to = u; es[e].w = w; es[e].next = head[v]; head[v] = e++;
}
int change(int u)
{
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(!vis[v])
            return v;
    }
    return 0;
}
int getw(int u,int v)
{
    for(int i = head[u];i!=-1;i = es[i].next)
        if(es[i].to == v)
            return es[i].w;
}
void init(int n)
{
    e = 0;
    memset(deg,0,sizeof(deg));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int f = 1,t = 0,n;
        int ans = 1;
        scanf("%d",&n);
        init(n);
        int v1,w1,v2,w2,u,v;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d%d",&v1,&w1,&v2,&w2);
            addedge(i,v1+n,w1);
            addedge(i,v2+n,w2);
        }
        n<<=1;
        for(int i = 1;i <= n;i++)
            if(deg[i] == 1)
                q[++t] = i;
        while(f <= t)
        {
            u = q[f++];
            for(int i = head[u];i!=-1;i = es[i].next)
            {
                if(!vis[es[i].to])
                {
                    v = es[i].to;
                    ans = 1LL*ans*es[i].w%mod;
                    break;
                }
            }
            vis[u] = vis[v] = 1;
            for(int i = head[v];i!=-1;i = es[i].next)
            {
                u = es[i].to;
                if(!vis[u])
                {
                    deg[u]--;
                    if(deg[u] == 1) q[++t] = u;
                }
            }
        }
        int t1,t2;
        for(int i = 1;i <= n;i++)
            if(!vis[i])
            {
                vis[q[t = 1] = i] = 1;
                for(int j = change(i);j;j = change(j))
                    vis[q[++t] = j] = 1;
                //cout<<1<<endl;
                q[t+1] = q[1];
                t1 = t2 = 1;
                //for(int i = 1;i <= t+1;i++)
                    //printf("%d\n",q[i]);
                for(int j = 1;j <= t;j+=2) t1 = 1LL*t1*getw(q[j],q[j+1])%mod;
                for(int j = 2;j <= t;j+=2) t2 = 1LL*t2*getw(q[j],q[j+1])%mod;
                //cout<<t1<<" "<<t2<<endl;
                ans = 1LL*ans*(t1+t2)%mod;
            }
        printf("%d\n",ans);
    }
    return 0;
}
