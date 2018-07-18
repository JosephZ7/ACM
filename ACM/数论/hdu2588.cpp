#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
int Euler(int n)
{
    int sum = n;
    for(int i = 2;i*i <= n;i++)
    {
        if(n%i == 0)
        {
            sum = sum/i*(i-1);
            while(n%i == 0) n/=i;
        }
    }
    if(n > 1) sum = sum/n*(n-1);
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans = 0;
        for(int i = 1;i*i <= n;i++)
        {
            if(n%i == 0)
            {
                if(i >= m) ans+=Euler(n/i);
                if(n/i >= m&&i*i!=n) ans+=Euler(i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
