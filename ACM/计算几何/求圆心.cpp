#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
using namespace std;
const int MAX_N = 1e2+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
double R;
int N;
struct Point
{
    double x,y;
}a[MAX_N],O1,O2;
double getdist(Point e,Point b)
{
    return (e.x-b.x)*(e.x-b.x)+(e.y-b.y)*(e.y-b.y);
}
int getnum(Point t)
{
    int sum = 0;
    for(int i = 0;i < N;i++)
        if(R*R-getdist(t,a[i]) > -eps)
            sum++;
    return sum;
}
void getO(Point e1,Point e2)
{
    Point t;
    t.x = (e1.x+e2.x)/2;
    t.y = (e1.y+e2.y)/2;
    double d = sqrt(R*R-getdist(e1,t));
    double k1 = e1.x-e2.x;
    double k2 = e1.y-e2.y;
    if(e1.y == e2.y)
    {
        O1.x = t.x; O1.y = t.y-d;
        O2.x = t.x; O2.y = t.y+d;
        return ;
    }
    double angle = atan(-k1/k2);
    O1.x = t.x-cos(angle)*d;
    O1.y = t.y-sin(angle)*d;
    O2.x = t.x+cos(angle)*d;
    O2.y = t.y+sin(angle)*d;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>R>>N;
        for(int i = 0;i < N;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        if(N <= 1)
        {
            printf("%d\n",N);
            continue;
        }
        int ans = 1;
        for(int i = 0;i < N-1;i++)
        {
            for(int j = i+1;j < N;j++)
            {
                if(getdist(a[i],a[j]) > 4.0*R*R) continue;
                getO(a[i],a[j]);
                ans = max(ans,getnum(O1));
                ans = max(ans,getnum(O2));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
