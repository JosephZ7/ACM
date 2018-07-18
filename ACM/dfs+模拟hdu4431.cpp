#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e3+10;
const int INF = 1<<30;
char *sa[] = {"1m","2m","3m","4m","5m","6m","7m","8m","9m",
              "1s","2s","3s","4s","5s","6s","7s","8s","9s",
              "1p","2p","3p","4p","5p","6p","7p","8p","9p",
              "1c","2c","3c","4c","5c","6c","7c"};
int k;
int s[15];
int ans[55],flag;
int c[55];
void dfs(int cnt)
{
    if(cnt == 14) flag = 1;
    if(flag) return ;
    for(int i = 0;i < 34;i++)
    {
        int mk = 0;
        if(c[i] >= 3)
        {
            mk++;
            c[i]-=3;
            dfs(cnt+3);
            c[i]+=3;
        }
        if(c[i]>=1&&c[i+1] >= 1&&c[i+2] >= 1&&((0 <= i&&i <= 6)
                                                ||(9 <= i&&i <= 15)||(18 <= i&&i<=24)))
        {
            mk++;
            c[i]--; c[i+1]--; c[i+2]--;
            dfs(cnt+3);
            c[i]++; c[i+1]++; c[i+2]++;
        }
        if(mk == 0&&c[i]) return ;
        if(c[i]) break;
    }
}
bool Find()
{
    int dui,cnt,f;
    dui = cnt = f = 0;
    for(int i = 0;i < 34;i++)
    {
        if(c[i] == 2) dui++;
        if(c[i] >= 1&&((i+1)%9 == 1||(i+1)%9 == 0||i >= 27))
        {
            if(c[i] == 2) f++;
            cnt++;
        }
    }
    if(dui == 7) return true;
    if(cnt == 13&&f == 1) return true;
    for(int i = 0;i < 34;i++)
    {
        if(c[i] >= 2)
        {
            c[i]-=2;
            flag = 0;
            dfs(2);
            if(flag) return true;
            c[i]+=2;
        }
    }
    return false;
}
void Judge()
{
    for(int i = 0;i < 34;i++)
    {
        int fg = 0;
        memset(c,0,sizeof(c));
        c[i]++;
        for(int j = 0;j < 13;j++)
        {
            c[s[j]]++;
            if(c[s[j]] > 4)
            {
                fg = 1;
                break;
            }
        }
        if(fg) continue;
        if(Find())
            ans[k++] = i;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        k = 0;
        char x[5];
        for(int i = 0;i < 13;i++)
        {
            scanf("%s",x);
            for(int j = 0;j < 34;j++)
            {
                if(strcmp(x,sa[j]) == 0)
                {
                    s[i] = j;
                    break;
                }
            }
        }
        Judge();
        if(k == 0)
            printf("Nooten\n");
        else
        {
            printf("%d",k);
            for(int i = 0;i < k;i++)
                printf(" %s",sa[ans[i]]);
            printf("\n");
        }
    }
    return 0;
}
