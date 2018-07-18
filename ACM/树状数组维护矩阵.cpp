#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<math.h>
#include<set>
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e3+10;
const int INF = 1<<30;
const LL inf = 1e17+10;
using namespace std;
int mx[1200][1200];
int c[1200][1200];
int n;
int lowbit(int x)
{
    return x&-x;
}
int query(int x,int y)
{
    int sum = 0;
    for(int i = x;i > 0;i-=lowbit(i))
        for(int j = y;j > 0;j-=lowbit(j))
            sum+=c[i][j];
    return sum;
}
void update(int x,int y,int val)
{
    for(int i = x;i <= n;i+=lowbit(i))
        for(int j = y;j <= n;j+=lowbit(j))
            c[i][j]+=val;
}
int main()
{
    int op,x,y,A,L,B,R,T;
    while(scanf("%d",&op)!=EOF)
    {
        if(op == 3) break;
        else if(op == 0)
        {
            memset(c,0,sizeof(c));
            scanf("%d",&n);
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    mx[i][j] = 0;
        }
        else if(op == 1)
        {
            scanf("%d%d%d",&x,&y,&A);
            update(x,y,A);
        }
        else if(op == 2)
        {
            scanf("%d%d%d%d",&L,&B,&R,&T);
            int ans = query(R,T)-query(R,B-1)-query(L-1,T)+query(L-1,B-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
*/
