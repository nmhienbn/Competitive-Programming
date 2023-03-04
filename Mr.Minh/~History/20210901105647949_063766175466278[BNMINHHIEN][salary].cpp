#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "salary"
const int maxn = 5e5+5;

using namespace std;

int n, m, a[maxn], in[maxn], out[maxn], id;
ll st[maxn*4], T[maxn*4];
vector<int> g[maxn];

void dfs(int u){
    in[u] = ++id;
    for (auto v : g[u]){
        dfs(v);
    }
    out[u] = id;
}

void lazy(int id){
    T[id*2] += T[id];
    st[id*2] += T[id];
    T[id*2+1] += T[id];
    st[id*2+1] += T[id];
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c, int x){
    if (d < c) return;
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        st[id] += x;
        T[id] += x;
        return;
    }
    int m = (l + r) >> 1;
    lazy(id);
    update(id*2, l, m, d, c, x);
    update(id*2+1, m+1, r, d, c, x);
}

void get(int id, int l, int r, int vt, int x){
    if (vt > r || vt < l) return;
    if (l == r){
        cout << st[id] + x << '\n';
        return;
    }
    int m = (l + r) >> 1;
    lazy(id);
    if (vt <= m) get(id*2, l, m, vt, x);
    else get(id*2+1, m+1, r, vt, x);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> a[1];
    fi(i, 2, n){
        int u;
        cin >> a[i] >> u;
        g[u].pb(i);
    }
    dfs(1);
    while (m--){
        char kind;
        int y, x;
        cin >> kind >> y;
        if (kind == 'p'){
            cin >> x;
            update(1, 1, n, in[y]+1, out[y], x);
        }
        else {
            get(1, 1, n, in[y], a[y]);
        }
    }
}
