#includestdio.h
#includestdlib.h
#includecstdio
#includecstring
#includealgorithm
#includeiostream
#includemath.h
#define LL long long
const int MAX_N = 1e6+10;
using namespace std;
double a[200][200],b[200][200];
int n;
int cmp(double x,double y)
{
    double v = fabs(x-y);
    if(v  1e-6) return 1;
    if(v  -1e-6) return -1;
    return 0;
}
void swaprow(int r1,int r2)
{
    for(int i = 1;i = n+1;i++)
        swap(a[r1][i],a[r2][i]);
}
void subrow(int r1,int r2,double x)
{
    for(int i = 1;i = n+1;i++)
    {
        a[r1][i]-=x*a[r2][i];
    }
}
int main()
{
    memset(a,0,sizeof(a));
    scanf(%d,&n);
    for(int i = 1;i = n;i++)
    {
        for(int j = 1;j = n;j++)
        {
            scanf(%lf,&a[i][j]);
            b[i][j] = a[i][j];
            a[i][n+1]+=a[i][j];
            a[i][j] = 1;
        }
        a[i][i] = 0;
    }
    for(int i = 1;i = n;i++)
    {
        if(cmp(a[i][i],0) == 0)
        {
            int j;
            for(j = i+1;j = n;j++)
                if(cmp(a[j][i],0) == 1)
                    break;
            swaprow(i,j);
        }
        for(int j = 1;j = n;j++)
        {
            if(j!=i)
                subrow(j,i,a[j][i]/a[i][i]);
        }
    }
    for(int i = 1; i = n; i++)
        a[i][n+1] = a[i][i];

    for(int i = 1;i = n;i++)
        b[i][i] = a[i][n+1];
    for(int i = 1;i = n;i++)
    {
        for(int j = 1;j = n;j++)
        {
            if(j == 1)
                printf("%.0lf",b[i][j]);
            else
                printf("%.0lf",b[i][j]);
        }
        coutendl;
    }
    return 0;
}
