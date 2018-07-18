#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    stack<char> s;
    char ch;
    while((ch = getchar())!=EOF)
    {
        if(ch >= 'a'&&ch <= 'z'||ch >= 'A'&&ch <= 'Z')
            s.push(ch);
        else
        {
            while(!s.empty())
            {
                char x = s.top();
                s.pop();
                printf("%c",x);
            }
            if(ch == '\n')
                printf("\n");
            else
                printf("%c",ch);
        }
    }
    while(!s.empty())
    {
        char x = s.top();
        s.pop();
        printf("%c",x);
    }
    return 0;
}
