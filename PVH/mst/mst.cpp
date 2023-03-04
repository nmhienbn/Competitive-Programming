#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mst"
const int maxn = 5e5 + 5;
using namespace std;

void minimize(int& x, int y){
    if (x > y) x = y;
}

struct dl {
    int u, v, w, id;
    bool used;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
};

int m, n, sub;
bool res[maxn];
dl E[maxn];

int lab[maxn];
int Find(int u){
    return lab[u] < 0 ? u : lab[u] = Find(lab[u]);
}
bool unify(int p, int q){
    p = Find(p);
    q = Find(q);
    if (p == q) return false;
    if (lab[p] > lab[q]) swap(p, q);
    lab[p] += lab[q];
    lab[q] = p;
    return true;
}

bool used[maxn];
int node[maxn], cnt;
vector<pii> g[maxn];

int low[maxn], num[maxn], cntNodes;
void dfs(int u){
    low[u] = num[u] = ++cntNodes;
    for (pii it : g[u]) if (!E[it.second].used){
        E[it.second].used = 1;
        int v = it.first;
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) res[E[it.second].id] = 1;
        }
    }
}

void process(int L, int R){
    fi(i, L, R){
        E[i].u = Find(E[i].u);
        int u = E[i].u;
        E[i].v = Find(E[i].v);
        int v = E[i].v;
        if (!used[u]) node[++cnt] = u, used[u] = 1;
        if (!used[v]) node[++cnt] = v, used[v] = 1;
    }
    fi(i, 1, cnt){
        int u = node[i];
        g[u].clear();
        low[u] = num[u] = 0;
    }
    fi(i, L, R){
        int u = E[i].u;
        int v = E[i].v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    cntNodes = 0;
    fi(i, 1, cnt) if (!num[node[i]]) dfs(node[i]);
    fi(i, 1, cnt){
        used[node[i]] = 0;
    }
    cnt = 0;
    fi(i, L, R) unify(E[i].u, E[i].v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> n >> m;
    fi(i, 1, n) lab[i] = -1;
    fi(i, 1, m){
        cin >> E[i].u >> E[i].v >> E[i].w;
        E[i].id = i;
    }
    sort(E + 1, E + m + 1);
    int j = 1;
    fi(i, 1, m + 1){
        if (E[i].w != E[i - 1].w){
            if (j < i) process(j, i - 1);
            j = i;
        }
    }
    fi(i, 1, m){
        cout << (res[i] ? "Yes " : "No ");
    }
}
