#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ants"
const int maxn = 1e5 + 5;
using namespace std;

int n, q, b[maxn][20], h[maxn];
ll d[maxn];

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    fid(i, 17, 0) if (gb(del, i)){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 17, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

ll dis(int u, int v){
    return d[u] + d[v] - d[LCA(u, v)] * 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> n){
        if (n == 0) break;
        fi(i, 2, n){
            int p, w;
            cin >> p >> w;
            p++;
            d[i] = d[p] + w;
            h[i] = h[p] + 1;
            b[i][0] = p;
            fi(j, 1, 17) b[i][j] = b[b[i][j - 1]][j - 1];
        }
        cin >> q;
        fi(i, 1, q){
            int u, v;
            cin >> u >> v;
            u++, v++;
            cout << dis(u, v) << ' ';
        }
        cout << '\n';
    }

}
