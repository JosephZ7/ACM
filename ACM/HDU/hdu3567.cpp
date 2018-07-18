#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 5e5+10;
const double eps = 1e-7;
const LL mod = 1000000009;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int x,y;
    int val;
    char a[11];
    node(){}
};
int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
char dirz[5] = "dlru";
int f[10];
int pre[10][MAX_N];
char ans[10][MAX_N];
int vis[MAX_N];
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
    return res;
}
int flag;
void Astar(char a[],int p)
{
    memset(pre[p],-1,sizeof(pre[p]));
    memset(vis,0,sizeof(vis));
    queue<node> q;
    node st;
    strcpy(st.a,a);
    st.x = p/3; st.y = p%3;
    st.val = work(a);
    vis[st.val] = 1;

    q.push(st);
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            node t = now;
            t.x = now.x+dir[i][0];
            t.y = now.y+dir[i][1];
            if(t.x < 3&&t.x >= 0&&t.y < 3&&t.y >= 0)
            {
                swap(t.a[t.x*3+t.y],t.a[now.x*3+now.y]);
                t.val = work(t.a);
                if(vis[t.val] == 0)
                {
                    vis[t.val] = 1;
                    pre[p][t.val] = now.val;
                    ans[p][t.val] = dirz[i];
                    q.push(t);
                }
            }
        }
    }
}
int main()
{
    calc();
    int T;
    char a[11];
    strcpy(a,"123456789");
    Astar(a,8);
    strcpy(a,"123456798");
    Astar(a,7);
    strcpy(a,"123456978");
    Astar(a,6);
    strcpy(a,"123459678");
    Astar(a,5);
    strcpy(a,"123495678");
    Astar(a,4);
    strcpy(a,"123945678");
    Astar(a,3);
    strcpy(a,"129345678");
    Astar(a,2);
    strcpy(a,"192345678");
    Astar(a,1);
    strcpy(a,"912345678");
    Astar(a,0);

    int num[20],ti = 1;
    char A[20],B[20];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",A);
        scanf("%s",B);
        int p;
        for(int i = 0,j = 0;i <9;i++)
        {
            if(A[i] == 'X') p = i;
            else num[A[i]-'0'] = j++;
        }
        for(int i = 0;i < 9;i++)
        {
            if(B[i] == 'X')
            {
                B[i] = '9';
                continue;
            }
            B[i] = num[B[i]-'0']+'1';
        }
        int val = work(B);
        string res = "";
        while(val!=-1)
        {
            res+=ans[p][val];
            val = pre[p][val];
        }
        printf("Case %d: %d\n",ti++,res.size()-1);
        for(int i = res.size()-2;i >= 0;i--)
            printf("%c",res[i]);
        cout<<endl;
    }
    return 0;
}
/*
*/
