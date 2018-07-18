#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n, m, cur;
long long dp[2][1<<15];       /*1表示当前位置已被填上，0则相反*/
int main(void)
{
    int i, j, k;
    while(scanf("%d%d", &n, &m), n!=0 || m!=0)
    {
        for(i=0;i<=(1<<m)-1;i++)
            dp[0][i] = 1;       /*边界处理，所有dp[0][j]初始化为1*/
        if(m>n)
            swap(n, m);     /*交换行列，使列尽可能窄*/
        cur = 0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(cur==0)      /*滚动数组*/
                    cur = 1;
                else
                    cur = 0;
                memset(dp[cur], 0, sizeof(dp[cur]));
                for(k=0;k<=(1<<m)-1;k++)       //  枚举上个阶段的状态(00000000…(m个0)→11111111…(m个1))
                {
                    /*第一种放法：不放    条件：二进制k最左边为1,即k&(1<<(m-1))==1*/
                    if(k&(1<<(m-1)))
                        dp[cur][(k<<1)^(1<<m)] += dp[1-cur][k];
                                //(k<<1)^(1<<m)为新状态，所有1和0往左移1位并弃掉最高位的1，因为不放所以不用+1*/
                    /*第二种放法：竖放    条件：二进制k最左边为0且当前不是第一行,即k&(1<<(m-1))==0 && i!=1 */
                    if(i!=1 && (k&(1<<(m-1)))==0)
                        dp[cur][(k<<1)+1] += dp[1-cur][k];
                                //(k<<1)+1为新状态，所有1和0往左移一位并+1, 因为最高位是0没必要弃掉
                    /*第三种放法：横放    条件：二进制k最左边为1，最右边为0，且当前不是第一列，即(k&(1<<(m-1)))!=0 && (k&1)==0 && j!=1)*/
                    if(j!=1 && (k&(1<<(m-1)))!=0 && (k&1)==0)
                        dp[cur][(k<<1)^(1<<m)+3] += dp[1-cur][k];
                                //(k<<1)^(1<<m)+3为新状态，所有1和0往左移一位并+3，弃掉最高位的1
                }
            }
        }
        printf("%lld\n", dp[cur][(1<<m)-1]);  //全部填满的状态
    }
    return 0;
}
