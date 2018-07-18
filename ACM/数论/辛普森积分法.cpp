#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double esp=1e-10;
double r1,r2;
double f(double x)
{
    return sqrt((r1*r1-x*x)*(r2*r2-x*x));
}

double Simpson(double a,double b)
{
    return (b-a)*(f(a)+f(b)+4*f((a+b)/2.0))/6.0;
}

double Midd(double a,double b) ///迭代求解数值积分
{
    double mid=(a+b)/2.0;
    double res=Simpson(a,b);
    if(fabs(res-Simpson(a,mid)-Simpson(mid,b))<esp)
    {
        return res;
    }
    else return Midd(a,mid)+Midd(mid,b);
}

int main()
{

    while(scanf("%lf%lf",&r1,&r2)!=EOF)
    {
        if(r1==r2)
            printf("%.4lf\n",16.0/3*r1*r1*r1);
        else
        {
            if(r1>r2)
            {
                double t=r1;
                r1=r2;
                r2=t;
            }
            printf("%.4lf\n",8.0*Midd(0,r1));
        }
    }
    return 0;
}
