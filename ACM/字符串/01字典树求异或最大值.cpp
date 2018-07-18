#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 2e5+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
int ch[MAX_N<<5][2];
int sz;
int num[MAX_N<<5];
void clr()
{
    sz = 0;
    memset(num,0,sizeof(num));
    memset(ch,0,sizeof(ch));
}
void Insert(int x)
{
    int u = 0;
    for(int i = 29;i >= 0;i--)
    {
        int zt = (x>>i)&1;
        if(!ch[u][zt])
            ch[u][zt] = ++sz;

        u = ch[u][zt];
        num[u]++;
    }
}
void del(int x)
{
    int u = 0;
    for(int i = 29;i >= 0;i--)
    {
        u = ch[u][(x>>i)&1];
        num[u]--;
    }
}
int query(int x)
{
    int u = 0,ans = 0;
    for(int i = 29;i >= 0;i--)
    {
        int zt = (x>>i)&1;
        if(num[ch[u][zt^1]])
        {
            ans+=(1<<i);
            u = ch[u][zt^1];
        }
        else
            u = ch[u][zt];
    }
    return ans;
}
int main()
{
    int q;
    scanf("%d",&q);
    char op[10];
    int s;
    clr();
    Insert(0);
    while(q--)
    {
        scanf("%s%d",op,&s);
        if(op[0] == '+')
            Insert(s);
        if(op[0] == '-')
            del(s);
        if(op[0] == '?')
            printf("%d\n",query(s));
    }
    return 0;
}
/*
*/
