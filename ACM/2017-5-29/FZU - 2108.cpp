#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e4+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
int B;
string A;
LL q_mod(LL a,LL b)
{
    LL sum = 1;
    while(b)
    {
        if(b&1)
            sum = (sum*a)%B;
        a = (a*a)%B;
        b>>=1;
    }
    return sum%B;
}
struct node
{
    LL val,len;
};
node dfs(int l,int r)
{
    int top = 0;
    int left,right,k,cnt;
    node ans;
    ans.val = 0;
    ans.len = 0;
    for(int i = l;i <= r;i++)
    {
        if(A[i] == '[')
        {
            if(!top)
                left = i+1;
            top++;
        }
        else if(A[i] == ']')
        {
            top--;
            if(!top)
            {
                right = i-1;
                cnt = A[i+1]-'0';
                node t = dfs(left,right);
                LL base = q_mod(10,t.len);
                ans.len += cnt*t.len;
                ans.val = (ans.val*q_mod(base,cnt))%B;
                LL s = 1,b = base;
                while(--cnt)
                {
                    s = (s+b)%B;
                    b = (b*base)%B;
                }
                t.val = (t.val*s)%B;
                ans.val = (ans.val+t.val)%B;
                i++;
            }
        }
        else if(!top)
        {
            ans.val = (ans.val*10+A[i]-'0')%B;
            ans.len++;
        }
    }
    return ans;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>A>>B;
        node ans = dfs(0,A.size()-1);
        cout<<ans.val<<endl;
    }
    return 0;
}
