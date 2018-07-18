#include <stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
const int mod = 998244353;
const int MAX_N = 5e4+10;
const double eps=1e-6;
using namespace std;
struct Point
{
    double x,y;
    Point() {}
    Point(double a,double b)
    {
        x=a,y=b;
    }
    Point operator - (const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    bool operator == (const Point &b)const
    {
        return x==b.x&&y==b.y;
    }

}p[MAX_N],ch[MAX_N];
int len;
bool Point_cmp(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int Convex_hull(int n)
{
    sort(p,p+n,Point_cmp);
    n=unique(p,p+n)-p;
    int m=0;
    for (int i=0;i<n;i++)
    {
        while(m>1&&((ch[m-1]-ch[m-2])^(p[i]-ch[m-2]))<=0)
            m--;
        ch[m++]=p[i];
    }
    int k=m;
    for (int i=n-2;i>=0;i--)
    {
        while(m>k&&((ch[m-1]-ch[m-2])^(p[i]-ch[m-2]))<=0)
            m--;
        ch[m++]=p[i];
    }
    if(n>1)
        m--;
    return m;
}
double Rotating_Calipers(int n)
{
    int j=1;
    double ans=0;
    ch[n]=ch[0];
    int s = 1,e = 2;
    for (int i=0;i<n;i++)
    {
        while(((ch[i]-ch[s])^(ch[i]-ch[e]))<((ch[i]-ch[s+1])^(ch[i]-ch[e])))
            s=(s+1)%n;
        ans=max(ans,fabs((ch[i]-ch[s])^(ch[i]-ch[e])));
        while(((ch[i]-ch[s])^(ch[i]-ch[e]))<((ch[i]-ch[s])^(ch[i]-ch[e+1])))
            e=(e+1)%n;
        ans=max(ans,fabs((ch[i]-ch[s])^(ch[i]-ch[e])));
        //cout<<fabs((ch[i]-ch[i+1])^(ch[i]-ch[j]))<<endl;
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == -1) break;
        for(int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        len = Convex_hull(n);
        //for(int i = 0;i < len;i++)
            //printf("%lf %lf\n",ch[i].x,ch[i].y);
        double ans = Rotating_Calipers(len);
        printf("%.2f\n",ans/2);
    }
    return 0;
}
