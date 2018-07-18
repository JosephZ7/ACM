#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-7;
const int mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int l,r;
    int sum,ad;
}tree[MAX_N<<2];
int e,head[MAX_N],cnt,vis[MAX_N];
int st[MAX_N],ed[MAX_N];
struct edge
{
    int to,next;
}es[MAX_N];
void add(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
void dfs(int u)
{
    st[u] = ++cnt;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        dfs(es[i].to);
    }
    ed[u] = cnt;
}
void PushDown(int id)
{
    if(tree[id].ad)
    {
        tree[id<<1].ad = 1;
        tree[id<<1|1].ad = 1;
        tree[id<<1].sum = tree[id].sum;
        tree[id<<1|1].sum = tree[id].sum;
        tree[id].ad = 0;
    }
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].sum = -1;
    tree[id].ad = 0;
    if(l == r)
        return ;
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
int query(int id,int x)
{
    if(tree[id].l == x&&tree[id].r == x)
    {
        return tree[id].sum;
    }
    PushDown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    if(x <= mid)
        return query(id<<1,x);
    else
        return query(id<<1|1,x);
}
void update(int id,int l,int r,int val)
{
    if(tree[id].l == l&&tree[id].r == r)
    {
        tree[id].ad = 1;
        tree[id].sum = val;
        return ;
    }
    PushDown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    if(r <= mid)
        update(id<<1,l,r,val);
    else if(l > mid)
        update(id<<1|1,l,r,val);
    else
    {
        update(id<<1,l,mid,val);
        update(id<<1|1,mid+1,r,val);
    }
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        e = 0;
        cnt = 0;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        int n;
        scanf("%d",&n);
        int u,v;
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            vis[u] = 1;
            add(v,u);
        }
        for(int i = 1;i <= n;i++)
            if(!vis[i])
            {
                dfs(i);
                break;
            }
        build(1,1,cnt);
        int m,x,y;
        char op[4];
        scanf("%d",&m);
        printf("Case #%d:\n",ti++);
        for(int i = 0;i < m;i++)
        {
            scanf("%s%d",op,&x);
            if(op[0] == 'C')
            {
                printf("%d\n",query(1,st[x]));
            }
            else
            {
                scanf("%d",&y);
                update(1,st[x],ed[x],y);
            }
        }
    }
    return 0;
}

