#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "sumseqs"
const int maxn = 5e5 + 5, mod = 1e9;
using namespace std;

int n, a[maxn], prem[maxn], preM[maxn];
int q[maxn], top;
int res;

int add(int a, int b){
    return a + b >= mod ? a + b - mod : a + b;
}
int sub(int a, int b){
    return a >= b ? a - b : a - b + mod;
}
int mul(int a, int b){
    return 1ll * a * b % mod;
}
struct dl {
    int L, m, M, mL, ML, mM, mML, len, lzL, lzm, lzM;
    void print(){
        cout << L << ' ' << m << ' ' << M << ' ' << mL << ' ' << ML
        << ' ' << mM << ' ' << mML << ' ' << len << ' ' << lzL << ' ' << lzm << ' ' << lzM;
        cout << endl;
    }
    void updm(int x){
        m   = mul(x, len);
        mL  = mul(x, L);
        mM  = mul(x, M);
        mML = mul(x, ML);
        lzm = x;
    }
    void updM(int x){
        M   = mul(x, len);
        ML  = mul(x, L);
        mM  = mul(x, m);
        mML = mul(x, mL);
        lzM = x;
    }
    void add_L(int x){
        L   = add(L, mul(x, len));
        mL  = add(mL, mul(x, m));
        ML  = add(ML, mul(x, M));
        mML = add(mML, mul(x, mM));
        lzL = add(lzL, x);
    }
    friend void merge(dl& c, dl a, dl b){
        c.L   = add(a.L, b.L);
        c.m   = add(a.m, b.m);
        c.M   = add(a.M, b.M);
        c.mL  = add(a.mL, b.mL);
        c.mM  = add(a.mM, b.mM);
        c.ML  = add(a.ML, b.ML);
        c.mML = add(a.mML, b.mML);
    }
    void lazy(dl& p){
        if (p.lzm)  updm(p.lzm);
        if (p.lzM)  updM(p.lzM);
        if (p.lzL) add_L(p.lzL);
    }
} st[maxn << 2];
void build(int id, int l, int r){
    st[id].len = r - l + 1;
    if (l == r){
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
}
void down(int id){
    st[id * 2].lazy(st[id]);
    st[id * 2 + 1].lazy(st[id]);
    st[id].lzL = st[id].lzm = st[id].lzM = 0;
}
void udm(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        st[id].updm(val);
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    udm(id * 2, l, m, d, c, val);
    udm(id * 2 + 1, m + 1, r, d, c, val);
    merge(st[id], st[id * 2], st[id * 2 + 1]);
}
void udM(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        st[id].updM(val);
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    udM(id * 2, l, m, d, c, val);
    udM(id * 2 + 1, m + 1, r, d, c, val);
    merge(st[id], st[id * 2], st[id * 2 + 1]);
}
void addL(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        st[id].add_L(val);
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    addL(id * 2, l, m, d, c, val);
    addL(id * 2 + 1, m + 1, r, d, c, val);
    merge(st[id], st[id * 2], st[id * 2 + 1]);
}

void calcPre(){
    fi(i, 1, n){
        while (top && a[q[top]] > a[i]) top--;
        prem[i] = q[top];
        q[++top] = i;
    }
    top = 0;
    fi(i, 1, n){
        while (top && a[q[top]] < a[i]) top--;
        preM[i] = q[top];
        q[++top] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
    }
    build(1, 1, n);
    calcPre();
    fi(i, 1, n){
        udm(1, 1, n, prem[i] + 1, i, a[i]);
        udM(1, 1, n, preM[i] + 1, i, a[i]);
        addL(1, 1, n, 1, i, 1);
        res = add(res, st[1].mML);
    }
    cout << res;
}

