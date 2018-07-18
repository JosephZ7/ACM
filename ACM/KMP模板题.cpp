#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <iostream>
#include <iomanip>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
int next[MAX_N],a[MAX_N];
int n,m;
void getnext(int s[])
{
    mem(next);
    int k = -1,j = 0;
    next[0] = -1;
    while(j < n)
    {
        if(k == -1||s[k] == s[j])
        {
            next[j+1] = k+1;
            j++;
            k++;
        }
        else
            k = next[k];
    }
}
int KMP(int s[],int t[])
{
    getnext(t);
    int i = 0,j = 0;
    while(i < n&&j < m)
    {
        if(j == -1||s[i] == t[j])
        {
            i++,j++;
        }
        else
            j = next[j];
        if(j == m)
            return i-j+1;
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        for(int j = 0;j < m;j++)
            scanf("%d",&s[j]);
        printf("%d\n",KMP(a,s));
    }
    return 0;
}
