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
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000009;
const LL inf = 1e15+5;
using namespace std;
int b[200],d[200];
map<int, int>L, R;

int build(int ld,int rd,int lb,int rb)
{
    if(lb > rb)
        return 0;
    int i;
    int rt = b[rb];
    for(i = ld;i <= rd;i++)
        if(d[i] == rt)
            break;
    if(i <= rd)
    {
        L[rt] = build(ld,i-1,lb,rb-rd+i-1);
        R[rt] = build(i+1,rd,rb-rd+i,rb-1);
    }
    return rt;
}
void BFS(int rt)
{
    queue<int> q;
    q.push(rt);
    int x = 0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if(x == 0)
            printf("%d",t);
        else
            printf(" %d",t);
        x++;
        if(L[t])
            q.push(L[t]);
        if(R[t])
            q.push(R[t]);
    }
    cout<<endl;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)
        scanf("%d",&b[i]);
    for(int i = 1;i <= N;i++)
        scanf("%d",&d[i]);
    int rt = build(1,N,1,N);
    BFS(rt);
    return 0;
}
/*
*/
