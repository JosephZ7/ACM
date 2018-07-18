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
LL a[MAX_N];
struct node
{
    int l,r;
    LL sum;
}tree[MAX_N<<2];

void PushUp(int id)
{
    tree[id].sum = tree[id<<1].sum+tree[id<<1|1].sum;
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    if(l == r)
    {
        tree[id].sum = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    PushUp(id);
}
LL query(int id,int l,int r)
{
    if(tree[id].l >= l&&tree[id].r <= r)
    {
        return tree[id].sum;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    LL ans = 0;
    if(l <= mid)
        ans+=query(id<<1,l,r);
    if(r > mid)
        ans+=query(id<<1|1,l,r);
    return ans;
}
void update(int id,int l,int r)
{
    if(tree[id].sum == tree[id].r-tree[id].l+1) return ;
    if(tree[id].l == tree[id].r)
    {
        tree[id].sum = sqrt(tree[id].sum);
        return ;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    if(l <= mid)
        update(id<<1,l,r);
    if(r > mid)
        update(id<<1|1,l,r);
    PushUp(id);
}
int main()
{
    int n,q,ti = 1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 1;i <= n;i++)
            scanf("%I64d",&a[i]);
        int T,l,r;
        build(1,1,n);
        scanf("%d",&q);
        printf("Case #%d:\n",ti++);
        while(q--)
        {
            scanf("%d%d%d",&T,&l,&r);
            if(l > r)
                swap(l,r);
            if(T == 0)
            {
                update(1,l,r);
            }
            else
            {
                printf("%I64d\n",query(1,l,r));
            }
        }
        printf("\n");
    }
    return 0;
}

