#include<cstdio>
#include<cstring>
const int MAXN = 128;
double A[MAXN][MAXN];
int n;
int cmp(double x, double y) {
	double v = abs(x-y);
	if(v>1e-6) return 1;
	if(v<-1e-6) return -1;
	return 0;
}
void Solve() {
	//A[1]...A[n];
	//A[i][1]...A[i][n] A[i][n+1]
	for(int i=1; i<=n; ++i) {
		if(cmp(A[i][i],0)==0) {
			int j;
			for(j=i+1; j<=n; ++j)
				if(cmp(A[j][i],0)==1)
					break;
			swaprow(i,j);
		}
		for(int j=1; j<=n; ++j) 
			if(j!=i) {
				subrow(j,i,A[j][i]/A[i][i]);
			}
	}
	for(int i=1; i<=n; ++i)
		A[i][n+1] /= A[i][i];
}
