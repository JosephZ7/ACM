#include<cstdio>
#include<cstring>
#define N 1010
bool flag[N], a[N][N];
int ans, cnt[N], group[N], n, vis[N];
// ����ţ� V��ȡK�����㣬������໥����
// ���������� V��ȡK�����㣬����䲻����
// ��������� = ��ͼ������������

bool dfs( int u, int pos ){
    int i, j;
    for( i = u+1; i <= n; i++){
        if( cnt[i]+pos <= ans ) return 0;
        if( a[u][i] ){
             // ��Ŀǰ����Ԫ�رȽϣ�ȡ Non-N(i)
            for( j = 0; j < pos; j++ ) if( !a[i][ vis[j] ] ) break;
            if( j == pos ){     // ��Ϊ�գ������ i ���ڣ����ʱ��i���뵽 �������
                vis[pos] = i;
                if( dfs( i, pos+1 ) ) return 1;
            }
        }
    }
    if( pos > ans ){
            for( i = 0; i < pos; i++ )
                group[i] = vis[i]; // ����� Ԫ��
            ans = pos;
            return 1;
    }
    return 0;
}
void maxclique()
{
    ans=-1;
    for(int i=n;i>0;i--)
    {
        vis[0]=i;
        dfs(i,1);
        cnt[i]=ans;
    }
}
