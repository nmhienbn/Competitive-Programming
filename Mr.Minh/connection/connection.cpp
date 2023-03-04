#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define X first
#define Y second
#define pii pair <int, int>
#define pb push_back
#define Irelia "connection"
const int maxn = 1005, maxm = 1e6 + 5,
        ngg[4] = {0, 0, -1, 1},
        doc[4] = {-1, 1, 0, 0};

using namespace std;

struct edge{
    char typ;
    int i, j;
} E[maxm];

int n, m, k, res;
int f[maxn][maxn];

int root[maxm];
int get(int u){
    return root[u] == 0 ? u : root[u] = get(root[u]);
}

bool unify(int u, int v){
    int p = get(u);
    int q = get(v);
    if (p == q) return false;
    if (p > q) root[p] = q;
    else root[q] = p;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) fi(j, 1, n) f[i][j] = (i - 1) * n + j;
    fi(i, 1, k){
        char typ;
        int u, v;
        cin >> typ >> u >> v;
        if (typ == 'R'){
            unify(f[u][v], f[u][v + 1]);
        }
        else {
            unify(f[u][v], f[u + 1][v]);
        }
    }
    fi(i, 1, m) fi(j, 1, n){
        fi(t, 0, 3){
            int u = i + ngg[t];
            int v = j + doc[t];
            if (1 <= u && u <= m && 1 <= v && v <= n){
                if (unify(f[i][j], f[u][v])){
                    res++;
                    if (t == 0) E[res] = {'R', u, v};
                    else if (t == 1) E[res] = {'R', i, j};
                    else if (t == 2) E[res] = {'D', u, v};
                    else E[res] = {'D', i, j};
                }
            }
        }
    }
    cout << res << '\n';
    fi(i, 1, res){
        cout << E[i].typ << ' ' << E[i].i << ' ' << E[i].j << '\n';
    }
}
