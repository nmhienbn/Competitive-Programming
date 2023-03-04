#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "love"
const int maxn = 255;
using namespace std;

int n, m, st, fn, f[maxn][maxn];
vector<int> g[maxn];
queue<pii> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> st >> fn;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    f[st][fn] = 1;
    q.push({st, fn});
    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int u : g[i]) for (int v : g[j]){
            if (!f[u][v]){
                f[u][v] = f[i][j] + 1;
                if (u == v){
                    cout << f[u][v] - 1;
                    exit(0);
                }
                q.push({u, v});
            }
        }
    }
    cout << -1;
}
