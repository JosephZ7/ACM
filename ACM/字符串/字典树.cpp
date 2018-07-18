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
const int MAX_N = 4e5+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
struct Trie
{
    int ch[MAX_N][26];
    int num[26];
    int sz;
    void clr()
    {
        sz = 0;
        memset(num,0,sizeof(num));
        memset(ch[0],0,sizeof(ch[0]));
    }
    void Insert(char *s)
    {
        int len = strlen(s);
        int u = 0;
        for(int i = 0;i < len;i++)
        {
            int z = s[i]-'a';
            if(!ch[u][z])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                ch[u][z] = ++sz;
                if(i) num[z]++;
            }
            u = ch[u][z];
        }
    }
};
Trie frt,bac;
/*
*/
