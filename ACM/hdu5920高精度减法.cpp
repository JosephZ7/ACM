#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e6+10;
const LL inf = 1e17+10;
const int maxn = 1e6 + 233;

void sub(char s1[],char s2[])//只限大的非负整数减小的非负整数
{
    int na[1005]={0},nb[1005]={0};
    int la=strlen(s1),lb=strlen(s2);
    for(int i=0;i<la;i++) na[la-1-i]=s1[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=s2[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++)
    {
        na[i]-=nb[i];
        if(na[i]<0) na[i]+=10,na[i+1]--;
    }
    while(!na[--lmax]&&lmax>0)  ;lmax++;
    int l = 0;
    for(int i=lmax-1;i>=0;i--) s1[l++]=na[i]+'0';
    s1[l] = '\0';
}
char ans[55][1005],s[1005];
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        int k = 0,f = 0;
        printf("Case #%d:\n",ti++);
        scanf("%s",s);
        int len = strlen(s);
        char t[1005];
        while(strcmp(s,"0") != NULL)
        {
            len = strlen(s);
            for(int i = 0;i < (len+1)/2;i++)
                t[i] = s[i];

            for(int i = 0,j = len-1;i < len/2;i++,j--)
                t[j] = t[i];
            t[len] = '\0';

            if(strcmp(t,s) == 0)
            {
                strcpy(ans[f++] ,t);
                break;
            }
            else if(strcmp(t,s) < 0)
            {
                strcpy(ans[f++],t);
                sub(s,t);
            }
            else
            {
                for(int i = 0;i < (len+1)/2;i++)
                    t[i] = s[i];
                int tmp;
                t[(len+1)/2] = '\0';
                sub(t,"1");
                k = strlen(t);
                if(len%2== 0)
                    tmp = k-1;
                else
                    tmp = k-2;
                for(int i = tmp,j = k;i >= 0;i--,j++)
                    t[j] = t[i],t[j+1] = '\0';
                if(strcmp(t,"00") == 0) strcpy(t,"1");
                strcpy(ans[f++],t);
                sub(s,t);
            }
        }
        printf("%d\n",f);
        for(int i = 0;i < f;i++)
            printf("%s\n",ans[i]);
    }
    return 0;
}
/*
*/
