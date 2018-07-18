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
const int mod = 6;
const int MAX_N = 1e3+10;
using namespace std;
int n,k;
struct Matrix
{
    int a[7][7];
    Matrix operator * (const Matrix &e)const
    {
        Matrix b;
        memset(b.a,0,sizeof(b.a));
        for(int i = 0;i < k;i++)
            for(int j = 0;j < k;j++)
                for(int g = 0;g < k;g++)
                    b.a[i][j] = (b.a[i][j]+a[i][g]*e.a[g][j]%mod)%mod;
        return b;
    }
};
Matrix Matrix_pow(Matrix ma,int b)
{
    Matrix t;
    memset(t.a,0,sizeof(t.a));
    for(int i = 0;i < k;i++)
        t.a[i][i] = 1;
    while(b)
    {
        if(b&1)
            t = t*ma;
        ma = ma*ma;
        b>>=1;
    }
    return t;
}
int ans[1005][1005];
int main()
{
    while(scanf("%d%d",&n,&k),n,k)
    {
        int A[1005][7],B[7][1005];
        int tA[1005][7];
        Matrix C;
        memset(A,0,sizeof(A)); memset(tA,0,sizeof(tA));
        memset(B,0,sizeof(B)); memset(ans,0,sizeof(ans));
        memset(C.a,0,sizeof(C.a));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < k;j++)
                scanf("%d",&A[i][j]);
        for(int i = 0;i < k;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&B[i][j]);

        for(int i = 0;i < k;i++)
            for(int j = 0;j < k;j++)
                for(int g = 0;g < n;g++)
                    C.a[i][j] = (C.a[i][j]+B[i][g]*A[g][j]%mod)%mod;

        C = Matrix_pow(C,n*n-1);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < k;j++)
                for(int g = 0;g < k;g++)
                    tA[i][j] = (tA[i][j]+A[i][g]*C.a[g][j]%mod)%mod;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                for(int g = 0;g < k;g++)
                    ans[i][j] = (ans[i][j]+tA[i][g]*B[g][j]%mod)%mod;
        int sum = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                sum+=ans[i][j];
        cout<<sum<<endl;
    }
    return 0;
}
