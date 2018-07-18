#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-7;
const LL mod = 999999997;
const LL inf = 1LL<<60;
using namespace std;
struct DLX
{
    int L[MAX_N],R[MAX_N],U[MAX_N],D[MAX_N];
    int Row[MAX_N],Col[MAX_N];
    int h[MAX_N],s[MAX_N];
    int sz,ans;
    void init(int m)
    {
        for(int i = 0;i <= m;i++)
        {
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
            s[i] = 0;
        }
        L[0] = m;
        R[m] = 0;
        memset(h,-1,sizeof(h));
        sz = m;
        ans = INF;
    }
    void link(int r,int c)
    {
        sz++;
        Col[sz] = c;
        Row[sz] = r;
        s[c]++;
        U[sz] = U[c];
        D[sz] = c;
        D[U[c]] = sz;
        U[c] = sz;
        if(h[r] < 0)
            h[r] = L[sz] = R[sz] = sz;
        else
        {
            R[sz] = h[r];
            L[sz] = L[h[r]];
            R[L[sz]] = sz;
            L[R[sz]] = sz;
        }
    }
    void Remove(int c)
    {
        for(int i = D[c];i!=c;i = D[i])
        {
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }
    void Resume(int c)
    {
        for(int i = U[c];i!=c;i = U[i])
            L[R[i]] = R[L[i]] = i;
    }
    int vis[MAX_N];
    int f()
    {
        int res = 0;
        for(int i = R[0];i;i = R[i])
            vis[i] = 0;
        for(int i = R[0];i;i = R[i])
        {
            if(!vis[i])
            {
                res++;
                vis[i] = 1;
                for(int j = D[i];j!=i;j = D[j])
                    for(int k = R[j];k!=j;k = R[k])
                        vis[Col[k]] = 1;
            }
        }
        return res;
    }
    void dance(int cnt)
    {
        if(cnt+f() >= ans) return ;
        if(R[0] == 0)
        {
            ans = min(ans,cnt);
            return ;
        }
        int c = R[0];
        for(int i = R[0];i;i = R[i])
            if(s[c] > s[i]) c = i;
        for(int i = D[c];i!=c;i = D[i])
        {
            Remove(i);
            for(int j = R[i];j!=i;j = R[j])
                Remove(j);
            dance(cnt+1);
            for(int j = L[i];j!=i;j = L[j])
                Resume(j);
            Resume(i);
        }
    }

}dlx;

int G[20][20],id[20][20];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sz = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
            {
                scanf("%d",&G[i][j]);
                if(G[i][j])
                    id[i][j] = ++sz;
            }
        dlx.init(sz);
        int st,ed;
        scanf("%d%d",&st,&ed);
        int cnt = 0;
        int t = (n+st-1)/st*((m+ed-1)/ed);
        for(int i = 0;i+st <= n;i++)
            for(int j = 0;j+ed <= m;j++)
            {
                cnt++;
                for(int di = 0;di < st;di++)
                    for(int dj = 0;dj < ed;dj++)
                        if(G[i+di][j+dj])
                            dlx.link(cnt,id[i+di][j+dj]);
            }
        dlx.ans = t;
        dlx.dance(0);
        printf("%d\n",dlx.ans);
    }
    return 0;
}
