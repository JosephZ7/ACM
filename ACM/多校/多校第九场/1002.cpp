#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAX_N = 1e5+1000;
const LL inf = 1e15+10;
const int mod = 1e9+7;

struct node
{
    int to,next;
}es[MAX_N*4];
int e,head[MAX_N],id;
int siz[MAX_N],top[MAX_N],son[MAX_N],dep[MAX_N];
int fa[MAX_N],tid[MAX_N];
LL val[MAX_N],f[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int n,m;
void dfs1(int u,int father,int d)
{
    dep[u] = d;
    fa[u] = father;
    siz[u] = 1;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == father) continue;
        dfs1(v,u,d+1);
        siz[u]+=siz[v];
        if(son[u] == -1||siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u,int tp)
{
    top[u] = tp;
    tid[u] = ++id;
    if(son[u] != -1) dfs2(son[u],tp);
    for(int i = head[u];i!= -1;i = es[i].next)
    {
        int v = es[i].to;
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}
struct Tree
{
    int l,r;
    LL sum,ma,mi;
}tree[MAX_N<<2];
void PushUp(int id)
{
    tree[id].sum = tree[id<<1].sum+tree[id<<1|1].sum;
    tree[id].ma = max(tree[id<<1].ma,tree[id<<1|1].ma);
    tree[id].mi = min(tree[id<<1].mi,tree[id<<1|1].mi);
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].sum = tree[id].ma = tree[id].mi = 0;
    if(l == r)
    {
        tree[id].mi = tree[id].ma = tree[id].sum = f[l];
        return ;
    }
    int mid = l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    PushUp(id);
}
LL query(int id,int L,int R,LL a,LL b)
{
    if(L <= tree[id].l&&tree[id].r <= R)
    {
        if(tree[id].ma < a||tree[id].mi > b) return 0;
        else if(tree[id].ma <= b&&tree[id].mi >= a) return tree[id].sum;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    LL ans = 0;
    if(L <= mid)
        ans+= query(id<<1,L,R,a,b);
    if(R > mid)
        ans+= query(id<<1|1,L,R,a,b);
    return ans;
}
LL getans(int x,int y,LL a,LL b)
{
    LL ans = 0;
    int tx = top[x],ty = top[y];
    while(tx!=ty)
    {
        if(dep[tx] < dep[ty])
        {
            swap(tx,ty);
            swap(x,y);
        }
        ans+=query(1,tid[tx],tid[x],a,b);
        x = fa[tx];
        tx = top[x];
    }
    if(x == y)
    {
        if(val[x] <=b&&val[x] >= a) ans+=val[x];
        return ans;
    }
    if(dep[x] > dep[y]) swap(x,y);
    ans+=query(1,tid[x],tid[y],a,b);
    return ans;
}
void init()
{
    e = id = 0;
    memset(head,-1,sizeof(head));
    memset(tid,0,sizeof(tid));
    memset(son,-1,sizeof(son));
}
LL ans[MAX_N];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i = 1;i <= n;i++)
            scanf("%lld",&val[i]);
        int u,v;
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,-1,1);
        dfs2(1,1);
        for(int i = 1;i <= n;i++)
            f[tid[i]] = val[i];
        build(1,1,n);
        LL a,b;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%lld%lld",&u,&v,&a,&b);
            ans[i] = getans(u,v,a,b);
        }

        for(int i = 0;i < m;i++)
            printf(i == m-1?"%lld\n":"%lld ",ans[i]);
    }

    return 0;
}
/*
*/
