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
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 1e15+10;
const int mod = 1e9+7;
struct node
{
    int to,next;
}es[MAX_N*4];
int e,head[MAX_N],id,c[MAX_N];
int d[MAX_N];
int L[MAX_N],R[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
void dfs(int u,int fa)
{
    L[u] = ++id;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == fa) continue;
        dfs(v,u);
    }
    R[u] = id;
}
int lowbit(int x)
{
    return x&-x;
}
void update(int x,int val)
{
    while(x < MAX_N)
    {
        c[x]+=val;
        x+=lowbit(x);
    }
}
int getsum(int x)
{
    int sum = 0;
    while(x)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int N;
    scanf("%d",&N);
    int u,v;
    id = e = 0;
    memset(L,0,sizeof(L));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(R,0,sizeof(R));
    memset(head,-1,sizeof(head));
    for(int i = 0;i < N-1;i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,-1);
    for(int i = 1;i <= N;i++)
        update(i,1);
    int M;
    scanf("%d",&M);
    char op[5];
    int x;
    while(M--)
    {
        scanf("%s%d",op,&x);
        if(op[0] == 'C')
        {
            if(d[x])
                update(L[x],1);
            else
                update(L[x],-1);
            d[x]^=1;
        }
        else
        {
            printf("%d\n",getsum(R[x])-getsum(L[x]-1));
        }
    }
    return 0;
}
/*
*/
