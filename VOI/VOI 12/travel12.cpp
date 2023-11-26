#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "travel12"
const int maxn = 10005;
using namespace std;

int n, m;
bitset<maxn> a[maxn];
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        if (!a[u].test(v)){
            a[u].set(v);
            a[v].set(u);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    fi(u, 1, n){
        bitset<maxn> f;
        for (int v : g[u]){
            a[v][u] = 0;
            if ((f & a[v]).any()){
                f &= a[v];
                int w = 1;
                while (!f[w]) w++;
                for (int x : g[w]) if (a[u][x] && x != v){
                    cout << u << ' ' << x << ' ' << w << ' ' << v;
                    exit(0);
                }
            }
            else {
                f |= a[v];
            }
            a[v][u] = 1;
        }
    }
    cout << -1;
}
