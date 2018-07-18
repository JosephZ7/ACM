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
    int sum;
}tree[MAX_N*4];
int ans,vis[MAX_N];
void PushDown(int id)
{
    if(tree[id].sum == -1) return ;
    tree[id<<1].sum = tree[id<<1|1].sum = tree[id].sum;
    tree[id].sum = -1;
}
void build(int id,int l,int r)
{
    tree[id].sum = -1;
    tree[id].l = l;
    tree[id].r = r;
    if(l == r)
        return ;

    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
void query(int l,int r,int id)
{
    if(tree[id].sum!=-1)
    {
        if(!vis[tree[id].sum]) ans++;
        vis[tree[id].sum] = 1;
        return ;
    }
    if(l == r) return ;
    int mid = (l+r)/2;
    query(l,mid,id<<1);
    query(mid+1,r,id<<1|1);
}
void update(int id,int l,int r,int val)
{
    if(tree[id].l >= l&&tree[id].r <= r)
    {
        tree[id].sum = val;
        return ;
    }
    PushDown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    if(l <= mid)
        update(id<<1,l,r,val);
    if(r > mid)
        update(id<<1|1,l,r,val);
}
int x[MAX_N],y[MAX_N],f[MAX_N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        int k = 0;
        for(int i = 1;i <= N;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            f[k++] = x[i];
            f[k++] = y[i];
        }
        sort(f,f+k);
        int m = 1;
        for(int i = 1;i < k;i++)
            if(f[i]!=f[i-1])
                f[m++] = f[i];
        for(int i = m-1;i >= 1;i--)
            if(f[i]!=f[i-1]+1)
                f[m++] = f[i-1]+1;
        sort(f,f+m);
        build(1,1,m);
        for(int i = 1;i <= N;i++)
        {
            int l = lower_bound(f,f+m,x[i])-f;
            int r = lower_bound(f,f+m,y[i])-f;
            update(1,l+1,r+1,i);
        }
        memset(vis,0,sizeof(vis));
        ans = 0;
        query(1,m,1);
        printf("%d\n",ans);
    }
    return 0;
}

