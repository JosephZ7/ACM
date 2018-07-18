#include<iostream>
using namespace std;
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int f[1000]={0,0,1,1};//初始化前4个
int g[500],c[1000];
int main()
{
    int i,j,k,m,n,s;
    for(i=4;i<=1000;i++)
    {
        m=0;
        for(j=1;j<=i/2;j++)
        {
            g[m++]=f[j-1]^f[i-j-1];
        }
        qsort(g,m,sizeof(g[0]),cmp);//排序
        for(k=0;;k++)
        if(g[k]!=k)//找其补集的最小值
        {
            f[i]=k;//找到f[i]
            break;
        }
        //printf("a[%d]=%d\n",i,a[i]);
    }
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
         cin>>c[i];
        s=0;
        for(i=0;i<n;i++)
         s=s^f[c[i]];
        if(s==0)printf("先取者输\n");
        else printf("先取者赢\n");
    }

    return 0;
}
