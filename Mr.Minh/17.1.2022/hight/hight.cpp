#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "hight"
const int maxn = 105;
using namespace std;

int n, st, fn, m = 1;
vector<pii> g[maxn];
bool flag;
int lab[maxn];

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
} a[10005];

int find(int u){
    return lab[u] < 0 ? u : lab[u] = find(lab[u]);
}

bool unify(int u, int v){
    int p = find(u);
    int q = find(v);
    if (p == q) return false;
    if (lab[p] < lab[q]) swap(p, q);
    lab[q] += lab[p];
    lab[p] = q;
    return true;
}

void dfs(int u, int p, int val){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        dfs(v, u, min(val, w));
        if (flag) break;
    }
    if (u == st){
        flag = 1;
        cout << val << '\n';
    }
    if (flag) cout << u << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> st >> fn;
    while (cin >> a[m].u >> a[m].v >> a[m].w){
        m++;
    }
    m--;
    sort(a + 1, a + m + 1);
    memset(lab, -1, sizeof lab);
    fi(i, 1, m){
        if (unify(a[i].u, a[i].v)){
            g[a[i].u].pb({a[i].v, a[i].w});
            g[a[i].v].pb({a[i].u, a[i].w});
        }
    }
    if (unify(st, fn)){
        cout << 0;
        exit(0);
    }
    dfs(fn, 0, 1e9);
}
