#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+1e3;
struct Node{
	int minv, addv, maxv;
}tree[MAXN<<2];
int a[MAXN], n;
void build(int id, int tl, int tr) {
	tree[id].addv = 0;
	if(tl==tr) {
		tree[id].minv = a[tl];
		tree[id].maxv = a[tl];
	}
	else {
		int tm = tl+tr>>1;
		build(id<<1, tl, tm);
		build(id<<1|1, tm+1, tr);
		tree[id].minv = min(tree[id<<1].minv, tree[id<<1|1].minv);
		tree[id].maxv = max(tree[id<<1].maxv, tree[id<<1|1].maxv);
	}
}
void pushdown(int id) {
	int& x = tree[id].addv;
	tree[id<<1].minv += x;
	tree[id<<1].maxv += x;
	tree[id<<1].addv += x;
	tree[id<<1|1].minv += x;
	tree[id<<1|1].maxv += x;
	tree[id<<1|1].addv += x;
	x = 0;
}
void add(int id, int tl, int tr, int ql, int qr, int v) {
	if(ql<=tl&&tr<=qr) {
		tree[id].addv += v;
		tree[id].minv += v;
		tree[id].maxv += v;
		return;
	}
	if(tl<tr) pushdown(id);
	int tm = tl+tr>>1;
	if(tl<=qr&&tm>=ql)
		add(id<<1, tl, tm, ql, qr, v);
	if(tr>=ql&&tm+1<=qr)
		add(id<<1|1, tm+1, tr, ql, qr, v);
	if(tl<tr) {
	tree[id].minv = min(tree[id<<1].minv, tree[id<<1|1].minv);
	tree[id].maxv = max(tree[id<<1].maxv, tree[id<<1|1].maxv);
	}
}
int query(int id, int tl, int tr, int ql, int qr) {
	if(ql<=tl&&tr<=qr) {
		return tree[id].minv;
	}
	if(tl<tr) pushdown(id);
	int tm = tl+tr>>1;
	int ret = (1<<31)-1;
	if(tl<=qr&&tm>=ql)
		ret = query(id<<1, tl, tm, ql, qr);
	if(tr>=ql&&tm+1<=qr)
		ret = min(ret, query(id<<1|1, tm+1, tr, ql, qr));
	return ret;
}
int queryX(int id, int tl, int tr, int ql, int qr) {
	if(ql<=tl&&tr<=qr) {
		return tree[id].maxv;
	}
	if(tl<tr) pushdown(id);
	int tm = tl+tr>>1;
	int ret = 0;
	if(tl<=qr&&tm>=ql)
		ret = queryX(id<<1, tl, tm, ql, qr);
	if(tr>=ql&&tm+1<=qr)
		ret = max(ret, queryX(id<<1|1, tm+1, tr, ql, qr));
	return ret;
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	build(1, 0, n-1);
	return 0;
}

