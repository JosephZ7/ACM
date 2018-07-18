#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 1e6+10;
const int mod = 100;
const double eps = 1e-6;
using namespace std;
struct Tree
{
    LL x,y,z,dep;
    void dosort()
    {
        if(y < x) swap(x,y);
        if(z < x) swap(x,z);
        if(z < y) swap(z,y);
    }
}st,ed;
LL Abs(LL x)
{
    if(x > 0LL)
        return x;
    return -x;
}
bool cmp(Tree a,Tree b)
{
    if(a.x == b.x&&a.y == b.y&&a.z == b.z)
        return true;
    return false;
}
Tree Root(Tree &t)
{
    Tree tmp = t;
    tmp.dep = 0;
    LL dep = 0,c;
    while(Abs(tmp.x-tmp.y)!=Abs(tmp.y-tmp.z))
    {
        LL len1 = Abs(tmp.x-tmp.y);
        LL len2 = Abs(tmp.y-tmp.z);
        if(len2 > len1)
        {
            c = (len2-1)/len1;
            tmp.x+=c*len1;
            tmp.y+=c*len1;
        }
        else
        {
            c = (len1-1)/len2;
            tmp.y-=c*len2;
            tmp.z-=c*len2;
        }
        dep+=c;
    }
    t.dep = dep;
    return tmp;
}
void update(Tree &t,LL delta)
{
    LL cnt = 0,c,Mi;
    while(cnt < delta)
    {
        LL len1 = Abs(t.x-t.y);
        LL len2 = Abs(t.y-t.z);
        LL d = Abs(cnt-delta);
        if(len1 < len2)
        {
            c = (len2-1)/len1;
            Mi = min(d,c);
            t.x+=Mi*len1;
            t.y+=Mi*len1;
        }
        else
        {
            c = (len1-1)/len2;
            Mi = min(d,c);
            t.y-=Mi*len2;
            t.z-=Mi*len2;
        }
        cnt+=Mi;
        if(Mi == d) break;
    }
    t.dep-=delta;
}
LL solve()
{
    Tree ts,te;
    LL l = 0,r = st.dep;
    while(l <= r)
    {
        LL mid = l+r>>1;
        LL delta = st.dep-mid;
        ts = st; te = ed;
        update(ts,delta);
        update(te,delta);
        if(!cmp(ts,te))
            r = mid-1;
        else
            l = mid+1;
    }
    return 2*(st.dep-r);
}
int main()
{
    while(scanf("%I64d%I64d%I64d",&st.x,&st.y,&st.z)!=EOF)
    {
        scanf("%I64d%I64d%I64d",&ed.x,&ed.y,&ed.z);
        st.dep = ed.dep = 0;
        st.dosort(); ed.dosort();
        Tree rs = Root(st);
        Tree rt = Root(ed);
        if(!cmp(rs,rt))
        {
            printf("NO\n");
            continue;
        }
        LL tmp = Abs(st.dep-ed.dep);
        if(st.dep > ed.dep)
            update(st,st.dep-ed.dep);
        else
            update(ed,ed.dep-st.dep);
        LL ans = solve();
        printf("YES\n");
        printf("%I64d\n",tmp+ans);
    }

    return 0;
}
/*
*/
