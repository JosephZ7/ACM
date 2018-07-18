#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 1e4+10;
const int mod = 100;
const double eps = 1e-6;
using namespace std;
int n;
struct Matrix
{
    int a[55][55];
    Matrix operator * (const Matrix &e)const
    {
        Matrix c;
        memset(c.a,0,sizeof(c.a));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                for(int k = 0;k < n;k++)
                    c.a[i][j] = (c.a[i][j]+a[i][k]*e.a[k][j]%mod)%mod;
        return c;
    }
    void MakeE()
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                a[i][j] = i == j?1:0;
    }
};
Matrix Matrix_pow(Matrix ma,int b)
{
    Matrix tmp;
    tmp.MakeE();
    while(b)
    {
        if(b&1)
            tmp = tmp*ma;
        b>>=1;
        ma = ma*ma;
    }
    return tmp;
}
int f[55];
int main()
{
    int k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++)
        scanf("%d",&f[i]);
    Matrix ma;
    ma.MakeE();
    for(int i = 0;i < n;i++)
        ma.a[i][(i+1)%n] = 1;
    ma = Matrix_pow(ma,k);
    for(int i = 0;i < n;i++)
    {
        int tmp = 0;
        for(int j = 0;j < n;j++)
            tmp = (tmp+ma.a[i][j]*f[j])%mod;
        if(i == n-1)
            printf("%d\n",tmp);
        else
            printf("%d ",tmp);
    }
    return 0;
}
/*
*/
