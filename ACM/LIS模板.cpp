int stk[10010];
int LIS(int a[],int n)
{
    int i,top,mid,low,high;
    top = 0;
    stk[0] = -1;
    for(i = 0;i < n;i++)
    {
        if(a[i] > stk[top])
            stk[++top] = a[i];
        else
        {
            low = 1;
            high = top;
            while(low <= high)
            {
                mid = (low+high)/2;
                if(a[i] > stk[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
            stk[low] = a[i];
        }
    }
    return top;
}
