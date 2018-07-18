#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=110000+10;
char s[MAX*2];
int p[MAX*2];

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        memset(p,0,sizeof(p));
        int len = strlen(s);
        for(int i = len-1;i >= 0;i--)
        {
            s[i*2+2] = s[i];
            s[i*2+1] = '#';
        }
        int id = 0,mx = 0;
        int ans = 0;
        s[0] = '$',s[len*2+2] = '\0';
        s[len*2+1] = '#';
        for(int i = 2;i < 2*len+2;i++)
        {
            if(mx > i)
                p[i] = min(p[2*id-i],mx-i);
            else
                p[i] = 1;
            while(s[i+p[i]] == s[i-p[i]])
            {
                ++p[i];
            }
            if(mx < i+p[i])
            {
                mx = p[i]+i;
                id = i;
            }
            ans = max(ans,p[i]);
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
