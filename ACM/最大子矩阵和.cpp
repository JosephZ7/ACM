#define MAX 105
// ��i��ǰj��Ԫ�غ�
int sum[MAX][MAX];
// �����������
int n;
// ��������Ӿ���ͣ����ұ�����Ӿ������ʼԪ�غͽ���Ԫ�ص�����ֵ
int MaxSubMatSum(int &sX, int &sY, int &eX, int &eY)
{
    int ans=1e-6;
    // ö�ٵ�k�У���i����j�еĺ�
    for(int i=1; i<=n; ++i)
    {
        for(int j=i; j<=n; ++j)
        {
            int subSum = 0;
            for(int k=1; k<=n; ++k)
            {
                // ��̬�滮˼�룬subSum<0��������ܺͣ����Դ�ʱ������0
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
