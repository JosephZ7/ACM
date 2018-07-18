#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
#define ULL unsigned long long
const int MAX_N = 5e6+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
const ULL seed = 1e9+13;
using namespace std;
ULL f[MAX_N];
void init()
{
    f[0] = 1ULL;
    for(int i = 1;i < MAX_N;i++)
        f[i] = f[i-1]*seed;
}
ULL Hash(char s[],int len)
{
    ULL h = 0ULL;
    for(int i = 0;i < len;i++)
        h = h*seed+s[i];
    return h;
}
char s1[MAX_N],s2[MAX_N],ans[MAX_N];
ULL stk[MAX_N];
int main()
{
    init();
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int top = 0;
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        ULL cmp = Hash(s1,l1);
        stk[top] = 0;
        for(int i = 0;i < l2;i++)
        {
            ans[top++] = s2[i];
            stk[top] = stk[top-1]*seed+s2[i];
            if(top >= l1&&stk[top]-stk[top-l1]*f[l1] == cmp)
                top-=l1;
        }
        ans[top] = '\0';
        printf("%s\n",ans);
    }
    return 0;
}
/*
abc
aaabcbc
b
bbb
abc
ab
*/
