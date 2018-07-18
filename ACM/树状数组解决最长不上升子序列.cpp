#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 2e5+10;
int T[MAX_N];
int lowbit(int x)
{
    return x&-x;
}
int getMax(int x)
{
    int Max = 0;
    while(x)
    {
        Max = max(Max,T[x]);
        x-=lowbit(x);
    }
    return Max;
}
void update(int x,int val)
{
    while(x < MAX_N)
    {
        T[x] = max(T[x],val);
        x+=lowbit(x);
    }
}
int a[MAX_N],f[MAX_N];
int main()
{
    //freopen("in.txt","r",stdin);
    memset(T,0,sizeof(T));
    memset(f,0,sizeof(f));
    int n = 0;
    while(scanf("%d",&a[n])!=EOF)
    {
        n++;
    }
    int Ma = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] < 0) continue;
        if(a[i] < 10000)
        {
            f[i] = getMax(a[i])+1;
            update(a[i],f[i]);
        }
        else
        {
            f[i] = getMax(a[i]-10000)+5;
            update(a[i]-10000,f[i]);
        }
        Ma = max(Ma,f[i]);
    }
    cout<<Ma<<endl;
    return 0;
}
