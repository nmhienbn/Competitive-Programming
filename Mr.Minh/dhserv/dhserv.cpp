#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "dhserv"
const int maxn = 505;

using namespace std;

int n, m, k;
ll L[maxn][maxn];
bool kt[maxn];
vector<pii> g[maxn];

void Floyd(int x){
    fi(u, 1, n) fi(v, 1, n) L[u][v] = min(L[u][v], L[u][x] + L[x][v]);
    fi(u, 1, n) if (kt[u]) fi(v, 1, n) L[v][x] = min(L[v][x], L[v][u] + L[u][x]);
    fi(u, 1, n) if (kt[u]) fi(v, 1, n) L[x][v] = min(L[x][v], L[x][u] + L[u][v]);
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, n) fi(j, 1, i-1) L[i][j] = L[j][i] = 1e18;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        L[u][v] = w;
    }
    while (k--){
        int typ, x, y;
        cin >> typ >> x;
        if (typ == 1){
            if (kt[x]) continue;
            kt[x] = 1;
            Floyd(x);
        }
        else {
            cin >> y;
            cout << (L[x][y] == 1e18 ? -1 : L[x][y]) << '\n';
        }
    }
}
