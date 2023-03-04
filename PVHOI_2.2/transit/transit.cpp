#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define minimize(x, y) x = (x > y) ? y : x;
#define ll long long
#define Irelia "transit"
const int maxn = 1505;
const int maxm = 20;
const int INF = 1e9;
using namespace std;

int n, m, Q;
int vt[maxm];
int a[maxn][maxn], f[maxm][maxn], h[maxm][maxn];
bool cl[maxn];
int g[maxm][1 << 17][maxm];
vector<int> bit[1 << 17][2];
priority_queue<pii, vector<pii>, greater<pii>> q;

void Dijkstra(int st, int f[]){
    fi(i, 1, n) cl[i] = 0;
    fi(i, 0, n) f[i] = 1e9;
    f[st] = 0;
    fi(rep, 1, n){
        int u = 0;
        fi(i, 1, n){
            if (f[i] < f[u] && !cl[i]){
                u = i;
            }
        }
        cl[u] = 1;
        fi(v, 1, n){
            minimize(f[v], f[u] + a[u][v]);
        }
    }
}

void nhap(){
    cin >> n >> m >> Q;
    fi(i, 1, m) cin >> vt[i];
    fi(i, 1, n) fi(j, 1, n){
        cin >> a[i][j];
    }
    fi(i, 1, m){
        Dijkstra(vt[i], f[i]);
    }
    fi(i, 1, n) fi(j, 1, i - 1){
        swap(a[i][j], a[j][i]);
    }
    fi(i, 1, m){
        Dijkstra(vt[i], h[i]);
    }
}

void bitmask(){
    int u = (1 << m) - 1;
    fi(x, 1, u){
        fi(t, 1, m){
            if (gb(x, t - 1)) bit[x][1].pb(t);
            else bit[x][0].pb(t);
        }
    }
    fi(i, 1, m) fi(j, 1, m) fi(t, 0, u) g[i][t][j] = INF;
    fi(i, 0, m - 1) g[i + 1][1 << i][i + 1] = 0;
    fi(x, 1, u){
        for (int t : bit[x][1]) for (int i : bit[x][1]) for (int j : bit[x][0]){
            minimize(g[t][x | (1 << (j - 1))][j], g[t][x][i] + f[i][vt[j]]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    nhap();
    bitmask();
    int u = (1 << m) - 1;
    fi(rep, 1, Q){
        int st, fn;
        cin >> st >> fn;
        int res = INF;
        fi(i, 1, m) fi(j, 1, m) if (g[i][u][j] != INF){
            minimize(res, h[i][st] + g[i][u][j] + f[j][fn]);
        }
        cout << res << ' ';
    }
}
