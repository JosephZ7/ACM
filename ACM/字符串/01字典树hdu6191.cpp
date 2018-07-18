#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const double eps = 1e-15;
const int MAX_N = 1e5+10;
const LL mod = 1000000007;
struct node
{
    int to,next;
}es[MAX_N*4];
int L[MAX_N],R[MAX_N],id,e,head[MAX_N],a[MAX_N];
int ch[MAX_N<<5][2],sz,sum[MAX_N<<5],rk[MAX_N],root[MAX_N];
int Insert(int u,int val)
{
    int y = ++sz,x = u;
    int ans = y;
    for(int i = 30;i >= 0;i--)
    {
        sum[y] = sum[x]+1;
        ch[y][0] = ch[x][0];
        ch[y][1] = ch[x][1];
        int t = (val>>i)&1;
        ch[y][t] = ++sz;
        x = ch[x][t];
        y = ch[y][t];
    }
    sum[y] = sum[x]+1;
    return ans;
}
int query(int l,int r,int val)
{
    int ans = 0;
    for(int i = 30;i >= 0;i--)
    {
        int t = (val>>i)&1;
        if(sum[ch[r][t^1]]-sum[ch[l][t^1]])
        {
            r = ch[r][t^1];
            l = ch[l][t^1];
            ans+=(1<<i);
        }
        else
        {
            r = ch[r][t];
            l = ch[l][t];
        }
    }
    return ans;
}
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
void dfs(int u,int fa)
{
    L[u] = ++id;
    rk[id] = u;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == fa) continue;
        dfs(v,u);
    }
    R[u] = id;
}
void init()
{
    e = id = 0;
    memset(head,-1,sizeof(head));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    sz = 1;
    memset(ch,0,sizeof(ch));
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        init();
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        int v;
        for(int i = 1;i <= n-1;i++)
        {
            scanf("%d",&v);
            addedge(v,i+1);
            addedge(i+1,v);
        }
        dfs(1,-1);
        for(int i = 1;i <= n;i++)
            root[i] = Insert(root[i-1],a[rk[i]]);
        int u,x;
        while(q--)
        {
            scanf("%d%d",&u,&x);
            printf("%d\n",query(root[L[u]-1],root[R[u]],x));
        }
    }
    return 0;
}
