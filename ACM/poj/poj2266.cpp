#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <iostream>
#include <iomanip>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
char s[1000];
int N;
char b[1000][1000];
int k;
void Solve(int f,int e,int len)
{
    if(len == 1)
    {
        b[f][e] = s[k++];
    }
    else if(s[k]!='Q')
    {
        for(int i = f;i < f+len;i++)
            for(int j = e;j < e+len;j++)
                b[i][j] = s[k];
        k++;
    }
    else
    {
        k++;
        Solve(f,e,len/2);
        Solve(f,e+len/2,len/2);
        Solve(f+len/2,e,len/2);
        Solve(f+len/2,e+len/2,len/2);
    }
}
void print(int r,int c)
{
    int ans = 0;
    for(int i = c+7;i >= c;i--)
    {
        ans<<=1;
        if(b[r][i] == 'B') ans+=1;
        //cout<<ans<<endl;
    }
    printf("0x%02x,",ans);
}
int main()
{
    k = 0;
    scanf("%d",&N);
    scanf("%s",s);
    Solve(0,0,N);
    printf("#define quadtree_width %d\n",N);
    printf("#define quadtree_height %d\n",N);
    printf("static char quadtree_bits[] = {\n");
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N/8;j++)
        {
            print(i,j*8);
        }
        printf("\n");
    }
    printf("};");
    return 0;
}
