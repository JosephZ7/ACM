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
int a[MAX_N];
struct node
{
    int l,r;
    int ls,rs,ms;
}tree[MAX_N<<2];
int des[MAX_N],top;
void build(int id,int l,int r)
{
    tree[id].ls = tree[id].rs = tree[id].ms = r-l+1;
    tree[id].l = l;
    tree[id].r = r;
    if(l == r)
        return ;
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
int query(int id,int x)
{
    if(tree[id].l == tree[id].r||tree[id].ms == 0||tree[id].ms == tree[id].r-tree[id].l+1)
    {
        return tree[id].ms;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    if(x <= mid)
    {
        if(x >= tree[id<<1].r-tree[id<<1].rs+1)
            return query(id<<1,x)+query(id<<1|1,mid+1);
        else
            return query(id<<1,x);
    }
    else
    {
        if(x <= tree[id<<1|1].l+tree[id<<1|1].ls-1)
            return query(id<<1|1,x)+query(id<<1,mid);
        else
            return query(id<<1|1,x);
    }
}
void update(int id,int val,int o)
{
    if(tree[id].l == tree[id].r)
    {
        if(o < 0)
            tree[id].ls = tree[id].rs = tree[id].ms = 0;
        else
            tree[id].ls = tree[id].rs = tree[id].ms = 1;
        return ;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    if(val <= mid)
        update(id<<1,val,o);
    else
        update(id<<1|1,val,o);
    tree[id].ls = tree[id<<1].ls;
    tree[id].rs = tree[id<<1|1].rs;
    tree[id].ms = max(max(tree[id<<1].ms,tree[id<<1|1].ms),tree[id<<1].rs+tree[id<<1|1].ls);
    if(tree[id<<1].ls == tree[id<<1].r-tree[id<<1].l+1)
        tree[id].ls+=tree[id<<1|1].ls;
    if(tree[id<<1|1].rs == tree[id<<1|1].r-tree[id<<1|1].l+1)
        tree[id].rs+=tree[id<<1].rs;
}
int main()
{
    char op[10];
    int n,m,x;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top = 0;
        build(1,1,n);
        for(int i = 0;i < m;i++)
        {
            scanf("%s",op);
            if(op[0] == 'D')
            {
                scanf("%d",&x);
                des[top++] = x;
                update(1,x,-1);
            }
            else if(op[0] == 'Q')
            {
                scanf("%d",&x);
                printf("%d\n",query(1,x));
            }
            else
            {
                if(top > 0)
                {
                    x = des[--top];
                    update(1,x,1);
                }
            }
        }
    }
    return 0;
}

