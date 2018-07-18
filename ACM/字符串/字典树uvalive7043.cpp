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
const int MAX_N = 5e5+10;
const int INF = 1<<30;
const LL inf = 1e17+10;
using namespace std;
char s[50];
int n,cnt,ch[MAX_N][2],val[MAX_N],sz,ans[50];
struct IP
{
    int a,b,c,d,l;
    IP(int a,int b,int c,int d,int l):a(a),b(b),c(c),d(d),l(l){}
};
vector<IP> v;
void add(int x)
{
    for(int i = 7;i >= 0;i--)
    {
        if(x&(1<<i))
            s[cnt++] = '1';
        else
            s[cnt++] = '0';
    }
}
void Insert(char t[],int len)
{
    int u = 0;
    for(int i = 0;i < len;i++)
    {
        int k = t[i]-'0';
        if(!ch[u][k])
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][k] = sz++;
        }
        u = ch[u][k];
    }
    val[u] = 1;
}
void query(int u,int cur)
{
    if(val[u]) return ;
    for(int i = 1;i >= 0;i--)
    {
        ans[cur] = i;
        if(!ch[u][i])
        {
            int a[4];
            for(int j = 0;j <= 3;j++)
            {
                int tmp = 0,st = 8*j,ed = j*8+7;
                for(int k = st;k <= ed;k++)
                    tmp = tmp*2+ans[k];
                a[j] = tmp;
            }
            v.push_back(IP(a[0],a[1],a[2],a[3],cur));
        }
        else
            query(ch[u][i],cur+1);
    }
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        sz = 1;
        memset(ch[0],0,sizeof(ch[0]));
        scanf("%d",&n);
        if(n == 0)
        {
            printf("Case #%d\n1\n0.0.0.0/0\n",ti++);
            continue;
        }
        int a,b,c,d,l;
        for(int i = 0;i < n;i++)
        {
            scanf("%d.%d.%d.%d/%d",&a,&b,&c,&d,&l);
            cnt = 0;
            add(a); add(b); add(c); add(d);
            s[cnt] = 0;
            Insert(s,l);
        }
        query(0,0);
        int len = v.size();
        printf("Case #%d:\n%d\n",ti++,len);
        for(int i = 0;i < len;i++)
            printf("%d.%d.%d.%d/%d\n",v[i].a,v[i].b,v[i].c,v[i].d,v[i].l+1);
    }
    return 0;
}
/*
*/
