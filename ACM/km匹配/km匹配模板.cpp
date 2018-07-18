/* KM算法
 * 复杂度O(nx*nx*ny)
 * 求最大权匹配
 * 若求最小权匹配，可将权值取相反数，结果取相反数
 * 点的编号从0开始
 */
#include<cstring>
#include<cstdio>
const int N = 310;
const int INF = 0x3f3f3f3f;
int nx, ny; //两边的点数
int g[N][N];//二分图描述，g[x][y]表示边权。
int linker[N], lx[N], ly[N]; //y中各点匹配状态， x,y中的点标号
int slack[N];
bool visx[N], visy[N];
bool DFS(int x)
{
    visx[x] = true;
    for(int y = 0; y < ny; y++)
    {
        if(visy[y]) continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0)
        {
            visy[y] = true;
            if(linker[y] == -1 || DFS(linker[y]))
            {
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}
int KM()
{
    memset(linker, -1, sizeof(linker));
    // lx 初始为 -inf ，ly 初始为 0
    memset(ly, 0, sizeof(ly));
    for(int i = 0; i < nx; i++)
    {
        lx[i] = -INF;
        for(int j = 0; j < ny; j++)
            if(g[i][j] > lx[i])
                lx[i] = g[i][j];
    }
    for(int x = 0; x < nx; x++)
    {
        for(int i = 0; i < ny; i++)
            slack[i] = INF;  //初始slack为 inf
        while(true)
        {
            memset(visx, false, sizeof(visx));
            memset(visy, false, sizeof(visy));
            if(DFS(x))break;
            //若成功（找到了增广轨），则该点增广完成，进入下一个点的增广
            //若失败（没有找到增广轨），则需要改变一些点的标号，使得图中可行边的数量增加。
            //方法为：将所有在增广轨中（就是在增广过程中遍历到）的X方点的标号全部减去一个常数d，
            //所有在增广轨中的Y方点的标号全部加上一个常数d
            int d = INF;
            for(int i = 0; i < ny; i++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            if(d == INF)  return -1;
            for(int i = 0; i < nx; i++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 0; i < ny; i++)
            {
                if(visy[i])ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < ny; i++)
        if(linker[i] != -1)
        {
            res += g[linker[i]][i];
            if(g[linker[i]][i] == -INF)  return -1;
        }
    return res;
}
//HDU 2255
int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        nx = ny = n;
        printf("%d\n", KM());
    }
    return 0;
}
