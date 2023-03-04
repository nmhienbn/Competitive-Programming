#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "project2"
const int maxn = 1e5 + 5;
const ll INF = 1e18;
using namespace std;

int n, m, f[maxn], a[maxn];
int nex[1050];
ll g[maxn][1050], res = 0;

void maximize(ll& x, ll y){
    if (x < y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        f[v] |= (1 << (v - u - 1));
    }
    fi(i, 0, 1023) nex[i] = (i & 511) << 1;
    fi(i, 1, n) fi(j, 1, 1023) g[i][j] = -INF;
    g[1][1] = a[1];
    fi(i, 1, n - 1){
        fi(j, 0, 1023) if (g[i][j] > -INF){
            maximize(g[i + 1][nex[j]], g[i][j]);
            if ((j & f[i + 1]) == f[i + 1]){
                maximize(g[i + 1][nex[j] | 1], g[i][j] + a[i + 1]);
            }
        }
    }
    fi(i, 0, 1023){
        maximize(res, g[n][i]);
    }
    cout << res;
}
