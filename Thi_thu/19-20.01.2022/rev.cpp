#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "rev"
const int maxn = 2005;
using namespace std;

int n, m, a[maxn][maxn];
pii b[maxn][maxn];
vector<int> g[maxn * 2];
int f[maxn];

void dfs(int u, int p){
    for (int v : g[u]){
        if (v == p) continue;
        int uu = u > m ? u - m : u;
        int vv = v > m ? v - m : v;
        if (f[vv] == -1){
            f[vv] = (f[uu] ^ ((u > m) == (v <= m)));
            dfs(v, u);
        }
        else {
            if (f[vv] != (f[uu] ^ ((u > m) == (v <= m)))){
                cout << -1;
                exit(0);
            }
        }
    }
}

void ngc(int i, int j){
    if (i == j) return;
    g[i].pb(j + m);
    g[j + m].pb(i);
    g[j].pb(i + m);
    g[i + m].pb(j);
}

void xuoi(int i, int j){
    if (i == j) return;
    g[i].pb(j);
    g[j].pb(i);
}

void sub1(){
    memset(f, -1, sizeof f);
    fi(i, 1, m) fi(j, 1, i - 1){
        fi(k, 1, n) if (a[i][k] == a[j][k]){
            ngc(i, j);
            break;
        }
    }
    fi(i, 1, m) fi(j, 1, i - 1){
        fi(k, 1, n) if (a[i][k] == a[j][n + 1 - k]){
            xuoi(i, j);
            break;
        }
    }
    fi(i, 1, m) if (f[i] == -1){
        f[i] = 0;
        dfs(i, 0);
    }
    int cnt = 0;
    fi(i, 1, m) cnt += f[i];
    cout << cnt << '\n';
    fi(i, 1, m) if (f[i]) cout << i << ' ';
    exit(0);
}

void sub2(){
    memset(f, -1, sizeof f);
    fi(i, 1, n) fi(j, 1, m){
        b[i][j] = {a[j][i], j};
    }
    fi(i, 1, n) sort(b[i] + 1, b[i] + m + 1);
    if (n & 1){
        int i = n / 2 + 1;
        fi(j, 2, m){
            if (b[i][j].first == b[i][j - 1].first){
                cout << -1;
                exit(0);
            }
        }
    }
    fi(i, 1, n){
        fi(j, 2, m){
            if (b[i][j].first == b[i][j - 1].first){
                ngc(b[i][j].second, b[i][j - 1].second);
            }
        }
    }
    fi(i, 1, n / 2){
        int j = 1, k = 1;
        while (j <= m && k <= m){
            if (b[i][j] > b[n + 1 - i][k]) k++;
            if (b[i][j] < b[n + 1 - i][k]) j++;
            if (b[i][j] == b[n + 1 -i][k]){
                fi(t, j, m) if (b[i][t] == b[n + 1 -i][k]){
                    xuoi(b[i][t].second, b[n + 1 - i][k].second);
                }
                else break;
            }
        }
    }
    fi(i, 1, m) if (f[i] == -1){
        f[i] = 0;
        dfs(i, 0);
    }
    int cnt = 0;
    fi(i, 1, m) cnt += f[i];
    cout << cnt << '\n';
    fi(i, 1, m) if (f[i]) cout << i << ' ';
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
    }
    if (m <= 200) sub1();
    sub2();
}
