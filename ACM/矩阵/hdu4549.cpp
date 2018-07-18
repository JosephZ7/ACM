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
const LL mod = 1000000007;
using namespace std;
struct Matrix
{
    LL a[2][2];
    Matrix operator * (const Matrix &e)const
    {
        Matrix b;
        memset(b.a,0,sizeof(b.a));
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++)
                for(int k = 0;k < 2;k++)
                    b.a[i][j] = (b.a[i][j]+a[i][k]*e.a[k][j]%(mod-1))%(mod-1);
        return b;
    }
};
Matrix Matrix_pow(Matrix ma,LL b)
{
    Matrix tmp;
    memset(tmp.a,0,sizeof(tmp.a));
    for(int i = 0;i < 2;i++)
        tmp.a[i][i] = 1;
    while(b)
    {
        if(b&1)
            tmp = tmp*ma;
        b>>=1;
        ma = ma*ma;
    }
    return tmp;
}
LL q_pow(LL a,LL b)
{
    LL sum = 1;
    while(b)
    {
        if(b&1)
            sum = sum*a%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return sum;
}
int main()
{
    LL a,b,n;
    Matrix ma;
    memset(ma.a,0,sizeof(ma.a));
    ma.a[0][0] = 1; ma.a[0][1] = 1;
    ma.a[1][0] = 1; ma.a[1][1] = 0;
    while(cin>>a>>b>>n)
    {
        Matrix q = Matrix_pow(ma,n);
        LL ans = (q_pow(b,q.a[0][1])*q_pow(a,q.a[1][1]))%mod;
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
