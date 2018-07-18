#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 3e5+10;
const double eps = 1e-7;
const int mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int val,id;
}a[1000];
int b[1000];
bool cmp(const node &x,const node &y)
{
    return x.val < y.val;
}
int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    int least = 0,most = 0;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i].val);
        least+=(a[i].val+1)/2;
        most+=a[i].val;
        a[i].id = i;
    }
    if(least > w||most < w)
    {
        printf("-1\n");
        return 0;
    }
    sort(a,a+n,cmp);
    int t,sum = 0,flag = 1;
    b[a[0].id] = t = (a[0].val+1)/2;
    sum += t;
    for(int i = 1;i < n;i++)
    {
        if(i == n-1)
        {
            if(sum < w)
                t = w-sum;
            else
                flag = 0;
        }
        else
            t = (a[i].val+1)/2;
        if(t < b[a[i-1].id]||t < (a[i].val+1)/2)
            flag = 0;
        if(t > a[i].val)
        {
            int x = t-a[i].val;
            while(x)
            {
                for(int j = i-1;j >= 0;j--)
                {
                    if(b[a[j].id] < a[j].val)
                    {
                        b[a[j].id]++;
                        x--;
                    }
                    if(x == 0) break;
                }
            }
            t = a[i].val;
        }
        b[a[i].id] = t;
        sum+=t;
        if(sum > w)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 0)
    {
        printf("-1\n");
    }
    else
    {
        for(int i = 0;i < n;i++)
        {
            if(i == n-1)
                printf("%d\n",b[i]);
            else
                printf("%d ",b[i]);
        }
    }
    return 0;
}

