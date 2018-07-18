#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e6+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
using namespace std;
LL c1[200],c2[200];
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i = 0;i <= N;i++)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for(int i = 2;i <= N;i++)
        {
            for(int j = 0;j <= N;j++)
                for(int k = 0;k+j <= N;k+=i)
                    c2[j+k]+=c1[j];
            for(int j = 0;j <= N;j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout<<c1[N]<<endl;
    }
    return 0;
}
/*
*/
