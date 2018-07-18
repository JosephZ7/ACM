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
int fa[MAX_N],tid[MAX_N],root[MAX_N],tn;
LL val[MAX_N],f[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int n,m;
struct Tree
{
    int l,r;
    LL sum;
}tree[MAX_N*20];
int ct;
void build(int &id,int l,int r)
{
    tree[++ct] = tree[id]; id = ct;
    tree[id].sum = 0;
    if(l >= r) return ;
    int mid = ((r-l)>>1)+l;
    build(tree[id].l,l,mid);
    build(tree[id].r,mid+1,r);
}
void update(int &id,int l,int r,int pos)
{
    tree[++ct] = tree[id]; id = ct;
    tree[id].sum+=f[pos];
    if(l >= r) return ;
    int mid = ((r-l)>>1)+l;
    if(pos <= mid)
        update(tree[id].l,l,mid,pos);
    else
        update(tree[id].r,mid+1,r,pos);
}
LL query(int id,int L,int R,int l,int r)
{
    if(L <= l&&r <= R)
        return tree[id].sum;
    int mid = (l+r)/2;
    LL ans = 0;
    if(L <= mid)
        ans+= query(tree[id].l,L,R,l,mid);
    if(R > mid)
        ans+= query(tree[id].r,L,R,mid+1,r);
    return ans;
}
int LCA(int x,int y)
{
    int tx = top[x],ty = top[y];
    while(tx!=ty)
    {
        if(dep[tx] < dep[ty])
        {
            swap(tx,ty);
            swap(x,y);
        }
        x = fa[tx];
        tx = top[x];
    }
    if(dep[x] > dep[y]) swap(x,y);
    return x;
}
void dfs1(int u,int f,int d)
{
    dep[u] = d; fa[u] = f; siz[u] = 1;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == f) continue;
        dfs1(v,u,d+1);
        siz[u]+=siz[v];
        if(siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u,int tp)
{
    top[u] = tp; tid[u] = ++id;
    update(root[u] = root[fa[u]],1,tn,val[u]);
    if(!son[u]) return ;
    for(int i = head[u];i!= -1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == fa[u]) continue;
        dfs2(v,v);
    }
}
void init()
{
    e = ct = 0;
    memset(head,-1,sizeof(head));
    memset(tid,0,sizeof(tid));
    memset(son,0,sizeof(son));
    memset(fa,0,sizeof(fa));
}
LL ans[MAX_N];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&val[i]);
            f[i] = val[i];
        }
        int u,v;
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        fa[1] = 0;
        sort(f+1,f+n+1);
        tn = unique(f+1,f+n+1)-(f+1);
        for(int i = 1;i <= n;i++)
            val[i] = lower_bound(f+1,f+tn+1,val[i])-f;
        build(root[0],1,tn);
        dfs1(1,0,1);
        dfs2(1,1);
        int a,b;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            int l = lower_bound(f+1,f+tn+1,a)-f;
            int r = lower_bound(f+1,f+tn+1,b)-f;
            if(f[r] > b) r--;
            if(l == 0&&r == 0)
            {
                ans[i] = 0;
                continue;
            }
            int lca = LCA(u,v);
            ans[i] = query(root[u],l,r,1,tn)+query(root[v],l,r,1,tn)
                    -query(root[lca],l,r,1,tn)-query(root[fa[lca]],l,r,1,tn);
        }
        for(int i = 0;i < m;i++)
            printf(i == m-1?"%lld\n":"%lld ",ans[i]);
    }

    return 0;
}
/*
*/
