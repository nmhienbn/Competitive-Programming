#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cards"
const int maxn = 1e5+5;

using namespace std;

struct Node {
	Node *P, *L, *R;
	int sz, val;
};
typedef Node* PNode;

PNode root, nil;

void Update(PNode x) {
	x->sz = x->L->sz + x->R->sz + 1;
}

void SetL(PNode x, PNode y) {
	x->L = y;
	y->P = x;
}

void SetR(PNode x, PNode y) {
	x->R = y;
	y->P = x;
}

PNode NodeAt(PNode x, int i) {
	while (true){
		int p = x->L->sz+1;
		if (i == p) break;
		if (i < p) x = x->L;
		else x = x->R, i -= p;
	}
	return x;
}

void UpTree(PNode x) {
	PNode y = x->P, z = y->P;
	if (y->L == x) SetL(y,x->R), SetR(x,y);
	else SetR(y,x->L), SetL(x,y);
	if (z->L == y) SetL(z,x);
	else SetR(z,x);
	Update(y);
	Update(x);
}

void Splay(PNode x) {
	for (;;) {
		PNode y = x->P, z = y->P;
		if (y == nil) return;
		if (z != nil){
			if ((z->L == y) == (y->L == x)) UpTree(y);
			else UpTree(x);
		}
		UpTree(x);
	}
}

void Split(PNode T, int i, PNode &T1, PNode &T2) {
	if (i == 0) {
		T1 = nil;
		T2 = T;
		return ;
	}
	T1 = NodeAt(T,i);
	Splay(T1);
	T2 = T1->R;
	T1->R = nil;
	T2->P = nil;
	Update(T1);
}

PNode Join(PNode T1, PNode T2) {
	if (T1 == nil) return T2;
	T1 = NodeAt(T1,T1->sz);
	Splay(T1);
	SetR(T1,T2);
	Update(T1);
	return T1;
}

//-------------------------------//
int n, x, a[maxn], k, t[maxn];
//-------------------------------//

void Init() {
	nil = new Node();
	nil->sz = nil->val = 0;
	nil->P = nil->L = nil->R = nil;
	root = nil;
}

PNode build(int l, int r) {
	if (l > r) return nil;
	int m = (l+r)>>1;
	PNode x = new Node();
	x->val = m;
	x->P = nil;
	SetL(x, build(l,m-1));
	SetR(x, build(m+1,r));
	Update(x);
	return x;
}

void S(int i, int m, int j) {
	PNode T1, T2, T3;
	Split(root, i-1, T1, T2);
	Split(T2, m, T2, T3);
	root = Join(T1, T3);
	Split(root, j-1, T1, T3);
	root = Join(Join(T1, T2), T3);
}

void dfs(PNode x) {
	if (x == nil) return ;
	dfs(x->L);
	a[++a[0]] = x->val;
	dfs(x->R);
}

int main() {
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
	cin >> n >> k >> x;
	Init();
	root = build(1,n);
	while (x--) {
		int i, m, j;
		cin >> i >> m >> j;
		S(i,m,j);
	}
	dfs(root);
	fi(i,1,k) cout << a[i] << ' ';
	return 0;
}
