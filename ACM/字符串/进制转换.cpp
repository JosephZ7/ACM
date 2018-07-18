const int MAXN = 1000;
int  t[MAXN], A[MAXN];
char OldData[MAXN], NewData[MAXN];  // 转换前、后的数据
int olds, news;                     // 转换前、后的进制

// 调用方式：输入olds、news、OldData，然后调用trans(),输出NewData
void trans()
{
    int i, len, k;
    len = strlen(OldData);
    for(i=len; i>=0; --i)
        t[len-1-i] = OldData[i] - (OldData[i]<58 ? 48 : OldData[i]<97 ? 55 : 61);
    for(k=0; len;)
    {
        for(i=len; i>=1; --i)
        {
            t[i-1] += t[i]%news*olds;
            t[i] /= news;
        }
        A[k++] = t[0] % news;
        t[0] /= news;
        while(len>0 && !t[len-1]) --len;
    }
    NewData[k] = NULL;
    for(i=0; i<k; ++i)
        NewData[k-1-i] = A[i] + (A[i]<10 ? 48 : A[i]<36 ? 55 : 61);
}
