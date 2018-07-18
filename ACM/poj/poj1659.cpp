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
int Map[100][100];
struct node
{
    int deg;
    int v;

}a[100];
int cmp(const void *x,const void *y)
{
    return (*(struct node*)y).deg - (*(struct node*)x).deg;
}
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        mem(Map);
        for(int i = 0;i < N;i++)
        {
            scanf("%d",&a[i].deg);
            a[i].v = i;
        }
        int flag = 1;
        for(int k = 0;k < N;k++)
        {
            if(flag == 0) break;
            qsort(a+k,N-k,sizeof(a[0]),cmp);
            //for(int j = k;j <= N;j++)
               // printf("%d\n",a[j]);
            int d = a[k].deg;
            int x = a[k].v;
            if(d >= N-k)
                flag = 0;
            for(int j = 1;j <= d;j++)
            {
                if(flag == 0) break;
                int y = a[k+j].v;
                if(a[k+j].deg <= 0)
                    flag = 0;
                a[k+j].deg--;
                Map[x][y] = Map[y][x] = 1;
            }
        }
        if(flag == 0)
            puts("NO");
        else
        {
            puts("YES");
            for(int i = 0;i < N;i++)
            {
                for(int j = 0;j < N;j++)
                {
                    printf("%d",Map[i][j]);
                    if(j < N-1)
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        if(T)
            cout<<endl;
    }

    return 0;
}
