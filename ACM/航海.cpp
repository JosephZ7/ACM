#include<cstdio>
#include<cstring>
const int MAXN = 52;
struct Pos{
	int x, y;
	Pos(int xx=0, int yy=0)
		:x(xx), y(yy){}
	Pos operator -(const Pos& b) {
		return Pos(x-b.x, y-b.y);
	}
	Pos operator +(const Pos& b) {
		return Pos(x+b.x, y+b.y);
	}
}P[MAXN];
int n, m, sz;
char map[MAXN][MAXN];
bool ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
int step[4][2] = {0,1,0,-1,-1,0,1,0};
void initia() {
	sz = 0;
	memset(ans, false, sizeof(ans));
	memset(vis, false, sizeof(vis));
}
bool check2(int x, int y) {
	return x>=0&&y>=0&&x<n&&y<m&&map[x][y]!='#';
}
bool check1(int x, int y) {
	if(vis[x][y]||!check2(x,y))
		return false;
	for(int i=1; i<sz; ++i)
		if(!check2(P[i].x+x, P[i].y+y))
			return false;
	return true;
}
void dfs(int x, int y) {
	vis[x][y] = true;
	ans[x][y] = true;
	for(int i=1; i<sz; ++i)
		ans[P[i].x+x][P[i].y+y] = true;
	for(int i=0; i<4; ++i) {
		int xx=x+step[i][0];
		int yy=y+step[i][1];
		if(check1(xx,yy)) dfs(xx,yy);
		else vis[xx][yy] = true;
	}
}
int main() {
	int t, cas;
	scanf("%d", &t);
	for(cas=0; cas<t; ) {
		printf("Case #%d: ", ++cas);
		initia();
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; ++i) {
			scanf("%s", map[i]);
			for(int j=0; j<m; ++j)
				if(map[i][j]=='o')
					P[sz++] = Pos(i,j);
		}
		if(!sz) puts("0");
		else {
			for(int i=1; i<sz; ++i)
				P[i] = P[i]-P[0];
			dfs(P[0].x, P[0].y);
			int cnt = 0;
			for(int i=0; i<n; ++i)
				for(int j=0; j<m; ++j)
					if(ans[i][j]) ++cnt;
			printf("%d\n", cnt);
		}
	}
	return 0;
}

