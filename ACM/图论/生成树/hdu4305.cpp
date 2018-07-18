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
const double eps = 1e-6;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
struct Point
{
    int x,y;
}a[MAX_N];
int dist(Point p1,Point p2)
{
    return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int INV[mod];
int niyuan(int a,int m)
{
    if(a == 1)
        return 1;
    return niyuan(m%a,m)*(m-m/a)%m;
}
int G[400][400];
int matrix[400][400];
int Det(int N)
{
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            matrix[i][j] = (matrix[i][j]%mod+mod)%mod;

    int sum = 1;
    for(int i = 0;i < N;i++)
    {
        for(int j = i;j < N;j++)
            if(matrix[j][i]!=0)
            {
                for(int k = i;k < N;k++)
                    swap(matrix[i][k],matrix[j][k]);
                if(i!=j)
                    sum = (mod-sum)%mod;
                break;
            }
        if(matrix[i][i] == 0)
            return -1;
        for(int j = i+1;j < N;j++)
        {
            int mut = (matrix[j][i]*INV[matrix[i][i]])%mod;
            for(int k = i;k < N;k++)
                matrix[j][k] = (matrix[j][k]-(matrix[i][k]*mut)%mod+mod)%mod;
        }
        sum = (sum*matrix[i][i])%mod;
    }
    return sum;
}
int N,R;
int main()
{
    int T;
    for(int i = 1;i < mod;i++)
        INV[i] = niyuan(i,mod);
    scanf("%d",&T);
    while(T--)
    {
        memset(G,0,sizeof(G));
        memset(matrix,0,sizeof(matrix));
        scanf("%d%d",&N,&R);
        for(int i = 0;i < N;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        int k;
        for(int i = 0;i < N;i++)
        {
            for(int j = i+1;j < N;j++)
            {
                if(dist(a[i],a[j]) <= R*R)
                {
                    for(k = 0;k < N;k++)
                    {
                        if(i == k||j == k) continue;
                        if((a[i].x-a[k].x)*(a[j].y-a[k].y) == (a[j].x-a[k].x)*(a[i].y-a[k].y)
                           &&dist(a[i],a[k]) < dist(a[i],a[j])&&dist(a[j],a[k]) < dist(a[i],a[j]))
                            break;
                    }
                    if(k == N)
                    {
                        G[i][j] = G[j][i] = 1;
                    }
                }
            }
        }
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                if(i!=j&&G[i][j])
                {
                    matrix[i][j] = -1;
                    matrix[i][i]++;
                }
        LL ans = Det(N-1);
        cout<<ans<<endl;
    }
    return 0;
}
