#include <stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
const int mod = 998244353;
const int MAX_N = 1e4+10;
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
    Point operator + (const Point &b)const
    {
        return Point(x+b.x,y+b.y);
    }
    Point operator - (const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
    bool operator == (const Point &b)const
    {
        return x==b.x&&y==b.y;
    }
}p[MAX_N<<2],ans[MAX_N<<1];
struct Line
{
    Point s,e;
    double ang;
    Line(){}
    Line(Point a,Point b)
    {
        s=a,e=b;
        ang=atan2(b.y-a.y,b.x-a.x);
    }
    Point operator &(const Line &b)const
    {
        Point res = s;
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x+=(e.x-s.x)*t;
        res.y+=(e.y-s.y)*t;
        return res;
    }
}line[MAX_N<<1];
bool HPI_cmp(Line a,Line b)
{
    if(fabs(a.ang-b.ang)>eps)
        return a.ang<b.ang;
    return ((a.s-b.s)^(b.e-b.s))<-eps;//保留逆时针方向那个
}
int HPI(int n)
{
    Line Q[MAX_N];
    int tot=1,cnt=0;
    sort(line,line+n,HPI_cmp);
    for (int i=1;i<n;i++)
        if(fabs(line[i].ang-line[i-1].ang)>eps)
            line[tot++]=line[i];
    int head=0,tail=1;
    Q[0]=line[0];
    Q[1]=line[1];
    for(int i = 2; i < tot; i++)
    {
        if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s))<eps||fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s))<eps)
            return 0;
        while(head < tail && (((Q[tail]&Q[tail-1])-line[i].s)^(line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (((Q[head]&Q[head+1])-line[i].s)^(line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (((Q[tail]&Q[tail-1])-Q[head].s)^(Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (((Q[head]&Q[head-1])-Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
        head++;
    if(tail<=head+1)
        return 0;
    for (int i=head;i<tail;i++)
        ans[cnt++]=Q[i]&Q[i+1];
    if(head<tail-1)
        ans[cnt++]=Q[head]&Q[tail];
    return cnt;
}
double Cal_area(Point t[],int n)
{
    double res=0;
    for (int i=0;i < n;i++)
        res+=(t[i]^t[(i+1)%n]);
    return res/2.0;
}
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        if(Cal_area(p,n) < 0) reverse(p,p+n);
        for(int i = 0;i < n-1;i++)
            line[i] = Line(p[i],p[i+1]);
        line[n-1] = Line(p[n-1],p[0]);
        int len = HPI(n);
        double f = Cal_area(ans,len);
        printf("%.2f\n",f);
    }
    return 0;
}
/*
*/
