LL a[MAX_N],t[MAX_N];
void guibin(int first,int mid,int End)
{
    int x = mid,y = End;
    int i = first,j = mid+1;
    int k = first;
    while(i <= x&&j <= y)
    {
        if(a[i] <= a[j])
            t[k++] = a[i++];
        else
        {
            t[k++] = a[j++];
            cnt+=x-i+1;
        }
    }
    while(i <= x)
        t[k++] = a[i++];
    while(j <= y)
        t[k++] = a[j++];
    for(int i = first;i <= End;i++)
        a[i] = t[i];
}
void guibin2(int first,int End)
{
    if(first < End)
    {
        int mid = (first+End)/2;
        guibin2(first,mid);
        guibin2(mid+1,End);
        guibin(first,mid,End);
    }
}
