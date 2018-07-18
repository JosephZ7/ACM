#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 5e6+10;
const double eps = 1e-7;
const LL mod = 999999997;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int lc,rc;
    void clr()
    {
        lc = rc = -1;
    }
}A[10],B[10];
int rt1,rt2;
void Insert(node g[],int u,int v)
{
    if(v < u)
    {
        if(g[u].lc == -1) g[u].lc = v;
        else Insert(g,g[u].lc,v);
    }
    else
    {
        if(g[u].rc == -1) g[u].rc = v;
        else Insert(g,g[u].rc,v);
    }
}
void build(node g[],string s,int &rt)
{
    for(int i = 0;i < 10;i++)
        g[i].clr();
    rt = s[0]-'0';
    for(int i = 1;i < s.size();i++)
        Insert(g,rt,s[i]-'0');
}
bool cmp(int u,int v)
{
    if(u!=v) return false;
    if(u == -1) return true;
    return cmp(A[u].lc,B[u].lc)&&cmp(A[u].rc,B[u].rc);
}
int main()
{
    int n;
    string S,str;
    while(cin>>n&&n)
    {
        cin>>S;
        build(A,S,rt1);
        for(int i = 0;i < n;i++)
        {
            cin>>str;
            build(B,str,rt2);
            if(cmp(rt1,rt2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
