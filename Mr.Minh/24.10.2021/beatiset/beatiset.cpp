#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "beatiset"
const int maxn = 5e4+5;

using namespace std;

int n, q, a[maxn], b[maxn][20], h[maxn], s[maxn],
    in[maxn], out[maxn], id, x[maxn], maxs, maxa;
vector<int> g[maxn];

void dfs(int u){
    in[u] = ++id;
    for (auto v : g[u]){
        if (v != b[u][0]){
            b[v][0] = u;
            h[v] = h[u]+1;
            s[v] = s[u] + x[v]-1;
            fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
            dfs(v);
        }
    }
    out[u] = id;
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    fid(i, 17, 0){
        if ((del >> i) & 1){
            u = b[u][i];
        }
    }
    if (u == v) return u;
    fid(i, 17, 0){
        if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
    }
    return b[u][0];
}

pii st[maxn*4];
vector<int> pos[maxn];

pii merge(pii a, pii b){
    if (a.first == b.first){
        return {a.first, a.second + b.second};
    }
    if (a.second > b.second){
        return {a.first, a.second - b.second};
    }
    return {b.first, b.second - a.second};
}

void build (int id, int l, int r){
    if (l == r){
        st[id] = {a[l], 1};
        return;
    }
    int m = (l+r)/2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id] = merge(st[id*2], st[id*2+1]);
}

pii get(int id, int l, int r, int d, int c){
    if (d > c) return {0, 0};
    if (c < l || d > r) return {0, 0};
    if (d <= l && r <= c) return st[id];
    int m = (l+r)/2;
    return merge(get(id*2, l, m, d, c), get(id*2+1, m+1, r, d, c));
}

void query12(int typ, int u){
    if (typ == 1){
        int l = in[u], r = out[u];
        int res = get(1, 1, n, l, r).first;
        if (!res){
            cout << "-1\n";
            return;
        }
        int lb = lower_bound(pos[res].begin(), pos[res].end(), l) - pos[res].begin();
        int ub = upper_bound(pos[res].begin(), pos[res].end(), r) - pos[res].begin();
        int freq = ub - lb;

        if (freq*2 > r-l+1) cout << res << "\n";
        else cout << "-1\n";
    }
    else if (typ == 2){
        int l = in[u], r = out[u];
        int res = merge(get(1, 1, n, 1, l-1), get(1, 1, n, r+1, n)).first;
        if (!res){
            cout << "-1\n";
            return;
        }
        int lb = lower_bound(pos[res].begin(), pos[res].end(), l) - pos[res].begin();
        int ub = upper_bound(pos[res].begin(), pos[res].end(), r) - pos[res].begin();
        int freq = int(pos[res].size())-ub+lb;

        if (freq*2 > n-r+l-1) cout << res << "\n";
        else cout << "-1\n";
    }
}

void sub1(){
    while(q--){
        int typ, u, v;
        cin >> typ >> u;
        if (typ < 3){
            query12(typ, u);
        }
        else {
            cin >> v;
            int cnt = 0;
            int lca = LCA(u, v);
            map<int, int> dem;
            cnt++, dem[x[lca]]++;
            while (u != lca){
                cnt++;
                dem[x[u]]++;
                u = b[u][0];
            }
            while (v != lca){
                cnt++;
                dem[x[v]]++;
                v = b[v][0];
            }
            bool flag = 1;
            for (auto v : dem) if (v.second*2 > cnt){
                cout << v.first << '\n';
                flag = 0;
                break;
            }
            if (flag) cout << "-1\n";
        }
    }
    exit(0);
}

void sub2(){
    while(q--){
        int typ, u, v;
        cin >> typ >> u;
        if (typ < 3){
            query12(typ, u);
        }
        else {
            cin >> v;
            int lca = LCA(u, v);
            int len = h[u] + h[v] - h[lca]*2 + 1;
            int res = merge(get(1, 1, n, in[lca], in[u]), get(1, 1, n, in[lca]+1, in[v])).first;
            if (!res){
                cout << "-1\n";
                continue;
            }
            int freq = 0;
            int lb = lower_bound(pos[res].begin(), pos[res].end(), in[lca]) - pos[res].begin();
            int ub = upper_bound(pos[res].begin(), pos[res].end(), in[u]) - pos[res].begin();
            freq += ub - lb;

            if (in[lca] < in[v]){
                int lb = lower_bound(pos[res].begin(), pos[res].end(), in[lca]+1) - pos[res].begin();
                int ub = upper_bound(pos[res].begin(), pos[res].end(), in[v]) - pos[res].begin();
                freq += ub - lb;
            }

            if (freq*2 > len) cout << res << "\n";
            else cout << "-1\n";
        }
    }
    exit(0);
}

void sub3(){
    while(q--){
        int typ, u, v;
        cin >> typ >> u;
        if (typ < 3){
            query12(typ, u);
        }
        else {
            cin >> v;
            int lca = LCA(u, v);
            int len = h[u] + h[v] - h[lca]*2 + 1;
            int cnt2 = s[u] + s[v] - s[lca]*2 + x[lca]-1;
            int cnt1 = len - cnt2;
            if (cnt1 > cnt2) cout << "1\n";
            else if (cnt2 > cnt1) cout << "2\n";
            else {
                cout << "-1\n";
            }
        }
    }
    exit(0);
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> x[i];
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    s[1] = x[1]-1;
    dfs(1);
    fi(i, 1, n){
        a[in[i]] = x[i];
        pos[x[i]].pb(in[i]);
    }
    fi(i, 1, n) sort(pos[i].begin(), pos[i].end());
    build(1, 1, n);
    if (max(n, q) <= 2000){
        sub1();
    }
    fi(i, 1, n) maxs = max(maxs, int(g[i].size()));
    if (maxs <= 2){
        sub2();
    }
    maxa = *max_element(x+1, x+n+1);
    if (maxa <= 2){
        sub3();
    }
    sub1();
}
