#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <bitset>
#include <algorithm>
#include <iostream>
#define LL long long
#define PI acos(-1)
#define INF 0x7fffffff
const LL mod = 1000000007;
const int MAX_N = 1e3+10;
const double eps = 1e-6;
using namespace std;
int a[MAX_N];
bitset<1005> s[10005];
int main()
{
    int N;
    scanf("%d",&N);
    int x,n;
    for(int i = 0;i < N;i++)
    {
        scanf("%d",&n);
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&x);
            s[x].set(i);
        }
    }
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        if((s[p]&s[q]).any())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
/*
*/
