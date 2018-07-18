#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.1415926535898
#define LL long long int
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int N,M,S;
double V;
struct node
{
    int u,v;
    double Rab,Cab;
}es[20000];
int e;
void add(int u,int v,double r,double c)
{
   es[e].u = u;
   es[e].v = v;
   es[e].Rab = r;
   es[e++].Cab = c;
}
double d[20000];
bool Bellman()
{
    memset(d,0,sizeof(d));
    d[S] = V;
    bool flag;
    for(int i = 1;i < N;i++)
    {
        flag = false;
        for(int j = 0;j < e;j++)
        {
            if(d[es[j].v] < (d[es[j].u]-es[j].Cab)*es[j].Rab)
            {
                d[es[j].v] = (d[es[j].u]-es[j].Cab)*es[j].Rab;
                flag = true;
            }
        }
        if(!flag) break;
    }
    for(int i = 0;i < e;i++)
    {
        if(d[es[i].v] < (d[es[i].u]-es[i].Cab)*es[i].Rab)
            return true;
    }
    return false;
}
int main()
{
    e = 0;
    scanf("%d%d%d%lf",&N,&M,&S,&V);
    int A,B;
    double Rab,Rba,Cab,Cba;
    for(int i = 0;i < M;i++)
    {
        scanf("%d%d%lf%lf%lf%lf",&A,&B,&Rab,&Cab,&Rba,&Cba);
        add(A,B,Rab,Cab);
        add(B,A,Rba,Cba);
    }
    if(Bellman())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
