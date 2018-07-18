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
const LL mod = 10;
using namespace std;
int n,m;
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
                    b.a[i][j] = (b.a[i][j]+a[i][k]*e.a[k][j]%m)%m;
        return b;
    }
    void makeE()
    {
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++)
                a[i][j] = i == j?1:0;
    }
};
Matrix Matrix_pow(Matrix ma,int b)
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
    int a,b;
    while(scanf("%d%d%d%d",&a,&b,&n,&m)!=EOF)
    {
        Matrix ma;
        ma.a[0][0] = a; ma.a[0][1] = b;
        ma.a[1][0] = 1; ma.a[1][1] = a;
        ma = Matrix_pow(ma,n);
        cout<<ma.a[0][0]*2%m<<endl;
    }
    return 0;
}
/*
*/
