#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 5e2+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
struct Point
{
    int x,y;
}a[MAX_N];
int have[MAX_N][MAX_N];
int check(Point p1,Point p2)
{
    int dx = p1.x-p2.x;
    int dy = p1.y-p2.y;
    int ans = 0;
    if(p1.x+dy <= 200&&p1.x+dy >= 0&&p1.y-dx >= 0&&p1.y-dx <= 200&&p2.x+dy <= 200&&p2.x+dy >= 0
       &&p2.y-dx >= 0&&p2.y-dx <= 200&&have[p1.x+dy][p1.y-dx]&&have[p2.x+dy][p2.y-dx])
        ans++;
    if(p1.x-dy >= 0&&p1.x-dy <= 200&&p1.y+dx <= 200&&p1.y+dx >= 0&&p2.x-dy >= 0&&p2.x-dy <= 200
       &&p2.y+dx <= 200&&p2.y+dx >= 0&&have[p1.x-dy][p1.y+dx]&&have[p2.x-dy][p2.y+dx])
        ans++;
    return ans;
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        memset(have,0,sizeof(have));
        for(int i = 0;i < N;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].x+=100; a[i].y+=100;
            have[a[i].x][a[i].y] = 1;
        }
        int ans = 0;
        for(int i = 0;i < N;i++)
            for(int j = i+1;j < N;j++)
                 ans+=check(a[i],a[j]);
        cout<<ans/4<<endl;
    }
    return 0;
}
/*
*/
