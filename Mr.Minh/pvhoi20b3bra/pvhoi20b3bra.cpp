#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define mu2(i) (1 << (i))
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "pvhoi20b3bra"
const int maxn = 1e6+5;

using namespace std;

int n, m, a[maxn], bit[maxn];
string s;
int t[maxn*4], T[maxn*4];

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = a[l];
		return;
	}
	int m = (l+r) >> 1;
	build(k*2, l, m);
	build(k*2+1, m+1, r);
	t[k] = min(t[k*2], t[k*2+1]);
}

void lazy(int id){
    fi(j, id*2, id*2+1){
        T[j] += T[id];
        t[j] += T[id];
    }
    T[id] = 0;
}

void update(int k, int l, int r, int d, int c, int val) {
	if (r < d || c < l) return;
	if (d <= l && r <= c) {
		t[k] += val;
		T[k] += val;
		return;
	}
	int m = (l+r) >> 1;
	lazy(k);
	update(k*2, l, m, d, c, val);
	update(k*2+1, m+1, r, d, c, val);
	t[k] = min(t[k*2], t[k*2+1]);
}

int get(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return 1e9;
	if (L <= l && r <= R) return t[k];
	int m = (l+r) >> 1;
	lazy(k);
	return min(get(k*2, l, m, L, R), get(k*2+1, m+1, r, L, R));
}

void update(int x, int val){
    while (x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

int lowerBound(int val){
    int res = n+1, tmp = 0;
    fid(i, 20, 0) if ((tmp | mu2(i)) <= n){
        if (bit[tmp | mu2(i)] >= val) res = tmp | mu2(i);
        else {
            tmp |= mu2(i);
            val -= bit[tmp];
        }
    }
    return res;
}

int findLeftPos(int i, int l, int r, int pos, int lim) {
    if (l > pos || r < 1 || l > r || pos < 1) return n + 1;
    if (1 <= l && r <= pos){
        if (t[i] >= lim) return l;
        int res = n + 1;
        while (true) {
            if (l == r) return t[i] >= lim ? r : res;
            lazy(i);
            int m = (l + r) >> 1;
            if (t[2 * i + 1] >= lim) {
                res = m + 1;
                i = 2 * i;
                r = m;
            }
            else {
                i = 2 * i + 1;
                l = m + 1;
            }
        }
    }

    lazy(i);
    int m = (l + r) >> 1;
    if (pos <= m) return findLeftPos(2 * i, l, m, pos, lim);
    int tmp = findLeftPos(2 * i + 1, m + 1, r, pos, lim);
    int tnp = findLeftPos(2 * i, l, m, pos, lim);
    return tmp != m + 1 ? tmp : min(tmp, tnp);
}

void change(int i){
    if (s[i] == '('){
        s[i] = ')';
        update(i, 1);
        update(1, 1, n, i, n, -2);
    }
    else {
        s[i] = '(';
        update(i, -1);
        update(1, 1, n, i, n, 2);
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	fi(i, 1, n){
	    a[i] = a[i-1] + (s[i] == ')' ? -1 : 1);
        if (s[i] == ')') update(i, 1);
	}
	build(1, 1, n);
	fi(i, 1, m){
        int pos;
        cin >> pos;
        change(pos);
        int vt = s[pos] == ')' ? lowerBound(1) : findLeftPos(1, 1, n, pos, 2);
        cout << vt << ' ';
        change(vt);
	}
}
