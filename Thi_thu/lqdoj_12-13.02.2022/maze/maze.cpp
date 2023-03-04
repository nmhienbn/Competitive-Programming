#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "maze"
const int maxn = 1005, maxm = 1e5 + 5, N = 1e6 + 5;
const int ngg[4] = {-1, 0, 0, 1},
          doc[4] = {0, -1, 1, 0};
using namespace std;
struct dl {
    int typ, u, v, x, y, res;
};

int n, q;
bool a[maxn][maxn], kt[maxn][maxn];
int vt[maxn][maxn], pos;
dl b[maxm];

int lab[N];
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

void nhap(){
    cin >> n >> q;
    fi(i, 1, n) fi(j, 1, n){
        char c;
        cin >> c;
        a[i][j] = (c == '1');
        vt[i][j] = ++pos;
    }
    fi(i, 1, pos) lab[i] = -1;
    fi(i, 1, q){
        int typ;
        cin >> typ;
        if (typ == 1){
            int u, v;
            cin >> u >> v;
            b[i] = {typ, u, v, 0, 0};
            a[u][v] = 1;
        }
        else {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            b[i] = {typ, u, v, x, y};
        }
    }
}
void DSU(){
    fi(i, 1, n) fi(j, 1, n){
        fi(k, 0, 3){
            int u = i + ngg[k];
            int v = j + doc[k];
            if (vt[u][v] && !a[i][j] && !a[u][v]){
                unify(vt[i][j], vt[u][v]);
            }
        }
    }
    fid(rep, q, 1){
        if (b[rep].typ == 1){
            int i = b[rep].u;
            int j = b[rep].v;
            a[i][j] = 0;
            fi(k, 0, 3){
                int u = i + ngg[k];
                int v = j + doc[k];
                if (vt[u][v] && !a[u][v]){
                    unify(vt[i][j], vt[u][v]);
                }
            }
        }
        else {
            int i = b[rep].u;
            int j = b[rep].v;
            int u = b[rep].x;
            int v = b[rep].y;
            if (Find(vt[i][j]) != Find(vt[u][v])) b[rep].res = -1;
        }
    }
}

queue<pii> Q;
int par[N][21], h[N];
void BFS(){
    fi(i, 1, n){
        fi(j, 1, n){
            if (!a[i][j]){
                Q.push({i, j});
                break;
            }
        }
        if (Q.size()) break;
    }
    while (Q.size()){
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        fi(k, 0, 3){
            int u = i + ngg[k];
            int v = j + doc[k];
            if (vt[u][v] && !a[u][v] && !kt[u][v]){
                kt[u][v] = 1;
                par[vt[u][v]][0] = vt[i][j];
                h[vt[u][v]] = h[vt[i][j]] + 1;
                fi(t, 1, 20){
                    par[vt[u][v]][t] = par[par[vt[u][v]][t - 1]][t - 1];
                }
                Q.push({u, v});
            }
        }
    }
}

int dis(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    int res = d;
    fid(i, 20, 0) if (gb(d, i)){
        u = par[u][i];
    }
    if (u == v) return res;
    fid(i, 20, 0) if (par[u][i] != par[v][i]){
        res += (1 << (i + 1));
        u = par[u][i];
        v = par[v][i];
    }
    return res + 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    nhap();
    DSU();
    BFS();
    fi(rep, 1, q){
        if (b[rep].typ == 2){
            if (b[rep].res == -1){
                cout << "-1\n";
                continue;
            }
            int i = b[rep].u;
            int j = b[rep].v;
            int u = b[rep].x;
            int v = b[rep].y;
            cout << dis(vt[i][j], vt[u][v]) + 1 << '\n';
        }
    }
}
