#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
struct Point
{
    int a[3];
    int id,cnt;
    int vis[21];
    string path;
}no[100];
int m,k;
string ans[MAX_N];

string change(int x)
{
    string temp = "";
    while(x)
    {
        int t = x%10;
        temp = (char)(t+'0')+temp;
        x/=10;
    }
    //cout<<temp<<endl;
    return temp;
}
bool judge(string a,string b)
{
    int A[30],B[30],k1 = 0,k2 = 0;
    string t = "";
    for(int i = 0;i < a.size();i++)
    {
        if(a[i] == ' '||i == a.size()-1)
        {
            if(i == a.size()-1) t+=a[i];
            A[k1++] = atoi(t.c_str());
            t = "";
        }
        else t+=a[i];
    }
    for(int i = 0;i < b.size();i++)
    {
        if(b[i] == ' '||i == b.size()-1)
        {
            if(i == a.size()-1) t+=b[i];
            B[k2++] = atoi(t.c_str());
            t = "";
        }
        else t+=b[i];
    }
    for(int i = 0 ;i < 21;i++)
    {
        if(A[i] > B[i])
            return false;
    }
    return true;
}
void Sort()
{
    for(int i = 0;i < k;i++)
    {
        for(int j = i+1;j < k;j++)
        {
            if(judge(ans[i],ans[j]))
               swap(ans[i],ans[j]);
        }
    }
}
void solve(int u)
{
    queue<Point> q;
    Point st;
    st.id = u;
    st.cnt = 1;
    memset(st.vis,0,sizeof(st.vis));
    st.path = change(u);
    for(int i = 0;i < 3;i++)
    {
        Point t = st;
        t.id = no[u].a[i];
        t.path+=" "+change(t.id);
        t.vis[t.id] = 1;
        t.cnt++;
        q.push(t);
    }
    while(!q.empty())
    {
        Point now = q.front();
        q.pop();

        if(now.id == u&&now.cnt == 21)
        {
            ans[k++] = now.path;
            continue;
        }
        else if(now.id == u)
            continue;

        for(int i = 0;i < 3;i++)
        {
            Point t = now;
            t.id = no[now.id].a[i];
            if(t.vis[t.id]) continue;
            t.vis[t.id] = 1;
            t.cnt++;
            t.path += " "+change(t.id);
            q.push(t);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int x,y,z;
    for(int i = 1;i <= 20;i++)
    {
        scanf("%d%d%d",&no[i].a[0],&no[i].a[1],&no[i].a[2]);
        no[i].id = i;
    }
    while(scanf("%d",&m),m)
    {
        k = 0;
        solve(m);
        Sort();
        for(int i = 0;i < k;i++)
        {
            printf("%d:  ",i+1);
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
/*
*/
