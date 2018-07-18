#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define lson l, m
#define rson m+1, r
const int N=1e5+5;
int L[N<<5], R[N<<5], sum[N<<5];
int tot;
int a[N], T[N], Hash[N];
int build(int l, int r)
{
    int rt=(++tot);
    sum[rt]=0;
    if(l<r)
    {
        int m=(l+r)>>1;
        L[rt]=build(lson);
        R[rt]=build(rson);
    }
    return rt;
}

int update(int pre, int l, int r, int x)
{
    int rt=(++tot);
    L[rt]=L[pre], R[rt]=R[pre], sum[rt]=sum[pre]+1;
    if(l<r)
    {
        int m=(l+r)>>1;
        if(x<=m)
            L[rt]=update(L[pre], lson, x);
        else
            R[rt]=update(R[pre], rson, x);
    }
    return rt;
}

int query(int u, int v, int l, int r, int k)
{
    if(l>=r)
        return l;
    int m=(l+r)>>1;
    int num=sum[L[v]]-sum[L[u]];
    if(num>=k)
        return query(L[u], L[v], lson, k);
    else
        return query(R[u], R[v], rson, k-num);
}

int main()
{
    tot=0;
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        Hash[i]=a[i];
    }
    sort(Hash+1, Hash+n+1);
    int d=unique(Hash+1, Hash+n+1)-Hash-1;
    T[0]=build(1, d);
    //printf("d = %d\n",d);
    for(int i=1; i<=n; i++)
    {
        int x=lower_bound(Hash+1, Hash+d+1, a[i])-Hash;
        //printf("x = %d\n",x);
        T[i]=update(T[i-1], 1, d, x);
        //printf("T[%d] = %d\n",i,T[i]);
    }
    while(m--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int x=query(T[l-1], T[r], 1, d, k);
        cout<<x<<endl;
        printf("%d\n", Hash[x]);
    }
}
