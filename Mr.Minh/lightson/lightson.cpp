#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lightson"
const int maxn = 105, maxm = 2e4 + 5,
        ngg[4] = {-1, 0, 1, 0},
        doc[4] = {0, -1, 0, 1};
using namespace std;

int n, m, pre = -1, now;
bool f[maxn][maxn], cl[maxn][maxn];
vector<pii> g[maxn][maxn];
pii q[maxn * maxn];
int d, c;

void bfs(){
    pre = now;
    fi(i, 1, n) fi(j, 1, n) cl[i][j] = 0;
    d = 1, c = 0;
    q[++c] = {1, 1};
    cl[1][1] = 1;
    while (d <= c){
        int i = q[d].first, j = q[d++].second;
        for (pii vt : g[i][j]){
            int u = vt.first, v = vt.second;
            f[u][v] = 1;
        }
        fi(t, 0, 3){
            int u = i + ngg[t];
            int v = j + doc[t];
            if (f[u][v] && !cl[u][v]){
                cl[u][v] = 1;
                q[++c] = {u, v};
            }
        }
    }
    now = 0;
    fi(i, 1, n) fi(j, 1, n) now += f[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b].pb({c, d});
    }
    f[1][1] = 1;
    while (pre != now){
        bfs();
    }
    cout << now;
}
