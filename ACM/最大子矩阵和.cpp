#define MAX 105
// 第i行前j个元素和
int sum[MAX][MAX];
// 矩阵的行列数
int n;
// 返回最大子矩阵和，并且保存该子矩阵的起始元素和结束元素的行列值
int MaxSubMatSum(int &sX, int &sY, int &eX, int &eY)
{
    int ans=1e-6;
    // 枚举第k行，第i列至j列的和
    for(int i=1; i<=n; ++i)
    {
        for(int j=i; j<=n; ++j)
        {
            int subSum = 0;
            for(int k=1; k<=n; ++k)
            {
                // 动态规划思想，subSum<0将会减少总和，所以此时将其置0
                if(subSum < 0)
                {
                    subSum = 0;
                    sX = k;
                    sY = i;
                }
                subSum += sum[k][j] - sum[k][i-1];
                if(ans < subSum)
                {
                    ans = subSum;
                    eX = k;
                    eY = j;
                }
            }
        }
    }
    return ans;
}
