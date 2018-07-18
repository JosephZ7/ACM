#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 3e5+10;
const double eps = 1e-6;
const LL mod = 10000007;
const LL inf = 1LL<<60;
using namespace std;
int n,m;
struct Matrix
{
    LL a[3][3];
    Matrix operator * (const Matrix &e)const
    {
        Matrix b;
        memset(b.a,0,sizeof(b.a));
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                for(int k = 0;k < 3;k++)
                    b.a[i][j] = (b.a[i][j]+a[i][k]*e.a[k][j]%m)%m;
        return b;
    }
};
Matrix Matrix_pow(Matrix ma,int b)
{
    Matrix t;
    memset(t.a,0,sizeof(t.a));
    for(int i = 0;i < 3;i++)
        t.a[i][i] = 1;
    while(b)
    {
        if(b&1)
            t = t*ma;
        b>>=1;
        ma = ma*ma;
    }
    return t;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 1||n == 2)
            cout<<n%m<<endl;
        else
        {
            Matrix ma;
            ma.a[0][0] = 1; ma.a[0][1] = 2; ma.a[0][2] = 1;
            ma.a[1][0] = 1; ma.a[1][1] = 0; ma.a[1][2] = 0;
            ma.a[2][0] = 0; ma.a[2][1] = 0; ma.a[2][2] = 1;
            ma = Matrix_pow(ma,n-2);
            cout<<(ma.a[0][0]*2+ma.a[0][1]+ma.a[0][2])%m<<endl;
        }
    }
    return 0;
}
/*
*/
