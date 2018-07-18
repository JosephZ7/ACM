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
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
const LL inf = 1e15+5;
using namespace std;
void e_gcd(int a,int b,int &d,int &x,int &y)
{
    if(b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        return ;
    }
    e_gcd(b,a%b,d,y,x);
    y-=x*(a/b);
}
void calc(int a,int b,int d,int &x,int &y)
{
    int k;
    e_gcd(a,b,k,x,y);
    x*=d/k;
    int t = b/k;
    x = (x%t+t)%t;
    y = abs((a*x-d)/b);
}
int main()
{
    int a,b,d;
    while(scanf("%d%d%d",&a,&b,&d)&&a&&b&&d)
    {
        int x1,x2,y1,y2;
        calc(a,b,d,x1,y1);
        calc(b,a,d,x2,y2);
        if(x1+y1 < x2+y2)
            printf("%d %d\n",x1,y1);
        else
            printf("%d %d\n",y2,x2);
    }
    return 0;
}
/*
*/
