#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

const int MAX = 1e3+7;
//const int maxn = 3e6+5;
const int mod = 1000000007;
const db eps = 1e-7;
int ca = 1;

struct PO
{
    int x, y;
    PO (){};
    PO (int x, int y):x(x), y(y){};
    friend PO operator - (const PO&a, const PO&b)
    {
        return PO(a.x-b.x, a.y-b.y);
    }
};
PO pos[MAX];//存点
PO ch[MAX];//栈
bool cmp(const PO&a, const PO&b)
{
    if(a.x==b.x)return a.y<b.y;
    else return a.x<b.x;
}
int cross(const PO&a, const PO&b)
{
    return a.x*b.y-a.y*b.x;
}

int n;

void solve()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &pos[i].x, &pos[i].y);
    sort(pos, pos+n, cmp);
    //第一条链
    int m = 0;
    for(int i=0; i<n; i++)
    {
        while(m>1 && cross(pos[i]-ch[m-2], ch[m-1]-ch[m-2])>=0) m--;
        ch[m++] = pos[i];
    }
    //第二条链
    int temp = m;
    for(int i=n-2; i>=0; i--)
    {
        while(m>temp && cross(pos[i]-ch[m-2], ch[m-1]-ch[m-2])>=0) m--;
        ch[m++] = pos[i];
    }
    if(n>1) m--;
    cout << "______________"<<endl;
    for(int i=0; i<m; i++)
        printf("%d %d\n", ch[i].x, ch[i].y);
}

int main()
{
    //Frei
    //Freo
    int t = 1;
    //cin >> t;
    while (t--) solve();

}
