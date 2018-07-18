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
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int l,r;
    int sum1,sum2,sum3;
    int cg,ad,mut;

}tree[MAX_N<<2];
void PushUp(int id)
{
    if(tree[id].l == tree[id].r)
        return ;
    tree[id].sum1 = (tree[id<<1].sum1+tree[id<<1|1].sum1)%mod;
    tree[id].sum2 = (tree[id<<1].sum2+tree[id<<1|1].sum2)%mod;
    tree[id].sum3 = (tree[id<<1].sum3+tree[id<<1|1].sum3)%mod;
}
void PushDown(int id)
{
    if(tree[id].l == tree[id].r)
        return ;
    if(tree[id].cg!=0)
    {
        tree[id<<1].cg = tree[id<<1|1].cg = tree[id].cg;
        tree[id<<1].ad = tree[id<<1|1].ad = 0;
        tree[id<<1].mut = tree[id<<1|1].mut = 1;
        tree[id<<1].sum1 = (tree[id<<1].r-tree[id<<1].l+1)*tree[id<<1].cg%mod;
        tree[id<<1].sum2 = (tree[id<<1].r-tree[id<<1].l+1)*tree[id<<1].cg%mod*tree[id<<1].cg%mod;
        tree[id<<1].sum3 = (tree[id<<1].r-tree[id<<1].l+1)*tree[id<<1].cg%mod*tree[id<<1].cg%mod*tree[id<<1].cg%mod;

        tree[id<<1|1].sum1 = (tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id<<1|1].cg%mod;
        tree[id<<1|1].sum2 = (tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id<<1|1].cg%mod*tree[id<<1|1].cg%mod;
        tree[id<<1|1].sum3 = (tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id<<1|1].cg%mod*tree[id<<1|1].cg%mod*tree[id<<1|1].cg%mod;

        tree[id].cg = 0;
    }
    if(tree[id].ad!=0||tree[id].mut!=1)
    {
        tree[id<<1].ad = (tree[id].mut*tree[id<<1].ad%mod+tree[id].ad)%mod;
        tree[id<<1].mut = tree[id<<1].mut*tree[id].mut%mod;
        int sum1,sum2,sum3;
        sum1 = (tree[id<<1].sum1*tree[id].mut%mod+(tree[id<<1].r-tree[id<<1].l+1)*tree[id].ad%mod)%mod;
        sum2 = (tree[id].mut*tree[id].mut%mod*tree[id<<1].sum2%mod+2*tree[id].ad*tree[id].mut%mod*tree[id<<1].sum1%mod
                +(tree[id<<1].r-tree[id<<1].l+1)*tree[id].ad%mod*tree[id].ad%mod)%mod;
        sum3 = tree[id].mut*tree[id].mut%mod*tree[id].mut%mod*tree[id<<1].sum3%mod;
        sum3 = (sum3+3*tree[id].mut%mod*tree[id].mut%mod*tree[id].ad%mod*tree[id<<1].sum2)%mod;
        sum3 = (sum3+3*tree[id].mut%mod*tree[id].ad%mod*tree[id].ad%mod*tree[id<<1].sum1)%mod;
        sum3 = (sum3+(tree[id<<1].r-tree[id<<1].l+1)*tree[id].ad%mod*tree[id].ad%mod*tree[id].ad%mod)%mod;
        tree[id<<1].sum1 = sum1;
        tree[id<<1].sum2 = sum2;
        tree[id<<1].sum3 = sum3;

        tree[id<<1|1].ad = (tree[id].mut*tree[id<<1|1].ad%mod+tree[id].ad)%mod;
        tree[id<<1|1].mut = tree[id<<1|1].mut*tree[id].mut%mod;
        sum1 = (tree[id<<1|1].sum1*tree[id].mut%mod+(tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id].ad%mod)%mod;
        sum2 = (tree[id].mut*tree[id].mut%mod*tree[id<<1|1].sum2%mod+2*tree[id].ad*tree[id].mut%mod*tree[id<<1|1].sum1%mod
                +(tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id].ad%mod*tree[id].ad%mod)%mod;
        sum3 = tree[id].mut*tree[id].mut%mod*tree[id].mut%mod*tree[id<<1|1].sum3%mod;
        sum3 = (sum3+3*tree[id].mut%mod*tree[id].mut%mod*tree[id].ad%mod*tree[id<<1|1].sum2)%mod;
        sum3 = (sum3+3*tree[id].mut%mod*tree[id].ad%mod*tree[id].ad%mod*tree[id<<1|1].sum1)%mod;
        sum3 = (sum3+(tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id].ad%mod*tree[id].ad%mod*tree[id].ad%mod)%mod;
        tree[id<<1|1].sum1 = sum1;
        tree[id<<1|1].sum2 = sum2;
        tree[id<<1|1].sum3 = sum3;
        tree[id].ad = 0;
        tree[id].mut = 1;
    }
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].cg  = tree[id].ad = 0;
    tree[id].mut = 1;
    tree[id].sum1 = tree[id].sum2 = tree[id].sum3 = 0;
    if(l == r)
        return ;
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
int query(int id,int l,int r,int q)
{
    if(tree[id].l == l &&tree[id].r == r)
    {
        if(q == 1)
            return tree[id].sum1;
        else if(q == 2)
            return tree[id].sum2;
        else
            return tree[id].sum3;
    }
    PushDown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    if(r <= mid)
        return query(id<<1,l,r,q);
    else if(l > mid)
        return query(id<<1|1,l,r,q);
    else
        return (query(id<<1,l,mid,q)+query(id<<1|1,mid+1,r,q))%mod;
}
void update(int op,int id,int l,int r,int c)
{
    if(tree[id].l == l&&tree[id].r == r)
    {
        c%=mod;
        if(op == 1)
        {
            tree[id].ad += c;
            tree[id].ad%=mod;
            tree[id].sum3 = (tree[id].sum3+3*tree[id].sum2%mod*c%mod+3*tree[id].sum1%mod*c%mod*c%mod
                             +(tree[id].r-tree[id].l+1)*c%mod*c%mod*c%mod)%mod;
            tree[id].sum2 = (tree[id].sum2+2*tree[id].sum1%mod*c%mod+(tree[id].r-tree[id].l+1)*c%mod*c%mod)%mod;
            tree[id].sum1 = (tree[id].sum1+(tree[id].r-tree[id].l+1)*c%mod)%mod;
        }
        else if(op == 2)
        {
            tree[id].ad = tree[id].ad*c%mod;
            tree[id].mut = tree[id].mut*c%mod;
            tree[id].sum1 = tree[id].sum1*c%mod;
            tree[id].sum2 = tree[id].sum2*c%mod*c%mod;
            tree[id].sum3 = tree[id].sum3*c%mod*c%mod*c%mod;
        }
        else
        {
            tree[id].ad = 0;
            tree[id].mut = 1;
            tree[id].cg = c%mod;
            tree[id].sum1 = (tree[id].r-tree[id].l+1)*c%mod;
            tree[id].sum2 = (tree[id].r-tree[id].l+1)*c%mod*c%mod;
            tree[id].sum3 = (tree[id].r-tree[id].l+1)*c%mod*c%mod*c%mod;
        }
        return ;
    }
    PushDown(id);
    int mid = (tree[id].l+tree[id].r)/2;
    if(r <= mid)
        update(op,id<<1,l,r,c);
    else if(l > mid)
        update(op,id<<1|1,l,r,c);
    else
    {
        update(op,id<<1,l,mid,c);
        update(op,id<<1|1,mid+1,r,c);
    }
    PushUp(id);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m) break;
        build(1,1,n);
        int op,x,y,c;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d%d",&op,&x,&y,&c);
            if(op == 4)
                printf("%d\n",query(1,x,y,c));
            else
                update(op,1,x,y,c);
        }
    }
    return 0;
}

