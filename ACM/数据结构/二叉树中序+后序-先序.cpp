#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
const LL inf = 1e15+5;
using namespace std;
int N;
void Find(int b[],int d[],int len)
{
    int i;
    for(i = 0;i < len;i++)
        if(d[i] == b[len-1])
            break;
    if(i == len)
        return ;
    printf("%d ",d[i]);
    Find(b,d,i);
    Find(b+i,d+i+1,len-i-1);
}
int main()
{
    int b[200],d[200];
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&b[i]);
    for(int i = 0;i < N;i++)
        scanf("%d",&d[i]);
    Find(b,d,N);
    return 0;
}
/*
*/
