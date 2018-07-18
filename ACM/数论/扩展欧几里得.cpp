int e_gcd(int a,int b,int x,int y)
{
    if(b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    int ans = e_gcd(b,a%b,x,y);
    int t = x; x = y; y = t-a/b*y;
    return ans;
}
int calc(int a,int m)
{
    int x,y;
    int gcd = e_gcd(a,m,x,y);
    if(1%gcd!=0) return -1;
    x*=1/gcd;
    m = abs(m);
    int ans = x%m;
    if(ans <= 0) ans+=m;
    return ans;
}
