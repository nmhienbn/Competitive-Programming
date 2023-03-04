#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define minimize(x, y) x = x > y ? y : x;
#define pb push_back
#define ll long long
#define Irelia "nobridge"
const int maxn = 2e5 + 5;
using namespace std;

struct edge {
    int u, v, ok;
    int other(int x){
        return u ^ v ^ x;
    }
} E[maxn];

int n, m, res;
int low[maxn], num[maxn], id;
int tp[maxn], stp, cnt;
vector<int> g[maxn], f[maxn];
int st[maxn], top;

void dfs(int u, int p){
    low[u] = num[u] = ++id;
    st[++top] = u;
    for (int i : g[u]) if (!E[i].ok){
        E[i].ok = 1;
        int v = E[i].other(u);
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            dfs(v, u);
            minimize(low[u], low[v]);
        }
    }
    if (low[u] >= num[u]){
        stp++;
        while (true){
            int v = st[top--];
            tp[v] = stp;
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
        E[i] = {u, v, 0};
        g[u].pb(i);
        g[v].pb(i);
    }
    fi(i, 1, n) if (!num[i]){
        dfs(i, 0);
    }
    fi(i, 1, m){
        int u = E[i].u;
        int v = E[i].v;
        if (tp[u] == tp[v]) continue;
        f[tp[u]].pb(tp[v]);
        f[tp[v]].pb(tp[u]);
    }
    fi(i, 1, stp){
        sort(f[i].begin(), f[i].end());
        f[i].resize(unique(f[i].begin(), f[i].end()) - f[i].begin());
        cnt += (int(f[i].size()) == 1);
    }
    cout << cnt - cnt / 2;
}
