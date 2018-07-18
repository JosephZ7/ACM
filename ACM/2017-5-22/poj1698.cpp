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
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const int mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int l,r;
    int sum,ad;
}tree[MAX_N<<2];
void PushDown(int id,int d)
{
    if(tree[id].ad!=0)
    {
        tree[id<<1].ad = tree[id].ad;
        tree[id<<1|1].ad = tree[id].ad;
        tree[id<<1].sum = (d-(d>>1))*tree[id].ad;
        tree[id<<1|1].sum = (d>>1)*tree[id].ad;
        tree[id].ad = 0;
    }
}
void build(int id,int l,int r)
{
    tree[id].ad = 0;
    tree[id].sum = 1;
    tree[id].l = l;
    tree[id].r = r;
    if(l == r)
        return ;

    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
int query(int id,int l,int r)
{
    if(l == r)
        return tree[id].sum;
    int mid = (l+r)/2;
    return query(id<<1,l,mid)+query(id<<1|1,mid+1,r);
}
void update(int id,int l,int r,int val)
{
    if(tree[id].l >= l&&tree[id].r <= r)
    {
        tree[id].ad = val;
        tree[id].sum = (tree[id].r-tree[id].l+1)*val;
        return ;
    }
    PushDown(id,tree[id].r-tree[id].l+1);
    int mid = (tree[id].l+tree[id].r)/2;
    if(l <= mid)
        update(id<<1,l,r,val);
    if(r > mid)
        update(id<<1|1,l,r,val);
    tree[id].sum = tree[id<<1].sum+tree[id<<1|1].sum;
}

int main()
{
    int n,q;
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%d",&q);
        int l,r,v;
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d%d",&l,&r,&v);
            update(1,l,r,v);
        }
        printf("Case %d: The total value of the hook is %d.\n",ti++,tree[1].sum);
    }

    return 0;
}

