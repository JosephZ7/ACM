#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 1e6+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
using namespace std;
LL c1[300][300],c2[300][300];
int num[] = {0,1,5,10,25,50};
void init()
{
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(int j = 0;j <= 100;j++)
        c1[j][j] = 1;
    for(int i = 2;i <= 5;i++)
    {
        for(int j = 0;j <= 250;j++)
            for(int k = 0;k+j <= 250;k+=num[i])
                for(int l = 0;l+k/num[i] <= 100;l++)
                    c2[k+j][l+k/num[i]]+=c1[j][l];
        for(int k = 0;k <= 250;k++)
            for(int l = 0;l <= 100;l++)
            {
                c1[k][l] = c2[k][l];
                c2[k][l] = 0;
            }
    }
}
int main()
{
    int N;
    init();
    while(scanf("%d",&N)!=EOF)
    {
        int sum = 0;
        for(int i = 0;i <= 100;i++)
            sum+=c1[N][i];
        printf("%d\n",sum);
    }
    return 0;
}
