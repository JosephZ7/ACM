#include <stdio.h>
int main()
{
    double b,c,d,p;
    int k;
    long long tmp=0;
    scanf("%lf%lf%lf%d%lf",&b,&c,&d,&k,&p);
    for (int i=1;i<=k;i++)
        tmp+=(c+d*i);
    double m=0,bm=0;
    bm=b+tmp;
    m=tmp*(1+p/100.0);
    if(bm<m)
        printf("Cash\n%.2f\n",m-bm);
    else
        printf("Insurance\n%.2f\n",bm-m);
    return 0;
}
