#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
vector<int> G[200];
stack<int> s;
bool vis[200];
int C[200],R[200],id[200];
int N,T,ind;
void tarjan(int u)
{
    vis[u] = 1,s.push(u);
    C[u] = R[u] = T++;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(C[v] == -1)
        {
            tarjan(v);
            if(R[u] > R[v]) R[u] = R[v];
        }
        else if(vis[v]&&R[u] > C[v])
            R[u] = C[v];
    }
    if(R[u] == C[u])
    {
        while(1)
        {
            int v = s.top();
            s.pop();
            vis[v] = 0;
            id[v] = ind;
            if(v == u) break;
        }
        ind++;
    }
}
int main()
{
    int N;
    mem(R);
    int A = 0,B = 0;
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)
    {
        int num;
        G[i].clear();
        while(scanf("%d",&num),num)
        {
            G[i].push_back(num);
        }
    }
    for(int j = 1;j <= N;j++)
    {
        C[j] = -1; vis[j] = 0;
    }
    while(!s.empty()) s.pop();
    ind = T = 0;
    for(int i = 1;i <= N;i++) if(C[i] == -1) tarjan(i);
    for(int i = 0;i < ind;i++) C[i] = R[i] = 0;
    for(int i = 1;i <= N;i++)
    {
        int u = id[i];
        for(int j = 0;j < G[i].size();j++)
        {
            int v = id[G[i][j]];
            if(u!=v) C[u]++,R[v]++;
        }
    }
    int ans1 = 0,ans2 = 0;
    for(int i = 0;i < ind;i++)
    {
        if(R[i] == 0) ans1++;
        if(C[i] == 0) ans2++;
    }
    ans2 = max(ans1,ans2);
    if(ind == 1) ans1 = 1,ans2 = 0;
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}
