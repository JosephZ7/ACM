#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000009;
const LL inf = 1e15+5;
using namespace std;
LL N,M,C,f[MAX_N],k[MAX_N];
struct Matrix
{
    LL a[30][30];
    LL* operator[] (int x)
    {
        return a[x];
    }
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    Matrix operator * (Matrix &b)
    {
        Matrix c;
        for(int k = 0;k < N;k++)
            for(int i = 0;i < N;i++)
                for(int j = 0;j < N;j++)
                    c[i][j] = (c[i][j]+b[k][j]*a[i][k])%mod;
        return c;
    }
}A,B;
void init()
{
    for(int i = 0;i < N;i++)
        B[i][i] = 1;
    for(int i = 0;i < N-1;i++)
        A[i][i+1] = 1;
    for(int i = 0;i < C;i++)
        A[N-1][N-k[i]] = 1;
}
void Matrix_pow(LL x)
{
    while(x)
    {
        if(x&1)
            B = B*A;
        A = A*A;
        x>>=1;
    }
}
int main()
{
    scanf("%lld%lld%lld",&N,&M,&C);
    for(int i = 0;i < N;i++)
        scanf("%lld",&f[i]);
    for(int i = 0;i < C;i++)
        scanf("%lld",&k[i]);
    if(M <= N)
    {
        cout<<f[M-1]%mod<<endl;
        return 0;
    }
    init();
    Matrix_pow(M-1);
    LL ans = 0;
    for(int i = 0;i < N;i++)
        ans = (ans+B[0][i]*f[i])%mod;
    cout<<ans<<endl;
    return 0;
}
/*
*/
