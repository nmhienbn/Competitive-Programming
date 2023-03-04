#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pb push_back
#define Irelia "fixstr"
const int maxn = 1e6 + 5, INF = 1e9;
using namespace std;

int n, m, a[maxn], T[maxn * 8];
string s;
int b[1005][1005];
char typ;
int st[maxn * 8];

void lazy(int id){
    T[id * 2] += T[id];
    st[id * 2] += T[id];

    T[id * 2 + 1] += T[id];
    st[id * 2 + 1] += T[id];

    T[id] = 0;
}

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        st[id] += val;
        T[id] += val;
        return;
    }
    lazy(id);
    int m = (l + r) >> 1;
    update(id * 2, l, m, d, c, val);
    update(id * 2 + 1, m + 1, r, d, c, val);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return INF;
    if (d <= l && r <= c) return st[id];
    lazy(id);
    int m = (l + r) >> 1;
    return min(get(id * 2, l, m, d, c),
                     get(id * 2 + 1, m + 1, r, d, c));
}

int get(int id, int l, int r, int vt){
    if (vt == 0) return 0;
    if (l == r) return st[id];
    lazy(id);
    int m = (l + r) >> 1;
    if (vt <= m) return get(id * 2, l, m, vt);
    else return get(id * 2 + 1, m + 1, r, vt);
}

void sub1(){
    fi(i, 1, n) b[0][i] = s[i] == '(' ? 1 : -1;
    fi(i, 1, m){
        cin >> typ;
        if (typ == 'C'){
            int u;
            cin >> u;
            fi(j, 1, n) b[i][j] = b[i - 1][j];
            b[i][u] = - b[i][u];
        }
        else if (typ == 'U'){
            int u;
            cin >> u;
            fi(j, 1, n) b[i][j] = b[u - 1][j];
        }
        else {
            fi(j, 1, n) b[i][j] = b[i - 1][j];
            int u, v;
            cin >> u >> v;
            int sum = 0, minb = 0;
            fi(j, u, v) sum += b[i][j], minb = min(minb, sum);
            int res = 0;
            if (minb < 0) res -= minb, sum -= minb;
            res += sum;
            cout << res << '\n';
        }
    }
    exit(0);
}

void invert(int u){
    if (s[u] == '('){
        update(1, 1, n, u, n, -2);
        s[u] = ')';
    }
    else {
        update(1, 1, n, u, n, 2);
        s[u] = '(';
    }
}

struct dl {
    char typ;
    int u, v;
} f[maxn];

int ans[maxn];
vector<int> g[maxn];
bool cl[maxn];
void dfs(int u){
    cl[u] = 1;
    for (int v : g[u]) if (!cl[v]){
        char typ = f[v].typ;
        if (typ == 'C'){
            invert(f[v].u);
            dfs(v);
            invert(f[v].u);
        }
        else if (typ == 'Q'){
            int i = f[v].u, j = f[v].v;
            int s1 = get(1, 1, n, i-1);
            int s2 = get(1, 1, n, j);
            int s3 = get(1, 1, n, i, j);
            int sum = s2 - s1;
            int minb = s3 - s1;
            if (minb < 0) ans[v] -= minb, sum -= minb;
            ans[v] += sum;
            dfs(v);
        }
        else {
            dfs(v);
        }
    }
}

void sub2(){
    fi(i, 1, n){
        if (s[i] == '(') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
    }
    build(1, 1, n);
    fi(i, 1, m){
        cin >> typ;
        if (typ == 'C'){
            int u;
            cin >> u;
            g[i - 1].pb(i);
            g[i].pb(i - 1);
            f[i] = {typ, u, 0};
        }
        else if (typ == 'Q'){
            int u, v;
            cin >> u >> v;
            g[i].pb(i - 1);
            g[i - 1].pb(i);
            f[i] = {typ, u, v};
        }
        else {
            int u;
            cin >> u;
            g[i].pb(u - 1);
            g[u - 1].pb(i);
            f[i] = {typ, u, 0};
        }
    }
    dfs(0);
    fi(i, 1, m) if (f[i].typ == 'Q') cout << ans[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    if (n <= 1000) sub1();
    sub2();
}
