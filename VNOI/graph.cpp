#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "graph"
const int maxn = 1e4 + 5;
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
edge E[50005];
vector<int> g[maxn];
int low[maxn], num[maxn], id;
int Hinges, Bridges;

void dfs(int u, int p){
    low[u] = num[u] = ++ id;
    int child = (p > 0);
    for (int i : g[u]) if (!E[i].used){
        E[i].used = 1;
        int v = E[i].other(u);
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            dfs(v, u);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) Bridges++;
            if (low[v] >= num[u]) child++;
        }
    }
    if (child >= 2) Hinges++;
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
        g[u].pb(i);
        g[v].pb(i);
        E[i] = {u, v};
    }
    fi(i, 1, n) if (!num[i]){
        dfs(i, 0);
    }
    cout << Hinges << ' ' << Bridges;
}
