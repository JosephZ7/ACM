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
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int l,r;
    int lazy;
    int sum;
}tree[MAX_N<<2];
int N,M,Ql,Qr,ans;
int K,A,B;
void PushUp(int id,int l,int r)
{
    tree[id].sum = tree[id<<1].sum+tree[id<<1|1].sum;
    if(tree[id].sum == r-l+1||!tree[id].sum)
        tree[id].lazy = 1;
}
void PushDown(int id,int l,int r)
{
    if(tree[id].lazy)
    {
        int mid = (l+r)/2;
        tree[id<<1].lazy = tree[id<<1|1].lazy = 1;
        if(tree[id].sum == r-l+1)
        {
            tree[id<<1].sum = mid-l+1;
            tree[id<<1|1].sum = r-mid;
        }
        else
        {
            tree[id<<1].sum = 0;
            tree[id<<1|1].sum = 0;
        }
        tree[id].lazy = 0;
    }
}
void build(int id,int l,int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].sum = 0;
    tree[id].lazy = 1;
    if(l == r)
        return ;
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
void Clear(int id,int l,int r)
{
    if(A <= l&&r <= B)
    {
        ans+=tree[id].sum;
        tree[id].lazy = 1;
        tree[id].sum = 0;
        return ;
    }
    PushDown(id,l,r);
    int mid = (l+r)/2;
    if(A <= mid)
        Clear(id<<1,l,mid);
    if(B > mid)
        Clear(id<<1|1,mid+1,r);
    PushUp(id,l,r);
}
void PutFlower(int id,int l,int r)
{
    if(ans <= 0) return ;

    if(A <= l&&r <= B&&tree[id].lazy)
    {
        if(!tree[id].sum)
        {
            ans-=(r-l+1);
            tree[id].sum = r-l+1;
            if(Ql < 0) Ql = l-1;
            Qr = r-1;
        }
        else
        {
            B+=(r-l+1);
            if(B > N)
                B = N;
        }
        return ;
    }
    PushDown(id,l,r);
    int mid = (l+r)/2;
    if(A <= mid)
        PutFlower(id<<1,l,mid);
    if(B > mid)
        PutFlower(id<<1|1,mid+1,r);
    PushUp(id,l,r);
}
int main()
{
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {

        scanf("%d%d",&N,&M);
        build(1,1,N);
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d%d",&K,&A,&B);
            if(K == 1)
            {
                A++;
                ans = B;
                B = ans+A-1;
                Ql = Qr = -1;
                PutFlower(1,1,N);
                if(Qr >= 0)
                    printf("%d %d\n",Ql,Qr);
                else
                    printf("Can not put any one.\n");
            }
            else
            {
                A++; B++;
                ans = 0;
                Clear(1,1,N);
                printf("%d\n",ans);
            }
        }
        printf("\n");
    }
    return 0;
}
