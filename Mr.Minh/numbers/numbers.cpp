#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "numbers"
const int maxn = 10005;

using namespace std;

int n, m, t, res;
int low[maxn], num[maxn], id;
vector<int> g[maxn];
int st[maxn], top;
int scc, stt[maxn], T;
bool has_edge[maxn][maxn];
int deg_out[maxn];

void minimize(int& x, int y){
    if (x > y) x = y;
}

void dfs(int u){
    low[u] = num[u] = ++id;
    st[++top] = u;
    for (int v : g[u]){
        if (stt[v]) continue;
        if (num[v]) minimize(low[u], num[v]);
        else {
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    if (low[u] == num[u]){
        scc++;
        while (true){
            int v = st[top--];
            stt[v] = scc;
            if (v == t) T = scc;
            if (v == u) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> t;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    fi(i, 1, n) if (!stt[i]){
        dfs(i);
    }
    fi(i, 1, n){
        for (int j : g[i]){
            int u = stt[i], v = stt[j];
            if (u == v || has_edge[u][v]) continue;
            has_edge[u][v] = 1;
            deg_out[u]++;
        }
    }
    fi(i, 1, scc) res += deg_out[i] == 0 && i != T;
    cout << res;
}
