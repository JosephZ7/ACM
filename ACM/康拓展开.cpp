void calc()
{
    f[1] = 1;
    for(int i = 2;i <= 9;i++)
        f[i] = f[i-1]*i;
}
int work(char str[])
{
    int res = 0;
    for(int i = 0;i < 9;i++)
    {
        int tmp = 0;
        for(int j = i+1;j < 9;j++)
            if(str[i] > str[j]) tmp++;
        res+=tmp*f[8-i];
    }
    //cout<<res<<endl;
    return res;
}
