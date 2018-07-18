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
const int MAX_N = 5e5+10;
const double eps = 1e-7;
const LL mod = 1000000009;
const LL inf = 1LL<<60;
using namespace std;
int a[200][200];
int main()
{
    int N;
    while(scanf("%d",&N),N)
    {
        int num,v,w;
        memset(a,INF,sizeof(a));
        for(int i = 1;i <= N;i++)
        {
            scanf("%d",&num);
            for(int j = 0;j < num;j++)
            {
                scanf("%d%d",&v,&w);
                a[i][v] = w;
            }
        }
        for(int k = 1;k <= N;k++)
            for(int i = 1;i <= N;i++)
                for(int j = 1;j <= N;j++)
                    a[i][j] = min(a[i][j],a[i][k]+a[k][j]);

        int time,ans = INF;
        for(int i = 1;i <= N;i++)
        {
            int t = 0;
            for(int j = 1;j <= N;j++)
            {
                if(i == j)
                    continue;
                t = max(t,a[i][j]);
            }
            if(ans > t)
            {
                ans = t;
                time = i;
            }
        }
        if(ans == INF)
            printf("disjoint\n");
        else
            printf("%d %d\n",time,ans);
    }
    return 0;
}
/*
*/
