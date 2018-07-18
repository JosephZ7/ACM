#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 222222
typedef long long ll;
int T,n,tot,id[maxn];
struct node
{
    int x,y,z,cnt,ans,id;
}p[maxn];
int cmpx(node a,node b)
{
    if(a.x!=b.x)return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    return a.z<b.z;
}
int cmpy(node a,node b)
{
    if(a.y!=b.y)return a.y<b.y;
    return a.z<b.z;
}
int cmpid(node a,node b)
{
    return a.id<b.id;
}
struct BIT
{
    #define lowbit(x) (x&(-x))
    int b[maxn];
    void init()
    {
        memset(b,0,sizeof(b));
    }
    void update(int x,int v)
    {
        while(x<=maxn)
        {
            b[x]+=v;
            x+=lowbit(x);
        }
    }
    int query(int x)
    {
        int ans=0;
        while(x)
        {
            ans+=b[x];
            x-=lowbit(x);
        }
        return ans;
    }
    void clear(int x)
    {
        while(x<=maxn)
        {
            b[x]=0;
            x+=lowbit(x);
        }
    }
}bit;
void CDQ(int l,int r)
{
    if(l==r)
    {
        p[l].ans+=p[l].cnt-1;
        return ;
    }
    int mid=(l+r)>>1;
    CDQ(l,mid);
    CDQ(mid+1,r);
    sort(p+l,p+mid+1,cmpy);
    sort(p+mid+1,p+r+1,cmpy);
    int j=l;
    for(int i=mid+1;i<=r;i++)
    {
        for(;j<=mid&&p[j].y<=p[i].y;j++)
            bit.update(p[j].z,p[j].cnt);
        p[i].ans+=bit.query(p[i].z);
    }
    for(int i=l;i<j;i++)bit.update(p[i].z,-p[i].cnt);
    sort(p+l,p+r+1,cmpy);
}
int main()
{
    while(~scanf("%d",&n))
    {
        bit.init();tot=0;
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),p[i].ans=0,p[i].id=i;
        sort(p+1,p+n+1,cmpx);
        for(int i=1;i<=n;i++)
        {
            if(i!=1&&p[i-1].x==p[i].x&&p[i-1].y==p[i].y&&p[i-1].z==p[i].z)
                p[tot].cnt++;
            else p[++tot]=p[i],p[tot].cnt=1;
            id[p[i].id]=tot;
            p[tot].id=tot;
        }
        CDQ(1,tot);
        sort(p+1,p+tot+1,cmpid);
        ll ans=1ll*n*(n-1)/2;
        for(int i=1;i<=n;i++)ans-=p[id[i]].ans;
        printf("%I64d\n",ans);
    }
    return 0;
}
