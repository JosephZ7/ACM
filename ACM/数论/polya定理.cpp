//polya定理求循环节个数代码模板
const int MAX=1001;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
int n,perm[MAX],visit[MAX];//sum求循环节个数,Perm用来存储置换,即一个排列
int gcd(int n,int m)
{   return m==0?n:gcd(m,n%m);
}
void Polya()
{   int pos,sum=0;
    CLR(visit,0);
    for(int i=0;i<n;i++)
        if(!visit[i])
        {   sum++;
            pos=i;
            for(int j=0;!visit[perm[pos]];j++)
            {   pos=perm[pos];
                visit[pos]=1;
            }
        }
    return sum;
}
