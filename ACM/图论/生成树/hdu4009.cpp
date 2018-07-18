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
const int MAX_N = 1e3+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
struct Point
{
    int x,y,z;
}a[MAX_N];

struct edge
{
    int u,v;
    int val;
}es[MAX_N*MAX_N*5];
int in[MAX_N];
int col[MAX_N],pre[MAX_N],ID[MAX_N];
int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -x;
}
int Manhattan(Point e1,Point e2)
{
    return (abs(e1.x-e2.x)+abs(e1.y-e2.y)+abs(e1.z-e2.z));
}
int ZL_Mst(int root,int n,int m)
{
    int sum = 0;
    while(1)
    {
        for(int i = 0;i < n;i++) in[i] = INF;
        for(int i = 0;i < m;i++)
        {
            int u = es[i].u;
            int v = es[i].v;
            if(u!=v&&es[i].val < in[v])
            {
                in[v] = es[i].val;
                pre[v] = u;
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(i!=root&&in[i] == INF)
                return -1;
        }
        memset(col,-1,sizeof(col));
        memset(ID,-1,sizeof(ID));
        in[root] = 0;
        int tn = 0;
        for(int i = 0;i < n;i++)
        {
            sum+=in[i];
            int v = i;
            while(v!=root&&col[v] != i&&ID[v] == -1)
            {
                col[v] = i;
                v = pre[v];
            }
            if(v!=root&&ID[v] == -1)
            {
                for(int u = pre[v];u!=v;u = pre[u])
                    ID[u] = tn;
                ID[v] = tn++;
            }
        }
        if(tn == 0) break;
        for(int i = 0;i < n;i++)
            if(ID[i] == -1)
                ID[i] = tn++;
        for(int i = 0;i < m;i++)
        {
            int u = es[i].u;
            int v = es[i].v;
            es[i].u = ID[u];
            es[i].v = ID[v];
            if(ID[u]!=ID[v]) es[i].val -=in[v];
        }
        n = tn;
        root = ID[root];
    }
    return sum;
}
int n,k;
int main()
{
    int X,Y,Z;
    while(scanf("%d%d%d%d",&n,&X,&Y,&Z),n,X,Y,Z)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        }
        int num,x;
        k = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num);
            for(int j = 0;j < num;j++)
            {
                scanf("%d",&x);
                es[k].u = i;
                es[k].v = x-1;
                es[k].val = Y*Manhattan(a[i],a[x-1]);
                if(a[i].z < a[x-1].z)
                    es[k].val+=Z;
                k++;
            }
        }
        for(int i = 0;i < n;i++)
        {
            es[k].u = n;
            es[k].v = i;
            es[k++].val = a[i].z*X;
        }
        int ans = ZL_Mst(n,n+1,k);
        if(ans == -1)
            printf("poor XiaoA\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
