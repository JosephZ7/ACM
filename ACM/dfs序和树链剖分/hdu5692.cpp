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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 1e15+10;
const int mod = 1e9+7;
struct node
{
    int to,next;
}es[MAX_N*4];
int e,head[MAX_N],val[MAX_N],idx[MAX_N];
LL dis[MAX_N];
int L[MAX_N],R[MAX_N],id;
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int n,m;
void dfs(int u,int fa)
{
    L[u] = ++id;
    idx[id] = u;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == fa) continue;
        dis[v] = dis[u]+val[v];
        dfs(v,u);
    }
    R[u] = id;
}
struct Tree
{
    int l,r;
    LL sum,Ma,lz;
}tree[MAX_N<<2];
void Pushdown(int id)
{
    if(tree[id].lz)
    {
        tree[id<<1].lz+=tree[id].lz;
        tree[id<<1].sum+=(tree[id].r-tree[id].l+1)*tree[id].lz;
        tree[id<<1].Ma+=tree[id].lz;
        tree[id<<1|1].lz+=tree[id].lz;
        tree[id<<1|1].sum+=(tree[id].r-tree[id].l+1)*tree[id].lz;
        tree[id<<1|1].Ma+=tree[id].lz;
        tree[id].lz = 0;
    }
}
void PushUp(int id)
{
    tree[id].sum = tree[id<<1].sum+tree[id<<1|1].sum;
    tree[id].Ma = max(tree[id<<1].Ma,tree[id<<1|1].Ma);
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].sum = 0;
    tree[id].Ma = 0;
    tree[id].lz = 0;
    if(l == r)
    {
        tree[id].sum = tree[id].Ma = dis[idx[l]];
        //cout<<tree[id].sum<<endl;
        return ;
    }
    int mid = l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    PushUp(id);
}

void update(int id,int L,int R,int val)
{
    if(L <= tree[id].l&&tree[id].r <= R)
    {
        tree[id].lz+=val;
        tree[id].sum+=(tree[id].r-tree[id].l+1)*(LL)val;
        tree[id].Ma+=val;
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
        return tree[id].Ma;
    Pushdown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    LL q1 = -inf,q2 = -inf;
    if(L <= mid)
        q1 = query(id<<1,L,R);
    if(R > mid)
        q2 = query(id<<1|1,L,R);
    PushUp(id);
    return max(q1,q2);
}
void init()
{
    e = id = 0;
    memset(head,-1,sizeof(head));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    memset(idx,0,sizeof(idx));
    memset(dis,0,sizeof(dis));
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        int u,v;
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        for(int i = 0;i < n;i++)
            scanf("%d",&val[i]);
        dis[0] = val[0];
        dfs(0,-1);
        build(1,1,n);
        printf("Case #%d:\n",ti++);
        for(int i = 0;i < m;i++)
        {
            int op,x,y;
            scanf("%d%d",&op,&x);
            if(op == 1)
            {
                printf("%I64d\n",query(1,L[x],R[x]));
            }
            else
            {
                scanf("%d",&y);
                update(1,L[x],R[x],y-val[x]);
                val[x] = y;
            }
        }
    }
    return 0;
}
/*
*/
