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
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e4+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
int a[MAX_N],vis[MAX_N];
int N,M;
struct node
{
    int dgt,pre,r;
}q[MAX_N];

int BFS()
{
    mem(vis,0);
    int l = 0,r = 1;
    q[l].dgt = 0;
    q[l].pre = -1;
    q[l].r = 0;
    while(l < r)
    {
        node t = q[l];
        int R = t.r;
        for(int i = 0;i < M;i++)
        {
            int x = (10*R+a[i])%N;
            if(!vis[x]&&(a[i]!=0||t.pre!=-1))
            {
                vis[x] = 1;
                t.dgt = a[i];
                t.pre = l;
                t.r = x;
                q[r++] = t;
                if(t.r == 0) return r-1;
            }
        }
        l++;
    }
    return -1;
}
void print(int pos)
{
    if(pos)
    {
        print(q[pos].pre);
        printf("%d",q[pos].dgt);
    }
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        scanf("%d",&M);
        for(int i = 0;i < M;i++)
            scanf("%d",&a[i]);
        if(N == 0)
        {
            printf("0\n");
            continue;
        }
        sort(a,a+M);
        int ans = BFS();
        if(ans == -1)
            printf("0\n");
        else
        {
            print(ans);
            cout<<endl;
        }
    }
    return 0;
}
/*
*/
