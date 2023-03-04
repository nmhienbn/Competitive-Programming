#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lcp"
const int maxn = 10005, maxm = 4e6 + 5, maxk = 5005;
using namespace std;

int n, k, cnt;
int sz[maxn];
ll f[maxn][maxk], tmp[maxk];
string s;
vector<pii> g[maxn];

int id[maxm], numID;
int getID(int x){
    if (id[x] == 0){
        id[x] = ++numID;
    }
    return id[x];
}

struct node {
    int child[26];
    int deg;
    int depth;
} T[maxm];
void add(string s){
    int x = 0;
    for (char c : s){
        int now = c - 'a';
        if (!T[x].child[now]) T[x].child[now] = ++cnt;
        x = T[x].child[now];
    }
    T[x].deg++;
}
void dfsT(int u, int p, int depth){
    T[u].depth = depth;
    int child = 0;
    fi(i, 0, 25)
        child += (T[u].child[i] > 0);
    if (T[u].deg || child > 1){
        if (u != p){
            g[getID(p)].pb({getID(u), depth - T[p].depth});
        }
        p = u;
    }
    if (T[u].deg) sz[getID(u)] = T[u].deg;
    fi(i, 0, 25) if (T[u].child[i]){
        dfsT(T[u].child[i], p, depth + 1);
    }
}

void dfs(int u){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        dfs(v);
        fi(i, 0, sz[u]) fi(j, 0, sz[v]){
            tmp[i + j] = max(tmp[i + j], f[u][i] + f[v][j] + 1LL * j * (j - 1) / 2 * w);
        }
        sz[u] += sz[v];
        fi(i, 0, sz[u]){
            f[u][i] = tmp[i];
            tmp[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cout << sizeof(T) << '\n';
    cin >> n >> k;
    fi(i, 1, n){
        cin >> s;
        add(s);
    }
    dfsT(0, 0, 0);
    dfs(1);
    cout << f[1][k];
}
