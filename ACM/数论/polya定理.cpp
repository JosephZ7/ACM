//polya������ѭ���ڸ�������ģ��
const int MAX=1001;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
int n,perm[MAX],visit[MAX];//sum��ѭ���ڸ���,Perm�����洢�û�,��һ������
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
