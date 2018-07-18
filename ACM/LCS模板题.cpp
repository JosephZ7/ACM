#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e4+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
char a[110][40],b[110][40];
char ans[110][40];
int dp[110][110],vis[110][110],la,lb,cnt;
void LCS()
{
    mem(dp,0); mem(vis,0);
    for(int i = 0;i <= la;i++)
        vis[i][0] = 1;
    for(int i = 0;i <= lb;i++)
        vis[0][i] = -1;
    for(int i = 1;i <= la;i++)
    {
        for(int j = 1;j <= lb;j++)
        {
            if(!strcmp(a[i-1],b[j-1]))
            {
                dp[i][j] = dp[i-1][j-1]+1;
                vis[i][j] = 0;
            }
            else if(dp[i-1][j] >= dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                vis[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                vis[i][j] = -1;
            }
        }
    }
}
void PrintLCS(int i,int j)
{
    if(i == 0&&j == 0)
        return ;
    if(vis[i][j] == 0)
    {
        PrintLCS(i-1,j-1);
        strcpy(ans[cnt++],a[i-1]);
    }
    else if(vis[i][j] == 1)
        PrintLCS(i-1,j);
    else
        PrintLCS(i,j-1);
}
int main()
{
    while(scanf("%s",a[0])!=EOF)
    {
        la = 1;
        while(strcmp(a[la-1],"#"))
            scanf("%s",a[la++]);

        la--;
        scanf("%s",b[0]);
        lb = 1;
        while(strcmp(b[lb-1],"#"))
            scanf("%s",b[lb++]);

        LCS();
        cnt = 0;
        PrintLCS(la,lb);
        printf("%s",ans[0]);
        for(int i = 1;i < cnt;i++)
            printf(" %s",ans[i]);
        printf("\n");
    }
    return 0;
}
