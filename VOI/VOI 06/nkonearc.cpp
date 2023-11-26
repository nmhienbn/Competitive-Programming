#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define minimize(x,y) x = x > y ? y : x
#define pb push_back
#define ll long long
#define Irelia "nkonearc"
const int maxn = 2005;
using namespace std;

int n, m;
int low[maxn], num[maxn], id;
vector<int> g[maxn];
int st[maxn], sn;
int cnt, scc[maxn];
bool in[maxn], out[maxn];

void dfs(int u){
    low[u] = num[u] = ++id;
    st[++sn] = u;
    for (int v : g[u]) if (num[v] >= 0){
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    if (low[u] == num[u]){
        cnt++;
        while (true){
            int v = st[sn--];
            scc[v] = cnt;
            num[v] = -1;
            if (v == u) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    fi(u, 1, n) if (!num[u]){
        dfs(u);
    }
    fi(u, 1, n){
        for (int v : g[u]){
            if (scc[u] != scc[v]){
                in[scc[v]] = out[scc[u]] = 1;
            }
        }
    }
    fi(i, 1, cnt) if (!out[i]) fi(j, 1, cnt) if (!in[j]){
        fi(u, 1, n) if (scc[u] == i) fi(v, 1, n) if (scc[v] == j){
            cout << "YES\n" << u << ' ' << v;
            exit(0);
        }
    }
    cout << "NO\n";
}
