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
int a[MAX_N];
struct node
{
    int l,r;
    int mi,ma,ca;
}tree[MAX_N<<2];
/*
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
}*/
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    if(l == r)
    {
        tree[id].mi = tree[id].ma = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    tree[id].mi = min(tree[id<<1].mi,tree[id<<1|1].mi);
    tree[id].ma = max(tree[id<<1].ma,tree[id<<1|1].ma);

}
int Ma,Mi;
void query(int id,int l,int r)
{
    if(tree[id].l >= l&&tree[id].r <= r)
    {
        Ma = max(Ma,tree[id].ma);
        Mi = min(Mi,tree[id].mi);
        return ;
    }
    int mid = (tree[id].l+tree[id].r)/2;
    if(r <= mid)
        query(id<<1,l,r);
    else if(l > mid)
        query(id<<1|1,l,r);
    else
    {
        query(id<<1,l,mid);
        query(id<<1|1,mid+1,r);
    }
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    int l,r;
    build(1,1,n);
    while(q--)
    {
        Ma = -1,Mi = INF;
        scanf("%d%d",&l,&r);
        query(1,l,r);
        printf("%d\n",Ma-Mi);
    }

    return 0;
}

