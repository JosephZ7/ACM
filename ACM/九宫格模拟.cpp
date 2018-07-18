#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<math.h>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int MAX_N = 2e3+10;
int qk[1000][3][3],cnt;
void Rotate(int a[][3])
{
    int t[3][3];
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            t[i][j] = a[j][3-i-1];
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            a[i][j] = t[i][j];
}
void ROTATE(int x)
{
    cnt++;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            qk[cnt][i][j] = qk[x][i][j];
    Rotate(qk[cnt]);
    cnt++;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            qk[cnt][i][j] = qk[cnt-1][i][j];
    Rotate(qk[cnt]);
    cnt++;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            qk[cnt][i][j] = qk[cnt-1][i][j];
    Rotate(qk[cnt]);
}
void Mirror()
{
    cnt++;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            qk[cnt][i][j] = qk[1][i][j];
    for(int i = 0;i < 3;i++)
        swap(qk[cnt][i][0],qk[cnt][i][2]);
    cnt++;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            qk[cnt][i][j] = qk[1][i][j];
    for(int i = 0;i < 3;i++)
        swap(qk[cnt][0][i],qk[cnt][2][i]);
}
void init()
{
    cnt = 1;
    qk[cnt][0][0] = 4;qk[cnt][0][1] = 9;qk[cnt][0][2] = 2;
    qk[cnt][1][0] = 3;qk[cnt][1][1] = 5;qk[cnt][1][2] = 7;
    qk[cnt][2][0] = 8;qk[cnt][2][1] = 1;qk[cnt][2][2] = 6;
    Mirror();
    for(int i = 1;i <= 3;i++)
        ROTATE(i);
}
int k;
bool equl(int a[][3],int x)
{
    int tmp = 0;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            if(qk[x][i][j] == a[i][j])
                tmp++;
    return tmp == k;
}
void print(int x)
{
    for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                printf(j == 2?"%d\n":"%d ",qk[x][i][j]);
    cout<<endl;
}
bool Equal(int x)
{
    for(int i = 1;i < x;i++)
    {
        int f = 0;
        for(int j = 0;j < 3;j++)
            for(int g = 0;g < 3;g++)
                if(qk[x][j][g]==qk[i][j][g])
                    f++;
        if(f == 9) return true;
    }
    return false;
}
int main()
{
    init();
    int a[3][3];
    k = 0;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]) k++;
        }
    int ans = 0,pos = 0;
    for(int i = 1;i <= cnt;i++)
    {
        if(Equal(i)) continue;
        //print(i);
        if(equl(a,i))
        {
            ans++;
            pos = i;
        }
    }
    //cout<<ans<<endl;
    if(ans == 1)
    {
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                printf(j == 2?"%d\n":"%d ",qk[pos][i][j]);
    }
    else
        printf("Too Many\n");
    return 0;
}
