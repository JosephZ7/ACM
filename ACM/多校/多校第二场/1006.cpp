#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 5e2+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
struct Matrix
{
    LL a[2][2];
    Matrix operator * (const Matrix &e)const
    {
        Matrix c;
        memset(c.a,0,sizeof(c.a));
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++)
                for(int k = 0;k < 2;k++)
                    c.a[i][j] = (c.a[i][j]+a[i][k]*e.a[k][j]%mod)%mod;
        return c;
    }
    Matrix operator - (const Matrix &e)const
    {
        Matrix c;
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++)
                c.a[i][j] = (a[i][j]-e.a[i][j]+mod)%mod;
        return c;
    }
    void MakeE()
    {
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++)
                a[i][j] = i==j?1:0;
    }
};
Matrix Matrix_pow(Matrix ma,LL b)
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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL N,M;
        scanf("%lld%lld",&N,&M);
        Matrix A,B0,B1;
        A.a[0][0] = 0; A.a[0][1] = 1;
        A.a[1][0] = 2; A.a[1][1] = 1;
        B0.MakeE();
        B1.a[0][0] = -1; B1.a[0][1] = 1;
        B1.a[1][0] = 2; B1.a[1][1] = 0;
        A = Matrix_pow(A,N);
        //for(int i = 0;i < 2;i++)
           // for(int j = 0;j < 2;j++)
               // printf(j == 1?"%d\n":"%d ",A.a[i][j]);
        Matrix ma;
        if(N&1)
            ma = A-B1;
        else
            ma = A-B0;
        ma = Matrix_pow(ma,M-1);
        //for(int i = 0;i < 2;i++)
           // for(int j = 0;j < 2;j++)
               // printf(j == 1?"%d\n":"%d ",ma.a[i][j]);
        LL ans = (ma.a[0][0]+ma.a[0][1]+mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
