#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pli pair <ll, int>
#define X first
#define Y second
#define pb push_back
#define Irelia "balloon"
const int maxn = 205;
using namespace std;

int n, st, fn;
int sz[maxn];
pii a[maxn][maxn];
ll L[maxn][maxn], f[maxn];

priority_queue<pli, vector<pli>, greater<pli>> q;

void operator -= (pii& a, pii b){
    a.X -= b.X;
    a.Y -= b.Y;
}

pii operator - (pii a, pii b){
    return {a.X - b.X, a.Y - b.Y};
}

ll dis(pii a, pii b){
    a -= b;
    return (ll) (sqrt(1ll * a.X * a.X + 1ll * a.Y * a.Y) * 1000000);
}

double dis2(pii a, pii b){
    a -= b;
    return sqrt(1ll * a.X * a.X + 1ll * a.Y * a.Y);
}

ll Prod(pii a, pii b){
    return 1ll * a.X * b.X + 1ll * a.Y * b.Y;
}

ll dis(pii a, pii b, pii c){
    b -= a;
    c -= a;
    //cout << a.X << ' ' << a.Y << ' ' << b.X << ' ' << b.Y << ' ' << c.X << ' ' << c.Y << ' ' << dis2(b, c) << '\n';
    if (Prod(b, b - c) < 0) return 1e18;
    if (Prod(c, c - b) < 0) return 1e18;
    return (ll) (double(abs(1ll * b.X * c.Y - 1ll * c.X * b.Y)) / dis2(b, c) * 1000000);
}

void sub1(){
    fi(i, 1, n){
        fi(j, 1, i - 1){
            L[i][j] = 1e18;
            fi(u, 1, sz[i]){
                fi(v, 1, sz[j]){
                    L[i][j] = min(L[i][j], dis(a[i][u], a[j][v]));
                    L[i][j] = min(L[i][j], dis(a[i][u], a[j][v], a[j][v + 1]));
                }
            }
            L[j][i] = L[i][j];
        }
    }
    fi(i, 1, n) f[i] = 1e18;
    f[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        if (f[u] < q.top().first){
            q.pop();
            continue;
        }
        if (u == fn) break;
        q.pop();
        fi(v, 1, n){
            if (f[u] + L[u][v] < f[v]){
                f[v] = f[u] + L[u][v];
                q.push({f[v], v});
            }
        }
    }
    cout << f[fn];
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> st >> fn;
    fi(i, 1, n){
        cin >> sz[i];
        fi(j, 1, sz[i]){
            cin >> a[i][j].X >> a[i][j].Y;
        }
        a[i][sz[i] + 1] = a[i][1];
    }
    sub1();
}
