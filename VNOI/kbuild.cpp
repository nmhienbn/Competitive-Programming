#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kbuild"
const int maxn = 2e5 + 5;
using namespace std;

struct edge {
    int u, v;
    bool used;
    int other(int& x){
        return u ^ v ^ x;
    }
};

void minimize(int& x, int& y){
    if (x > y) x = y;
}

int n, m;
edge E[maxn << 1];
vector<int> g[maxn];
int low[maxn], num[maxn], id;
int Bridges;

void dfs(int u){
    low[u] = num[u] = ++ id;
    for (int i : g[u]) if (!E[i].used){
        E[i].used = 1;
        int v = E[i].other(u);
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) Bridges++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(i);
        g[v].pb(i);
        E[i] = {u, v};
    }
    cin >> m;
    m += n - 1;
    fi(i, n, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(i);
        g[v].pb(i);
        E[i] = {u, v};
    }
    dfs(1);
    cout << Bridges;
}
