#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAX_N = 2e5+10;
const LL inf = 1e15+10;
const int mod = 1e9+7;
struct node
{
    int to,next;
}es[MAX_N*4];
int e,head[MAX_N],val[MAX_N],id,L[MAX_N],R[MAX_N];
int siz[MAX_N],top[MAX_N],son[MAX_N],dep[MAX_N];
int fa[MAX_N],tid[MAX_N],rk[MAX_N];
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
    L[u] = tid[u] = ++id;
    rk[tid[u]] = u;
    if(son[u] != -1) dfs2(son[u],tp);
    for(int i = head[u];i!= -1;i = es[i].next)
    {
        int v = es[i].to;
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
    R[u] = id;
}
struct Tree
{
    int l,r;
    LL sum,lz;
}tree[MAX_N<<2];
void Pushdown(int id)
{
    if(tree[id].lz)
    {
        tree[id<<1].lz+=tree[id].lz;
        tree[id<<1].sum+=(tree[id<<1].r-tree[id<<1].l+1)*tree[id].lz;
        tree[id<<1|1].lz+=tree[id].lz;
        tree[id<<1|1].sum+=(tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id].lz;
        tree[id].lz = 0;
    }
}
void PushUp(int id)
{
    tree[id].sum = tree[id<<1].sum+tree[id<<1|1].sum;
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].sum = 0;
    tree[id].lz = 0;
    if(l == r)
    {
        tree[id].sum = (LL)val[rk[l]];
        //cout<<tree[id].sum<<endl;
        return ;
    }
    int mid = l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    PushUp(id);
}
void update(int id,int L,int R,LL val)
{
    if(L <= tree[id].l&&tree[id].r <= R)
    {
        tree[id].lz+=val;
        tree[id].sum+=(LL)(tree[id].r-tree[id].l+1)*val;
        return ;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    Pushdown(id);
    if(L <= mid)
        update(id<<1,L,R,val);
    if(R > mid)
        update(id<<1|1,L,R,val);
    PushUp(id);
}
LL query(int id,int L,int R)
{
    if(L <= tree[id].l&&tree[id].r <= R)
        return tree[id].sum;
    Pushdown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    LL ans = 0;
    if(L <= mid)
        ans+= query(id<<1,L,R);
    if(R > mid)
        ans+= query(id<<1|1,L,R);
    PushUp(id);
    return ans;
}
LL getans(int x,int y)
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
        ans+=query(1,tid[tx],tid[x]);
        x = fa[tx];
        tx = top[x];
    }
    if(dep[x] > dep[y]) swap(x,y);
    ans+=query(1,tid[x],tid[y]);
    return ans;
}
void init()
{
    e = id = 0;
    memset(head,-1,sizeof(head));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    memset(tid,0,sizeof(tid));
    memset(rk,0,sizeof(rk));
    memset(son,-1,sizeof(son));
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%d",&val[i]);
    int u,v;
    for(int i = 0;i < n-1;i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    build(1,1,n);
    for(int i = 0;i < m;i++)
    {
        int op,x;
        LL y;
        scanf("%d%d",&op,&x);
        if(op == 1)
        {
            scanf("%lld",&y);
            update(1,tid[x],tid[x],y);
        }
        else if(op == 2)
        {
            scanf("%lld",&y);
            update(1,L[x],R[x],y);
        }
        else
        {
            printf("%lld\n",getans(1,x));
        }
    }
    return 0;
}
/*
*/
