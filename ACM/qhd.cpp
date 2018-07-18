#define mem(a,x) memset(a,x,sizeof(a))
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<cmath>
#include<map>
#include<stdlib.h>
#include<cctype>
#include<string>
#define Sint(n) scanf("%d",&n)
#define Sll(n) scanf("%I64d",&n)
#define Schar(n) scanf("%c",&n)
#define Sint2(x,y) scanf("%d %d",&x,&y)
#define Sll2(x,y) scanf("%I64d %I64d",&x,&y)
#define Pint(x) printf("%d",x)
#define Pllc(x,c) printf("%I64d%c",x,c)
#define Pintc(x,c) printf("%d%c",x,c)
using namespace std;
typedef long long ll;
//const int N = 1000;
//int sg[N+6];
//int SG(int st)
//{
//  if (sg[st]!=-1) return sg[st];
//  set<int>s;
//  s.insert(SG(0));
//  for (int i = 1;i < st;++i)
//  {
//      s.insert(SG(st-i));//дц
//      s.insert(SG(i)^SG(st-i) );//╥ж
//  }
//  int g = 0;
//  while (s.count(g)) ++g;
//  sg[st] = g;
//  return sg[st];
//}
//void solve()
//{
//  mem(sg,-1);
//  sg[0] = 0;
//  for (int i = 1;i <= 50;++i)
//  {
//      cout<<i<<" :"<<SG(i)<<endl;
//  }
//}
int SG(int st)
{
    if (st == 0) return 0;
    if (st%4==0) return st-1;
    if (st%4==3) return st+1;
    return st;
}
int main()
{
//    solve();
    int T;cin>>T;
    while (T--)
    {
        int n;
        Sint(n);
        int s = 0;
        for (int i = 1,x;i <= n;++i)
        {
            Sint(x);
            s ^= SG(x);
        }
        if (s) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
