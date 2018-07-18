#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#define LL long long
const int MAX_N = 5e4+10;
const double eps = 1e-8;
const LL mod = 1e9+7;
using namespace std;
struct node
{
    LL val;
    double x,y,angle;
    node(){}
    void getangle()
    {
        angle = atan(y/x);
    }
    bool operator < (const node &e)const
    {
        return angle < e.angle;
    }
}p[MAX_N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lld",&p[i].x,&p[i].y,&p[i].val);
            p[i].getangle();
        }
        sort(p,p+n);
        LL L = 0,R = 0;
        for(int i = 0;i < n;i++)
        {
            if(p[i].x > eps)
                L+=p[i].val;
            else
                R+=p[i].val;
        }
        LL ans = L*R;
        for(int i = 0;i < n;i++)
        {
            if(p[i].x > 0)
                L-=p[i].val,R+=p[i].val;
            else
                L+=p[i].val,R-=p[i].val;
            ans = max(ans,L*R);
        }
        cout<<ans<<endl;
    }
    return 0;
}
