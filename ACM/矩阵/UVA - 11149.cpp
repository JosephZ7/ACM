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
int n;
struct Matrix
{
    LL a[50][50];
    Matrix operator * (const Matrix &e)const
    {
        Matrix b;
        memset(b.a,0,sizeof(b.a));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                for(int k = 0;k < n;k++)
                    b.a[i][j] = (b.a[i][j]+a[i][k]*e.a[k][j])%mod;
        return b;
    }
    Matrix operator + (const Matrix &e)const
    {
        Matrix c;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                c.a[i][j] = (a[i][j]+e.a[i][j])%mod;
        return c;
    }
    void makeE()
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
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
Matrix getans(Matrix ma,int num)
{
    if(num == 1)
        return ma;
    Matrix tmp;
    tmp.makeE();
    if(num&1)
    {
        Matrix tn = Matrix_pow(ma,num);
        tmp = tmp+Matrix_pow(ma,num/2);
        return tmp*getans(ma,num/2)+tn;
    }
    else
    {
        tmp = tmp+Matrix_pow(ma,num/2);
        return tmp*getans(ma,num/2);
    }
}
int main()
{
    int k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n == 0) break;
        Matrix A;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&A.a[i][j]),A.a[i][j]%=mod;
        Matrix ans = getans(A,k);
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(j == n-1)
                    printf("%d",ans.a[i][j]);
                else
                    printf("%d ",ans.a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
/*
*/
