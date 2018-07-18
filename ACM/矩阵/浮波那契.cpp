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
const int MAX_N = 5e5+10;
const LL mod = 1e9+7;
using namespace std;
LL n;
struct Matrix
{
    LL a[34][34];
    Matrix operator * (const Matrix &e)const
    {
        Matrix b;
        memset(b.a,0,sizeof(b.a));
        for(int i = 0;i < 34;i++)
            for(int j = 0;j < 34;j++)
                for(int k = 0;k < 34;k++)
                    b.a[i][j] = (b.a[i][j]+a[i][k]*e.a[k][j]%mod)%mod;
        return b;
    }
    void makeE()
    {
        for(int i = 0;i < 34;i++)
            for(int j = 0;j < 34;j++)
                a[i][j] = i == j?1:0;
    }
};
Matrix Matrix_pow(Matrix ma,LL b)
{
    Matrix tmp;
    tmp.makeE();
    while(b)
    {
        if(b&1)
            tmp = tmp*ma;
        ma = ma*ma;
        b>>=1;
    }
    return tmp;
}
int main()
{
    cin>>n;
    if(n <= 4)
    {
        printf("1\n");
        return 0;
    }
    Matrix ma;
    memset(ma.a,0,sizeof(ma.a));
    for(int i = 1;i < 34;i++)
        ma.a[i][i-1] = 1;
    ma.a[0][9] = 1; ma.a[0][33] = 1;
    ma = Matrix_pow(ma,(n-4)*10);
    /*for(int i = 0;i < 34;i++)
    {
        for(int j = 0;j < 34;j++)
        {
            printf("%d ",ma.a[i][j]);
        }
        cout<<endl;
    }*/
    LL ans = 0;
    for(int i = 0;i < 34;i++)
        ans = (ans+ma.a[0][i])%mod;
    cout<<ans<<endl;
    return 0;
}
/*
*/
